///////////////////////////////////////////////////////////////////////////////
// NAME:            ConcatenatingTest.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Tests that paths are concatenated correctly.
//
// CREATED:         09/08/2019
//
// LAST EDITED:     09/08/2019
////

#include "gtest/gtest.h"

#include <fsadaptor/Path.h>

class ConcatenatingTest : public ::testing::Test
{};

TEST_F(ConcatenatingTest, Persistence)
{
  FSAdaptor::Path top{"./TopLevel"};
  FSAdaptor::Path bottom{"BottomLevelPath.txt"};

  FSAdaptor::Path total = top / bottom;
  EXPECT_EQ(total.string(), "TopLevel/BottomLevelPath.txt");
  EXPECT_EQ(total.filename().string(), "BottomLevelPath.txt");
  EXPECT_EQ(total.extension().string(), ".txt");
  EXPECT_EQ(total.parent_path().string(), "TopLevel");
}

TEST_F(ConcatenatingTest, ExtraSlash)
{
  FSAdaptor::Path top{"./TopLevel/"};
  FSAdaptor::Path bottom{"BottomLevelPath.txt"};

  FSAdaptor::Path total = top / bottom;
  EXPECT_EQ(total.string(), "TopLevel/BottomLevelPath.txt");
  EXPECT_EQ(total.filename().string(), "BottomLevelPath.txt");
  EXPECT_EQ(total.extension().string(), ".txt");
  EXPECT_EQ(total.parent_path().string(), "TopLevel");
}

///////////////////////////////////////////////////////////////////////////////
