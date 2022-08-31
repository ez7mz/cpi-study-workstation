from algoFct import *
import numpy as np

# Test with Matrix of size 5 * 5

# Creation of two Matrices
G = np.array(
    [
        [1, 2, 3, 2, 3],
        [0, 4, 6, 2, 3],
        [1, 5, 1, 5, 6],
        [0, 4, 6, 2, 3],
        [9, 10, 11, 6, 7],
    ]
)

H = np.array(
    [
        [5, 2, 1, 6, 7],
        [1, 3, 9, 10, 11],
        [9, 3, 4, 1, 5],
        [1, 5, 1, 5, 6],
        [1, 2, 3, 2, 3],
    ]
)

print("\nMatrix A :\n")
print(G, "\n")
print("Matrix B :\n")
print(H, "\n")
print("The Product A * B with Strassen Algo: \n")
R = Strassen(G, H)
print(R, "\n")
print("The Product A*B with the classic method : \n")
print(np.dot(G, H))
