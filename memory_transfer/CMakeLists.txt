cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
set(PNAME memory_transfer)
project(${PNAME})

set(SOURCES
   memory_transfer_main.cpp
)

cuda_add_executable(${PNAME} ${SOURCES})
target_link_libraries(${PNAME}
    ${CUDA_LIBRARIES}
    ${OpenCV_LIBS}
)

