#!/usr/bin/env python3

import sys
from python_io import *


if __name__ == '__main__':
    npy_file = sys.argv[1]
    npz_file = sys.argv[2]

    A = load(npy_file)
    print_matrix(A)

    data = load(npz_file)
    print_dict(data)