# Testing by gtest
FetchContent_Declare(
  gtest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        master
)
FetchContent_MakeAvailable(gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(testMoney test.cpp)

target_compile_features(testMoney PRIVATE cxx_std_14)

target_include_directories(testMoney PRIVATE ../include)

# Should be linked to the main library, as well as the Catch2 testing library

target_link_libraries(testMoney PRIVATE gtest gtest_main)

# If you register a test, then ctest and make test will run it.
# You can also run examples and check the output, as well.
add_test(NAME money_test COMMAND testMoney) # Command can be a target
