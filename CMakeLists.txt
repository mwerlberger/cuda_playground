cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(cuda_playground)


# set(CUDA_TOOLKIT_ROOT_DIR ...)
find_package(CUDA REQUIRED)
set(CUDA_VERBOSE_BUILD ON)
cuda_include_directories(${CUDA_INCLUDE_DIRS})
include_directories(${CUDA_INCLUDE_DIRS})
message(STATUS "using CUDA version ${CUDA_VERSION_STRING}")

# compile and build setup
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
LIST(APPEND CMAKE_CXX_FLAGS "-std=c++11 -O3 -ffast-math -Wall")
LIST(APPEND CUDA_NVCC_FLAGS --compiler-options -fno-strict-aliasing -lineinfo -use_fast_math -Xptxas -dlcm=cg)
LIST(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_20,code=sm_20)
LIST(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_30,code=sm_30)
LIST(APPEND CUDA_NVCC_FLAGS -gencode arch=compute_35,code=sm_35)

add_subdirectory(memory_transfer)
