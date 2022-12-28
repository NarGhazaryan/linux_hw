cmake_minimum_required(VERSION 3.23)
project(ThreadAPI)

set(CMAKE_CXX_STANDARD 17)

add_executable(ThreadAPITest main.cpp ./ThreadAPI/details/LinuxThreadDetails.h ./ThreadAPI/LinuxThread.h ./ThreadAPI/LinuxMutex.h ./ThreadAPI/ConditionVariable.h)
target_link_libraries(ThreadAPITest PUBLIC -lpthread)