#!/usr/bin/python3
def print_matrix_integer(matrix=[[]]):
    if not matrix:
        return None 
    for submatrix in matrix:
        if len(submatrix) == 0:
            print ()
        for a in range(len(submatrix)):
            printf("{:d}".format{submatrix[a]},
                    end ="\n" if a is len(submatrix) - 1 else " ")
