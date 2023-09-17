///////////////////////////////////////////////////////////////////////////////
// NAME:            absolute.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Test file exposing the absolute function
//
// CREATED:         09/03/2019
//
// LAST EDITED:     09/03/2019
////

#define USAGE \
  "absolute <path>\n"\
  "\n"\
  "If <path> is not an absolute path, attempt to locate its absolute path\n"\
  "and print it."

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
  FSAdaptor::Path absolutePath = fsadaptor.absolute(p);
  std::cout << absolutePath.string() << std::endl;
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
