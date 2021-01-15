#!/usr/bin/python3
"""Method to rotate a 2Dmatrix, 90 degrees clockwise"""


def rotate_2d_matrix(matrix):
    """Method to rotate a 2Dmatrix, 90 degrees clockwise"""
    if len(matrix) < 2:
        return
    n = len(matrix)
    for i in range(0, int(n / 2)):
        for j in range(i, n - i - 1):
            aux = matrix[i][j]
            matrix[i][j] = matrix[n - j - 1][i]
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]
            matrix[j][n - i - 1] = aux
    return
