///////////////////////////////////////////////////////////////////////////////
// NAME:            OperatorTests.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Tests for some of the operators.
//
// CREATED:         09/08/2019
//
// LAST EDITED:     09/08/2019
////

#include "gtest/gtest.h"

#include <fsadaptor/Path.h>

#include <string>

class OperatorTests : public ::testing::Test
{};

TEST_F(OperatorTests, PlusEqualsOne)
{
  FSAdaptor::Path pOne{"/a/"};
  FSAdaptor::Path pTwo{"dir"};
  pOne += pTwo;
  ASSERT_EQ(pOne.string(), "/a/dir");
}

TEST_F(OperatorTests, PlusEqualsTwo)
{
  FSAdaptor::Path pOne{"/a"};
  FSAdaptor::Path pTwo{"dir"};
  pOne += pTwo;
  ASSERT_EQ(pOne.string(), "/adir");
}

TEST_F(OperatorTests, DivEqualsOne)
{
  FSAdaptor::Path pOne{"/a/"};
  FSAdaptor::Path pTwo{"dir"};
  pOne /= pTwo;
  ASSERT_EQ(pOne.string(), "/a/dir");
}

TEST_F(OperatorTests, DivEqualsTwo)
{
  FSAdaptor::Path pOne{"/a"};
  FSAdaptor::Path pTwo{"dir"};
  pOne /= pTwo;
  ASSERT_EQ(pOne.string(), "/a/dir");
}

TEST_F(OperatorTests, IsEqual)
{
  FSAdaptor::Path pOne{"a"};
  FSAdaptor::Path pTwo{"a"};
  ASSERT_TRUE(pOne == pTwo);
}

TEST_F(OperatorTests, IsNotEqual)
{
  FSAdaptor::Path pOne{"a"};
  FSAdaptor::Path pTwo{"b"};
  ASSERT_TRUE(pOne != pTwo);
}

///////////////////////////////////////////////////////////////////////////////
