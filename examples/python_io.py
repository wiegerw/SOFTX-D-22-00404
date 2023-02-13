from typing import Dict
import numpy as np


def load(filename: str) -> np.ndarray:
    print(f"Loading data from {filename}")
    return np.load(filename, allow_pickle=True)


def save_npy(filename: str, A: np.ndarray) -> None:
    print(f"Saving matrix to {filename}")
    np.save(filename, A)


def save_npz(filename: str, data: Dict[str, np.ndarray]) -> None:
    print(f"Saving data to {filename}")
    np.savez_compressed(filename, **data)


def print_list(A: np.ndarray):
    values = [str(x) for x in A.flatten()]
    return f'[{", ".join(values)}]'


def print_matrix(name: str, A: np.ndarray):
    print(f'{name}: raw data = {print_list(A)}')
    print(A)


def print_dict(data: Dict[str, np.ndarray]):
    for key, value in data.items():
        print(f'{key}: raw data = {print_list(value)}\n{value}')
