cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(cuda_playground)


# set(CUDA_TOOLKIT_ROOT_DIR ...)
find_package(CUDA REQUIRED)
set(CUDA_VERBOSE_BUILD ON)
cuda_include_directories(${CUDA_INCLUDE_DIRS})
include_directories(${CUDA_INCLUDE_DIRS})
message(STATUS "using CUDA version ${CUDA_VERSION_STRING}")

# check for common helper includes of sdk samples
set(CUDA_SDK_HELPER_SEARCH_DIR
  "${CUDA_SDK_HELPER_DIR}"
  "${CUDA_TOOLKIT_ROOT_DIR}/samples"
  )

find_path(CUDA_SDK_HELPER_INCLUDE_DIR
  helper_cuda.h
  PATHS ${CUDA_SDK_HELPER_SEARCH_DIR}
  PATH_SUFFIXES "common/inc" "C/common/inc"
  DOC "Location of helper_cuda.h"
  NO_DEFAULT_PATH
  )
include_directories(${CUDA_SDK_HELPER_INCLUDE_DIR})
cuda_include_directories(${CUDA_SDK_HELPER_INCLUDE_DIR})

message(STATUS "CUDA_SDK_HELPER_SEARCH_DIR=${CUDA_SDK_HELPER_SEARCH_DIR}")
message(STATUS "CUDA_SDK_HELPER_INCLUDE_DIR=${CUDA_SDK_HELPER_INCLUDE_DIR}")

# compile and build setup
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
LIST(APPEND CMAKE_CXX_FLAGS "-std=c++11 -O3 -ffast-math -Wall")
LIST(APPEND CUDA_NVCC_FLAGS --compiler-options -fno-strict-aliasing -lineinfo -use_fast_math -Xptxas -dlcm=cg)
LIST(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_20,code=sm_20)
LIST(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_30,code=sm_30)
LIST(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_35,code=sm_35)

add_subdirectory(memory_transfer)
