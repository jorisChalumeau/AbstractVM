cmake_minimum_required(VERSION 3.9)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled source/main.cpp source/IOperand.cpp header/IOperand.h source/Factory.cpp header/Factory.h header/BigDecimal.h source/BigDecimal.cpp header/Double.h source/Double.cpp header/Float.h source/Float.cpp header/Int32.h source/Int32.cpp header/Int16.h source/Int16.cpp header/Int8.h source/Int8.cpp)