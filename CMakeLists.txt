# CMake required version
cmake_minimum_required(VERSION 3.1)

# "Only interpret if() arguments as variables or keywords when unquoted."
cmake_policy(SET CMP0054 NEW)

# Set cmake build type
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
      "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
      FORCE)
endif(NOT CMAKE_BUILD_TYPE)

# Set Cpp11
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS -m32)

# Set project title
project(samp-plugin-totp)

# Base path constants
set(SAMP_TOTP_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(SAMP_TOTP_BIN_ROOT ${CMAKE_CURRENT_BINARY_DIR})
set(SAMP_TOTP_BIN_OUT_DIR ${CMAKE_BINARY_DIR}/build)

# Externals
set(SAMP_TOTP_EXTERNAL ${SAMP_TOTP_ROOT}/external)

# Module
set(CMAKE_MODULE_PATH
	${CMAKE_MODULE_PATH}
	${SAMP_TOTP_ROOT}/build/cmake
	${SAMP_TOTP_EXTERNAL}/sampcmake
)

include(TotpExternal)

# Add src
add_subdirectory(src)
