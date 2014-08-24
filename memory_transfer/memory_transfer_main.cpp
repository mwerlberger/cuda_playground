#include <iostream>
#include <cuda_runtime.h>
#include <helper_cuda.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//--------------------------------------------------------------------------------
int main(int argc, char** argv)
{
  std::cout << "We are alive!" << std::endl;

  // set device
  cudaDeviceProp device_prop;
  int dev_id = findCudaDevice(argc, (const char **) argv);
  checkCudaErrors(cudaGetDeviceProperties(&device_prop, dev_id));
  std::cout << "set cuda device id: " << dev_id << std::endl;

  cv::Mat im1 = cv::imread("/home/mwerlberger/data/std/Growth_of_cubic_bacteria_25x16.jpg");
  std::cout << "im1 size: " << im1.cols << "x" << im1.rows << std::endl;

  // copy im1 to global memory
  uchar* d_im1;
  const size_t size = im1.rows * im1.cols * sizeof(float);

//  cv::imshow("input", im1);
//  //cv::imshow("result", im1);
//  cv::waitKey();
  return EXIT_SUCCESS;
}
