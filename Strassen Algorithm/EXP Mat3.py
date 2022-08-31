from algoFct import *
import numpy as np

# Test with Matrix of size 3 * 3

# Creation of two Matrices
G = np.array([[2, 3, 4], [6, 7, 8], [13, 14, 15]])
H = np.array([[1, 2, 3], [5, 6, 7], [9, 10, 11]])


print("\nMatrix A :\n")
print(G, "\n")
print("Matrix B :\n")
print(H, "\n")
print("The Product A * B with Strassen Algo: \n")
R = Strassen(G, H)
print(R, "\n")
print("The Product A*B with the classic method : \n")
print(np.dot(G, H))
