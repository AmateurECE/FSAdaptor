///////////////////////////////////////////////////////////////////////////////
// NAME:            walk.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Test file exposing the walk function
//
// CREATED:         09/03/2019
//
// LAST EDITED:     09/04/2019
////

#define USAGE \
  "walk <path>\n"\
  "\n"\
  "If <path> refers to an existing directory on the filesystem, traverse it\n"\
  "in a top-down fashion, visiting all files and sub-directories\n"\
  "recursively, then printing a list of the files discovered."

#include <FSAdaptor/Path.h>
#include <FSAdaptor/PathWalker.h>
#include <FSAdaptor/StandardFilesystemAdaptor.h>

#include <iostream>
#include <list>

int main(int argc, char** argv)
{
  if (argc != 2)
    {
      std::cerr << USAGE << std::endl;
      return 1;
    }

  FSAdaptor::Path p{argv[1]};
  FSAdaptor::PathWalker<std::list> walker;
  FSAdaptor::StandardFilesystemAdaptor fsadaptor;

  fsadaptor.walk(walker, p);

  std::list<FSAdaptor::Path>& pathList = walker.getContainer();
  for_each(pathList.begin(), pathList.end(), [](FSAdaptor::Path& e){
      std::cout << e.string() << std::endl;
    });

  return 0;
}

///////////////////////////////////////////////////////////////////////////////
