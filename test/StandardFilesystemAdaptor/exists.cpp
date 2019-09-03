///////////////////////////////////////////////////////////////////////////////
// NAME:            exists.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Test file exposing the exists function
//
// CREATED:         09/03/2019
//
// LAST EDITED:     09/03/2019
////

#define USAGE \
  "exists <path>\n"\
  "\n"\
  "Determine if <path> refers to an existing file on the filesystem."

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
  fsadaptor.exists(p);
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
