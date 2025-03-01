#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#pragma pack(1)
#define N 10000

void rowAddition(int64_t[N][N], int64_t[N][N], int64_t[N][N]);
void columnAddition(int64_t[N][N], int64_t[N][N], int64_t[N][N]);
void printMatrix(int64_t[N][N]);

int32_t main(int argc, char **argv) {

  int64_t matrix1[N][N], matrix2[N][N], matrix3[N][N];

  memset(matrix3, 0x00, sizeof(matrix3));

  clock_t start = clock();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      matrix1[i][j] = rand() % 100;
      matrix2[i][j] = rand() % 100;
    }
  }
  clock_t end = clock();
  printf("Random filling: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

  start = clock();
  rowAddition(matrix1, matrix2, matrix3);
  end = clock();

  printf("Row addition: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

  memset(matrix3, 0x00, sizeof(matrix3));

  start = clock();
  columnAddition(matrix1, matrix2, matrix3);
  end = clock();
  printf("Column addition: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);

  return 0;
}

void rowAddition(int64_t matrix1[N][N], int64_t matrix2[N][N], int64_t matrix3[N][N]) {
  for (size_t y = 0; y < N; y++) {
    for (size_t x = 0; x < N; x++)
      matrix3[y][x] = matrix2[y][x] + matrix1[y][x];
  }
}

void columnAddition(int64_t matrix1[N][N], int64_t matrix2[N][N], int64_t matrix3[N][N]) {
  for (size_t x = 0; x < N; x++) {
    for (size_t y = 0; y < N; y++) {
      matrix3[y][x] = matrix1[y][x] + matrix2[y][x];
    }
  }
}

void printMatrix(int64_t matrix[N][N]) {
  for (size_t y = 0; y < N; y++) {
    for (size_t x = 0; x < N; x++) {
      printf("%ld ", matrix[y][x]);
    }
    printf("\n");
  }
}
