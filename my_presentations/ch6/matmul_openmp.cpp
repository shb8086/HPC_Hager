#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>
#include <chrono>

void fillMatrixRandom(int **matrix, int rows, int cols)
{
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      matrix[i][j] = std::rand() % 100;
    }
  }
}

void fillMatrixZero(int **matrix, int rows, int cols)
{
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      matrix[i][j] = 0;
    }
  }
}

void printMatrix(int **matrix, int rows, int cols)
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int main()
{
  const int rows = 1000;
  const int cols = 1000;
  int** matrixA = new int*[rows];
  int** matrixB = new int*[cols];
  int** result_openmp = new int*[rows];
  int** result_non_openmp = new int*[rows];

  for (int i = 0; i < rows; ++i) {
    matrixA[i] = new int[cols];
    matrixB[i] = new int[cols];
    result_openmp[i] = new int[cols];
    result_non_openmp[i] = new int[cols];
  }

  fillMatrixRandom(matrixA, rows, cols);
  fillMatrixRandom(matrixB, rows, cols);
  fillMatrixZero(result_openmp, rows, cols);
  fillMatrixZero(result_non_openmp, rows, cols);

  // Measure execution time of OpenMP version
  auto startOpenMP = std::chrono::high_resolution_clock::now();

  #pragma omp parallel for
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      for (int k = 0; k < cols; ++k) {
        result_openmp[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }

  auto endOpenMP = std::chrono::high_resolution_clock::now();
  auto durationOpenMP = std::chrono::duration_cast<std::chrono::milliseconds>(endOpenMP - startOpenMP);
  std::cout << "OpenMP version time: " << durationOpenMP.count() << " milliseconds" << std::endl;

  // Measure execution time of non-OpenMP version
  auto startNonOpenMP = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      for (int k = 0; k < cols; ++k) {
        result_non_openmp[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }

  auto endNonOpenMP = std::chrono::high_resolution_clock::now();
  auto durationNonOpenMP = std::chrono::duration_cast<std::chrono::milliseconds>(endNonOpenMP - startNonOpenMP);
  std::cout << "Non-OpenMP version time: " << durationNonOpenMP.count() << " milliseconds" << std::endl;

  // Clean up memory
  for (int i = 0; i < rows; ++i) {
    delete[] matrixA[i];
    delete[] matrixB[i];
    delete[] result_openmp[i];
    delete[] result_non_openmp[i];
  }
  delete[] matrixA;
  delete[] matrixB;
  delete[] result_openmp;
  delete[] result_non_openmp;

  return 0;
}