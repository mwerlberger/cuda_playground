#include <iostream>
#include <cuda_runtime.h>

//--------------------------------------------------------------------------------
int main(int argc, char** argv)
{
  std::cout << "We are alive!" << std::endl;

//  // set device
//  cudaDeviceProp device_prop;
//  int dev_id = findCudaDevice(argc, (const char **) argv);
//  checkCudaErrors(cudaGetDeviceProperties(&device_prop, dev_id));
//  std::cout << "set device id: " << dev_id << std::endl;



  cudaDeviceReset();
  return EXIT_SUCCESS;
}
