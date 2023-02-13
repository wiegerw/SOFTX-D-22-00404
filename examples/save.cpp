#include <cstdlib>
#include <list>

#include <Eigen/Dense>
#include "io.h"

int main(int argc, char* argv[])
{
  std::string npy_file = argv[1];
  std::string npz_file = argv[2];

  Eigen::MatrixXf A {
    {1, 2, 3},
    {4, 5, 6}
  };

  Eigen::MatrixXf B {
      {1, 5, 9},
      {4, 6, 8}
  };

  save_npy(npy_file, A);
  print_matrix("A:", A);

  std::map<std::string, Eigen::MatrixXf> data;
  data["A"] = A;
  data["B"] = B;
  save_npz(npz_file, data);
  print_dict(data);

  return EXIT_SUCCESS;
}
