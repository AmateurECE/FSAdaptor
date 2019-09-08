###############################################################################
# NAME:             CMakeLists.txt
#
# AUTHOR:           Ethan D. Twardy <edtwardy@mtu.edu>
#
# DESCRIPTION:      CMake rules for the Unit tests.
#
# CREATED:          09/03/2019
#
# LAST EDITED:      09/08/2019
###

find_program(BASH_PROGRAM bash REQUIRED)
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(UnitTests
    TestMain.cpp
    Path/ParsingTest.cpp
    Path/ConcatenatingTest.cpp
    Path/DiscoveredDefects.cpp
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

enable_testing()
gtest_discover_tests(UnitTests)

###############################################################################
# Verification Executables
###

# add_executable(absolute StandardFilesystemAdaptor/absolute.cpp)
# target_include_directories(absolute PRIVATE ../include)
# target_link_libraries(absolute fsadaptor)
# add_test(absolute ${CMAKE_CURRENT_SOURCE_DIR}/Scripts/absolute.sh)

# add_executable(createDirectories
#     StandardFilesystemAdaptor/createDirectories.cpp)
# target_include_directories(createDirectories PRIVATE ../include)
# target_link_libraries(createDirectories fsadaptor)
# add_test(createDirectories
#     ${CMAKE_CURRENT_SOURCE_DIR}/Scripts/createDirectories.sh)

# add_executable(createDirectory StandardFilesystemAdaptor/createDirectory.cpp)
# target_include_directories(createDirectory PRIVATE ../include)
# target_link_libraries(createDirectory fsadaptor)
# add_test(createDirectory
#     ${CMAKE_CURRENT_SOURCE_DIR}/Scripts/createDirectory.sh)

# add_executable(currentPath StandardFilesystemAdaptor/currentPath.cpp)
# target_include_directories(currentPath PRIVATE ../include)
# target_link_libraries(currentPath fsadaptor)
# add_test(currentPath ${CMAKE_CURRENT_SOURCE_DIR}/Scripts/currentPath.sh)

# add_executable(equivalent StandardFilesystemAdaptor/equivalent.cpp)
# target_include_directories(equivalent PRIVATE ../include)
# target_link_libraries(equivalent fsadaptor)
# add_test(equivalent ${CMAKE_CURRENT_SOURCE_DIR}/Scripts/equivalent.sh)

# add_executable(exists StandardFilesystemAdaptor/exists.cpp)
# target_include_directories(exists PRIVATE ../include)
# target_link_libraries(exists fsadaptor)
# add_test(exists ${CMAKE_CURRENT_SOURCE_DIR}/Scripts/exists.sh)

# add_executable(isDirectory StandardFilesystemAdaptor/isDirectory.cpp)
# target_include_directories(isDirectory PRIVATE ../include)
# target_link_libraries(isDirectory fsadaptor)
# add_test(isDirectory ${CMAKE_CURRENT_SOURCE_DIR}/Scripts/isDirectory.sh)

# add_executable(isEmpty StandardFilesystemAdaptor/isEmpty.cpp)
# target_include_directories(isEmpty PRIVATE ../include)
# target_link_libraries(isEmpty fsadaptor)
# add_test(isEmpty ${CMAKE_CURRENT_SOURCE_DIR}/Scripts/isEmpty.sh)

# add_executable(remove StandardFilesystemAdaptor/remove.cpp)
# target_include_directories(remove PRIVATE ../include)
# target_link_libraries(remove fsadaptor)
# add_test(remove ${CMAKE_CURRENT_SOURCE_DIR}/Scripts/remove.sh)

# add_executable(rename StandardFilesystemAdaptor/rename.cpp)
# target_include_directories(rename PRIVATE ../include)
# target_link_libraries(rename fsadaptor)
# add_test(rename ${CMAKE_CURRENT_SOURCE_DIR}/Scripts/rename.sh)

# add_executable(walk StandardFilesystemAdaptor/walk.cpp)
# target_include_directories(walk PRIVATE ../include)
# target_link_libraries(walk fsadaptor)
# add_test(walk ${CMAKE_CURRENT_SOURCE_DIR}/Scripts/walk.sh)

###############################################################################
