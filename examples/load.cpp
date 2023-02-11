#include <cstdlib>
#include <list>

#include <Eigen/Dense>
#include "cnpy++.hpp"

Eigen::MatrixXf load_eigen_matrix(const std::string& filename)
{
  std::cout << "Loading matrix from " << filename << std::endl;
  cnpypp::NpyArray array = cnpypp::npy_load(filename);
  const auto& shape = array.shape;
  return Eigen::Map<Eigen::MatrixXf>(array.data<float>(), shape[0], shape[1]);
}

void save_eigen_matrix(const std::string& filename, const Eigen::MatrixXf& A)
{
  std::cout << "Saving matrix to " << filename << std::endl;
  cnpypp::npy_save(filename, &A.data()[0], {static_cast<unsigned long>(A.rows()), static_cast<unsigned long>(A.cols())}, "w");
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
