#include <chrono>
#include <cuda.h>
#include <cuda_runtime.h>
#include <iostream>

#define N 10000000
#define MAX_ERR 1e-6

/**
Compile with
LD_LIBRARY_PATH=/usr/local/cuda/compat nvcc vector_add.cu -Xcompiler -O3 \
-arch=sm_86 -o vector_add
 */

void vector_add_cpu(float *out, float *a, float *b, int n) {
  for (size_t i = 0; i < n; i++)
    out[i] = a[i] + b[i];
}

__global__ void vector_add(float *out, float *a, float *b, int n) {
  int idx = threadIdx.x + blockIdx.x * blockDim.x;

  if (idx < n) {
    out[idx] = a[idx] + b[idx];
  }
}

int main() {
  float *a, *b, *out;
  float *d_a, *d_b, *d_out;

  a = (float *)malloc(sizeof(float) * N);
  b = (float *)malloc(sizeof(float) * N);
  out = (float *)malloc(sizeof(float) * N);

  for (int i = 0; i < N; i++) {
    a[i] = 1.0f;
    b[i] = 2.0f;
  }

  cudaError_t err = cudaMalloc((void **)&d_a, sizeof(float) * N);
  err = cudaMalloc((void **)&d_b, sizeof(float) * N);
  err = cudaMalloc((void **)&d_out, sizeof(float) * N);
  err = cudaMemcpy(d_a, a, sizeof(float) * N, cudaMemcpyHostToDevice);
  err = cudaMemcpy(d_b, b, sizeof(float) * N, cudaMemcpyHostToDevice);

  int blockSize = 256;
  int numBlocks = (N + blockSize - 1) / blockSize;

  auto start = std::chrono::high_resolution_clock::now();
  vector_add<<<numBlocks, blockSize>>>(d_out, d_a, d_b, N);
  cudaDeviceSynchronize();
  auto end = std::chrono::high_resolution_clock::now();

  std::cout << "GPU time: " << std::chrono::duration<float>(end - start).count()
            << "\n";

  err = cudaMemcpy(out, d_out, sizeof(float) * N, cudaMemcpyDeviceToHost);
  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_out);

  start = std::chrono::high_resolution_clock::now();
  vector_add_cpu(out, a, b, N);
  end = std::chrono::high_resolution_clock::now();

  std::cout << "CPU time: " << std::chrono::duration<float>(end - start).count()
            << "\n";

  free(a);
  free(b);
  free(out);
}
