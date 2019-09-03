///////////////////////////////////////////////////////////////////////////////
// NAME:            currentPath.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Test file exposing the currentPath function
//
// CREATED:         09/03/2019
//
// LAST EDITED:     09/03/2019
////

#define USAGE \
  "currentPath\n"\
  "\n"\
  "Print the current working directory."

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
  std::cout << fsadaptor.currentPath().string() << std::endl;
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
