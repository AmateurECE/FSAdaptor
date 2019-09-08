///////////////////////////////////////////////////////////////////////////////
// NAME:            IteratorTest.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Tests for iterators.
//
// CREATED:         09/08/2019
//
// LAST EDITED:     09/08/2019
////

#include "gtest/gtest.h"

#include <FSAdaptor/Path.h>

#include <string>

class IteratorTest : public ::testing::Test
{};

TEST_F(IteratorTest, AbsTrailingSlash)
{
  static const std::string pathName = "/Users/EthanTwardy/Desktop/";
  static const std::vector<std::string> components
    = {"/", "Users", "EthanTwardy", "Desktop", ""};
  FSAdaptor::Path p{pathName};
  auto pathIt = p.cbegin();
  auto compIt = components.cbegin();
  int numElements = 0;
  while (pathIt != p.cend() && compIt != components.cend())
    {
      EXPECT_EQ((*pathIt).string(), *compIt);
      numElements++;
      pathIt++;
      compIt++;
    }

  EXPECT_TRUE(pathIt == p.cend());
  EXPECT_TRUE(compIt == components.cend());
  EXPECT_EQ(numElements, 5);
}

///////////////////////////////////////////////////////////////////////////////
