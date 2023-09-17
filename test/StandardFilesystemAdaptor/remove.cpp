///////////////////////////////////////////////////////////////////////////////
// NAME:            remove.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Test file exposing the remove function
//
// CREATED:         09/03/2019
//
// LAST EDITED:     09/03/2019
////

#define USAGE \
  "remove <path>\n"\
  "\n"\
  "Remove the file corresponding to <path>"

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
  fsadaptor.remove(p);
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
