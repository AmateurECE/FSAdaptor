///////////////////////////////////////////////////////////////////////////////
// NAME:            equivalent.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Test file exposing the equivalent function
//
// CREATED:         09/03/2019
//
// LAST EDITED:     09/03/2019
////

#define USAGE \
  "equivalent <path1> <path2>\n"\
  "\n"\
  "Determine if <path1> is equivalent to <path2>"

#include <fsadaptor/Path.h>
#include <fsadaptor/StandardFilesystemAdaptor.h>

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
  return fsadaptor.equivalent(p1, p2);
}

///////////////////////////////////////////////////////////////////////////////
