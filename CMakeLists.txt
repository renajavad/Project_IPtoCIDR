cmake_minimum_required(VERSION 3.10)
project(IPtoCidr)
add_executable(IPtoCidr main.cpp)
target_link_libraries(IPtoCidr gtest)