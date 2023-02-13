#include <cstdlib>
#include <Eigen/Dense>
#include "io.h"

int main(int argc, char* argv[])
{
  std::string npy_file = argv[1];
  std::string npz_file = argv[2];

  Eigen::MatrixXf A = load_npy(npy_file);
  print_matrix(A);

  std::map<std::string, Eigen::MatrixXf> data = load_npz(npz_file);
  print_dict(data);

  return EXIT_SUCCESS;
}
