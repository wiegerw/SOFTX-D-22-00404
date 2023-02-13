#!/usr/bin/env python3

import sys
import numpy as np
from python_io import *


if __name__ == '__main__':
    npy_file = sys.argv[1]
    npz_file = sys.argv[2]

    A = np.array([
      [1, 2, 3],
      [4, 5, 6]
    ], dtype=np.float32)

    B = np.array([
        [1, 5, 9],
        [4, 6, 8]
    ], dtype=np.float32)

    data = {'A': A, 'B': B}

    save_npy(npy_file, A)
    print_matrix('A', A)

    save_npz(npz_file, data)
    print_dict(data)