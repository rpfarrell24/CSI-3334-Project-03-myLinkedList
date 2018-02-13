cmake_minimum_required(VERSION 3.9)
project(myLinkedList)

set(CMAKE_CXX_STANDARD 11)

add_executable(myLinkedList main.cpp myList.h "containerInterface.h")