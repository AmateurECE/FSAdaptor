///////////////////////////////////////////////////////////////////////////////
// NAME:            DiscoveredDefects.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     These tests were developed as a result of defects that were
//                  discovered in production.
//
// CREATED:         09/08/2019
//
// LAST EDITED:     09/08/2019
////

#include "gtest/gtest.h"

#include <fsadaptor/Path.h>

class DiscoveredDefects : public ::testing::Test
{};

// Apparently this is what std::filesystem::path does.
TEST_F(DiscoveredDefects, EmptyStringForDir)
{
  static const std::string pathName = "/Users/ethantwardy/Downloads/NewMusic/";
  ASSERT_EQ(FSAdaptor::Path{pathName}.filename().string(), "");
}

///////////////////////////////////////////////////////////////////////////////
