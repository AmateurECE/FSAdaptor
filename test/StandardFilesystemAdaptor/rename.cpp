///////////////////////////////////////////////////////////////////////////////
// NAME:            rename.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Test file exposing the rename function
//
// CREATED:         09/03/2019
//
// LAST EDITED:     09/03/2019
////

#define USAGE \
  "rename <oldPath> <newPath>\n"\
  "\n"\
  "If <oldPath> refers to an existing file on the filesystem, change the\n"\
  "path of that file to <newPath>"

#include <FSAdaptor/Path.h>
#include <FSAdaptor/StandardFilesystemAdaptor.h>

#include <iostream>

int main(int argc, char** argv)
{
  if (argc != 3)
    {
      std::cerr << USAGE << std::endl;
      return 1;
    }

  FSAdaptor::Path p1{argv[1]};
  FSAdaptor::Path p2{argv[2]};
  FSAdaptor::StandardFilesystemAdaptor fsadaptor;
  fsadaptor.rename(p1, p2);
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
