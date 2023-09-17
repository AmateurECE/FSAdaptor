///////////////////////////////////////////////////////////////////////////////
// NAME:            isDirectory.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Test file exposing the isDirectory function
//
// CREATED:         09/03/2019
//
// LAST EDITED:     09/03/2019
////

#define USAGE \
  "isDirectory <path>\n"\
  "\n"\
  "Determine if <path> refers to an existing directory on the filesystem."

#include <fsadaptor/Path.h>
#include <fsadaptor/StandardFilesystemAdaptor.h>

#include <iostream>

int main(int argc, char** argv)
{
  if (argc != 2)
    {
      std::cerr << USAGE << std::endl;
      return 1;
    }

  FSAdaptor::Path p{argv[1]};
  FSAdaptor::StandardFilesystemAdaptor fsadaptor;
  return fsadaptor.isDirectory(p);
}

///////////////////////////////////////////////////////////////////////////////
