project(donorTests)

include_directories(lib/googletest-master/googletest/include)

add_executable(runDonorTests
        basicTests.cpp)

add_subdirectory(lib/googletest-master)
target_link_libraries(runDonorTests gtest gtest_main)