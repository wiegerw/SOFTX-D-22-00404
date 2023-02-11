#!/usr/bin/env python3

import sys
import numpy as np


def load_eigen_matrix(filename: str) -> np.ndarray:
    print(f"Loading matrix from {filename}")
    return np.load(filename)


def save_eigen_matrix(filename: str, A: np.ndarray) -> None:
    print(f"Saving matrix to {filename}")
    np.save(filename, A)


def print_eigen_matrix(A: np.ndarray):
    print(A)


if __name__ == '__main__':
    filename = sys.argv[1]
    A = load_eigen_matrix(filename)
    print_eigen_matrix(A)
