#include <cstdlib>
#include <list>
#include <map>
#include <Eigen/Dense>
#include "cnpy++.hpp"

inline
Eigen::MatrixXf to_eigen(const cnpypp::NpyArray& array)
{
  const auto& shape = array.shape;
  if (array.memory_order == cnpypp::MemoryOrder::C)
  {
    return Eigen::Map<const Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor>>(array.data<float>(), shape[1], shape[0]).transpose();
  }
  else
  {
    return Eigen::Map<Eigen::MatrixXf>(const_cast<float*>(array.data<float>()), shape[0], shape[1]);
  }
}

inline
Eigen::MatrixXf load_npy(const std::string& filename)
{
  std::cout << "C++: loading matrix from " << filename << std::endl;
  cnpypp::NpyArray array = cnpypp::npy_load(filename);
  return to_eigen(array);
}

inline
void save_npy(const std::string& filename, const Eigen::MatrixXf& A)
{
  std::cout << "C++ saving matrix to " << filename << std::endl;
  cnpypp::npy_save(filename, &A.data()[0], {static_cast<unsigned long>(A.rows()), static_cast<unsigned long>(A.cols())}, "w", cnpypp::MemoryOrder::Fortran);
}

inline
std::map<std::string, Eigen::MatrixXf> load_npz(const std::string& filename)
{
  std::cout << "C++: loading data from " << filename << std::endl;

  std::map<std::string, Eigen::MatrixXf> result;
  cnpypp::npz_t data = cnpypp::npz_load(filename);
  for (const auto& [key, value]: data)
  {
    result[key] = to_eigen(value);
  }
  return result;
}

inline
void save_npz(const std::string& filename, const std::map<std::string, Eigen::MatrixXf>& data)
{
  std::cout << "C++ saving data to " << filename << std::endl;
  for (const auto& [key, value]: data)
  {
    std::vector<size_t> shape { static_cast<size_t>(value.rows()), static_cast<size_t>(value.cols()) };
    cnpypp::npz_save(filename, key, value.data(), shape, "a", cnpypp::MemoryOrder::Fortran);
  }
}

inline
void print_matrix(const Eigen::MatrixXf& A)
{
  std::cout << A << std::endl;
}

inline
void print_dict(const std::map<std::string, Eigen::MatrixXf>& data)
{
  for (const auto& [key, value]: data)
  {
    std::cout << key << " ->\n" << value << std::endl;
  }
}