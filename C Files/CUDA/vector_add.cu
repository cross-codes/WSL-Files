#include <assert.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10000000
#define MAX_ERR 1e-6

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
  if (err != cudaSuccess) {
    printf("CUDA malloc failed for d_a: %s\n", cudaGetErrorString(err));
    return -1;
  }

  err = cudaMalloc((void **)&d_b, sizeof(float) * N);
  if (err != cudaSuccess) {
    printf("CUDA malloc failed for d_b: %s\n", cudaGetErrorString(err));
    return -1;
  }

  err = cudaMalloc((void **)&d_out, sizeof(float) * N);
  if (err != cudaSuccess) {
    printf("CUDA malloc failed for d_out: %s\n", cudaGetErrorString(err));
    return -1;
  }

  err = cudaMemcpy(d_a, a, sizeof(float) * N, cudaMemcpyHostToDevice);
  if (err != cudaSuccess) {
    printf("CUDA memcpy failed for d_a: %s\n", cudaGetErrorString(err));
    return -1;
  }

  err = cudaMemcpy(d_b, b, sizeof(float) * N, cudaMemcpyHostToDevice);
  if (err != cudaSuccess) {
    printf("CUDA memcpy failed for d_b: %s\n", cudaGetErrorString(err));
    return -1;
  }

  int blockSize = 256;
  int numBlocks = (N + blockSize - 1) / blockSize;

  vector_add<<<numBlocks, blockSize>>>(d_out, d_a, d_b, N);

  err = cudaGetLastError();
  if (err != cudaSuccess) {
    printf("CUDA kernel launch failed: %s\n", cudaGetErrorString(err));
    return -1;
  }

  err = cudaDeviceSynchronize();
  if (err != cudaSuccess) {
    printf("CUDA synchronization failed: %s\n", cudaGetErrorString(err));
    return -1;
  }

  err = cudaMemcpy(out, d_out, sizeof(float) * N, cudaMemcpyDeviceToHost);
  if (err != cudaSuccess) {
    printf("CUDA memcpy failed for d_out: %s\n", cudaGetErrorString(err));
    return -1;
  }

  for (int i = 0; i < 10; i++) {
    printf("out[%d] = %f, expected = %f\n", i, out[i], a[i] + b[i]);
  }

  for (int i = 0; i < N; i++) {
    if (fabs(out[i] - (a[i] + b[i])) > MAX_ERR) {
      printf("Error at index %d: Expected %f, but got %f\n", i, a[i] + b[i],
             out[i]);
      return 1;
    }
  }

  printf("PASSED\n");

  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_out);

  free(a);
  free(b);
  free(out);
}
