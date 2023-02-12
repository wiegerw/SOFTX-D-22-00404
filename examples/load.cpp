#include <cstdlib>
#include <list>

#include <Eigen/Dense>
#include "cnpy++.hpp"

Eigen::MatrixXf load_eigen_matrix(const std::string& filename) {
  std::cout << "C++: loading matrix from " << filename << std::endl;
  cnpypp::NpyArray array = cnpypp::npy_load(filename);
  const auto& shape = array.shape;
  if (array.memory_order == cnpypp::MemoryOrder::C)
  {
    return Eigen::Map<const Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor>>(array.data<float>(), shape[1], shape[0]).transpose();
  }
  else
  {
    return Eigen::Map<Eigen::MatrixXf>(array.data<float>(), shape[0], shape[1]);
  }
}

void save_eigen_matrix(const std::string& filename, const Eigen::MatrixXf& A)
{
  std::cout << "C++ saving matrix to " << filename << std::endl;
  cnpypp::npy_save(filename, &A.data()[0], {static_cast<unsigned long>(A.rows()), static_cast<unsigned long>(A.cols())}, "w", cnpypp::MemoryOrder::C);
}

void print_eigen_matrix(const Eigen::MatrixXf& A)
{
  std::cout << A << std::endl;
}

int main(int argc, char* argv[])
{
  std::string filename = argv[1];

  Eigen::MatrixXf A = load_eigen_matrix(filename);
  print_eigen_matrix(A);

  return EXIT_SUCCESS;
}
