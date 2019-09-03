###############################################################################
# NAME:             CMakeLists.txt
#
# AUTHOR:           Ethan D. Twardy <edtwardy@mtu.edu>
#
# DESCRIPTION:      CMake rules for the Unit tests.
#
# CREATED:          09/03/2019
#
# LAST EDITED:      09/03/2019
###

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(UnitTests
    TestMain.cpp
    Path/UnixRelativeCurrentPathTest.h
    Path/UnixRelativeCurrentPathTest.cpp
    Path/UnixRelativeParentPathTest.cpp
    Path/UnixNoExtensionPathTest.cpp
    Path/UnixHiddenFilePathTest.cpp
    Path/UnixRelativeParentPathTest.h
    Path/UnixAbsolutePathTest.cpp
    Path/UnixNoExtensionPathTest.h
    Path/UnixHiddenFilePathTest.h
    Path/UnixAbsolutePathTest.h    
)

target_include_directories(UnitTests
    SYSTEM PRIVATE "${GTEST_INCLUDE_DIRS}"
)
target_include_directories(UnitTests
    PRIVATE ../include
)

target_link_libraries(UnitTests
    fsadaptor
    "${GTEST_BOTH_LIBRARIES}"
)

###############################################################################
