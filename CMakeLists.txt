cmake_minimum_required(VERSION 3.9)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled source/main.cpp header/IOperand.h source/Factory.cpp header/Factory.h header/OpBigDecimal.h source/OpBigDecimal.cpp header/OpDouble.h source/OpDouble.cpp header/OpFloat.h source/OpFloat.cpp header/OpInt32.h source/OpInt32.cpp header/OpInt16.h source/OpInt16.cpp header/OpInt8.h source/OpInt8.cpp source/Memory.cpp header/Memory.h source/Exceptions.cpp header/Exceptions.h source/IOInterface.cpp header/IOInterface.h source/Chipset.cpp header/Chipset.h source/Cpu.cpp header/Cpu.h source/TestFiles.cpp header/TestFiles.h)