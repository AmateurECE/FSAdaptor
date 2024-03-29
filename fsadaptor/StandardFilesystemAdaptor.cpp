///////////////////////////////////////////////////////////////////////////////
// NAME:            StandardFilesystemAdaptor.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Implementation of the Standard Filesystem Adaptor.
//
// CREATED:         08/29/2019
//
// LAST EDITED:     09/20/2022
////

// TODO: Switch to using std::filesystem::path
// TODO: Add support for non-english locales

// SortMedia headers
#include <fsadaptor/StandardFilesystemAdaptor.h>
#include <fsadaptor/Path.h>
#include <fsadaptor/IPathWalker.h>
#include <fsadaptor/PathWalker.h>

// LibC++ headers
#include <list>
#include <stdexcept>
#include <system_error>
#include <cstring>

// LibC headers
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

static std::system_error makeSystemError(int error)
{
  return std::system_error{std::make_error_code
      (static_cast<std::errc>(error))};
}

static std::system_error makeSystemError(int error, const std::string& message)
{
  return std::system_error{std::make_error_code(static_cast<std::errc>(error)),
      message.c_str()};
}

void
FSAdaptor::StandardFilesystemAdaptor
::walk(FSAdaptor::IPathWalker& walker, const FSAdaptor::Path& directory) const
{
  if (!exists(directory))
    {
      throw std::invalid_argument{"path does not exist"};
    }

  walker.insert(directory);
  if (isDirectory(directory))
    {
      PathWalker<std::list> thisDirectory;
      listDirectory(thisDirectory, directory);
      for (auto path : thisDirectory.getContainer())
        {
          if (path.string() != directory.string())
            {
              walk(walker, path);
            }
        }
    }
}

void
FSAdaptor::StandardFilesystemAdaptor
::listDirectory(FSAdaptor::IPathWalker& walker,
                const FSAdaptor::Path& directory) const
{
  DIR* directoryStream = NULL;
  struct dirent* result = NULL;
  struct dirent entry;
  memset(&entry, 0, sizeof(struct dirent));

  errno = 0;
  if (NULL == (directoryStream = opendir(directory.string().c_str())))
    {
      throw makeSystemError(errno);
    }

  errno = 0;
  int readdirError = 0;
  while (!(readdirError = readdir_r(directoryStream, &entry, &result))
         && NULL != result)
    {
      if (strncmp(entry.d_name, ".", sizeof("."))
          && strncmp(entry.d_name, "..", sizeof("..")))
        {
          walker.insert(directory/Path{entry.d_name});
        }
    }

  closedir(directoryStream);
  if (readdirError)
    {
      throw makeSystemError(errno);
    }
}

bool
FSAdaptor::StandardFilesystemAdaptor
::isEmpty(const FSAdaptor::Path& p) const
{
  struct stat path;
  memset(&path, 0, sizeof(path));

  errno = 0;
  if (stat(p.string().c_str(), &path))
    {
      throw makeSystemError(errno);
    }

  return 0 == path.st_size;
}

bool
FSAdaptor::StandardFilesystemAdaptor
::isDirectory(const FSAdaptor::Path& p) const
{
  struct stat path;
  memset(&path, 0, sizeof(path));
  errno = 0;
  if (stat(p.string().c_str(), &path))
    {
      throw makeSystemError(errno, "(during stat() on path "
                            + p.string() + ")");
    }

  return S_ISDIR(path.st_mode);
}

bool
FSAdaptor::StandardFilesystemAdaptor
::exists(const FSAdaptor::Path& p) const
{
  return access(p.string().c_str(), F_OK) != -1;
}

void
FSAdaptor::StandardFilesystemAdaptor
::createDirectory(const FSAdaptor::Path& p) const
{
  errno = 0;
  if (mkdir(p.string().c_str(), 0777))
    {
      throw makeSystemError(errno);
    }
}

void
FSAdaptor::StandardFilesystemAdaptor
::createDirectories(const FSAdaptor::Path& p) const
{
  Path stack;
  for (auto it = p.cbegin(); it != p.cend(); ++it)
    {
      stack /= *it;
      if (!exists(stack))
        {
          createDirectory(stack);
        }
    }
}

bool
FSAdaptor::StandardFilesystemAdaptor
::equivalent(const FSAdaptor::Path& p1, const FSAdaptor::Path& p2) const
{
  struct stat s1, s2;
  memset(&s1, 0, sizeof(s1));
  memset(&s2, 0, sizeof(s2));

  errno = 0;
  if (stat(p1.string().c_str(), &s1)
      || stat(p2.string().c_str(), &s2))
    {
      throw makeSystemError(errno);
    }

  return s1.st_dev == s2.st_dev && s1.st_ino == s2.st_ino;
}

void
FSAdaptor::StandardFilesystemAdaptor
::remove(const FSAdaptor::Path& p) const
{
  errno = 0;
  if (::remove(p.string().c_str()))
    {
      throw makeSystemError(errno);
    }
}

FSAdaptor::Path
FSAdaptor::StandardFilesystemAdaptor
::absolute(const FSAdaptor::Path& p) const
{
  char absolutePath[PATH_MAX + 1];
  if (exists(p))
    {
      return Path{realpath(p.string().c_str(), absolutePath)};
    }

  throw std::invalid_argument{"path does not exist"};
}

FSAdaptor::Path
FSAdaptor::StandardFilesystemAdaptor
::currentPath() const
{
  char cwd[PATH_MAX + 1];
  return Path{getcwd(cwd, PATH_MAX)};
}

void
FSAdaptor::StandardFilesystemAdaptor
::rename(const FSAdaptor::Path& oldPath, const FSAdaptor::Path& newPath) const
{
  errno = 0;
  if (::rename(oldPath.string().c_str(), newPath.string().c_str()))
    {
      throw makeSystemError(errno);
    }
}

///////////////////////////////////////////////////////////////////////////////
