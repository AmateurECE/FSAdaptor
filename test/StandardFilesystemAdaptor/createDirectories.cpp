///////////////////////////////////////////////////////////////////////////////
// NAME:            createDirectories.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Test file exposing the createDirectories function
//
// CREATED:         09/03/2019
//
// LAST EDITED:     09/03/2019
////

#define USAGE \
  "createDirectories <path>\n"\
  "\n"\
  "Create the directory at <path>, and any intermediate directories that do\n"\
  "not already exist."

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
  fsadaptor.createDirectories(p);
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
