///////////////////////////////////////////////////////////////////////////////
// NAME:            ParsingTest.cpp
//
// AUTHOR:          Ethan D. Twardy <edtwardy@mtu.edu>
//
// DESCRIPTION:     Tests that verify the Path class parses constructor arg.
//
// CREATED:         09/08/2019
//
// LAST EDITED:     09/08/2019
////

#include "gtest/gtest.h"

#include <FSAdaptor/Path.h>

#include <string>

class ParsingTest : public ::testing::Test
{};

TEST_F(ParsingTest, EmptyPath)
{
  static const std::string pathName = "";
  ASSERT_EQ(FSAdaptor::Path{pathName}.string(), pathName);
}

TEST_F(ParsingTest, AbsRegular)
{
  static const std::string pathName = "/this/is/a/path.test";
  ASSERT_EQ(FSAdaptor::Path{pathName}.string(), pathName);
}

TEST_F(ParsingTest, AbsHidden)
{
  static const std::string pathName = "/this/is/a/.test";
  ASSERT_EQ(FSAdaptor::Path{pathName}.string(), pathName);
}

TEST_F(ParsingTest, AbsNoExt)
{
  static const std::string pathName = "/this/is/a/test";
  ASSERT_EQ(FSAdaptor::Path{pathName}.string(), pathName);
}

TEST_F(ParsingTest, RelCurRegular)
{
  static const std::string pathName = "./this/is/a/path.test";
  ASSERT_EQ(FSAdaptor::Path{pathName}.string(), "this/is/a/path.test");
}

TEST_F(ParsingTest, RelParRegular)
{
  static const std::string pathName = "../this/is/a/path.test";
  ASSERT_EQ(FSAdaptor::Path{pathName}.string(), pathName);
}

TEST_F(ParsingTest, RemoveSlashes)
{
  static const std::string pathName = "/a/////path/on/system.txt";
  ASSERT_EQ(FSAdaptor::Path{pathName}.string(), "/a/path/on/system.txt");
}

TEST_F(ParsingTest, Spaces)
{
  static const std::string pathName = "A Path With Spaces.txt";
  ASSERT_EQ(FSAdaptor::Path{pathName}.string(), pathName);
}

///////////////////////////////////////////////////////////////////////////////
