///////////////////////////////////////////////////////////////////////////////
// NAME:            TestMain.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Main function for testing SortMedia classes and modules.
//
// CREATED:         08/18/2019
//
// LAST EDITED:     09/05/2019
////

// TODO: Update and refactor unit tests
// The goal here is to have a single test fixture for each behavior of the Path
// interface, and each test fixture is responsible only for testing a single
// behavior.

#include <gtest/gtest.h>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

///////////////////////////////////////////////////////////////////////////////
