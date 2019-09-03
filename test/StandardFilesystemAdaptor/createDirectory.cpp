///////////////////////////////////////////////////////////////////////////////
// NAME:            createDirectory.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Test file exposing the createDirectory function
//
// CREATED:         09/03/2019
//
// LAST EDITED:     09/03/2019
////

#define USAGE \
  "createDirectory <path>\n"\
  "\n"\
  "Create the directory at <path>. All intermediate directories must exist."

#include <FSAdaptor/Path.h>
#include <FSAdaptor/StandardFilesystemAdaptor.h>

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
  fsadaptor.createDirectory(p);
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
