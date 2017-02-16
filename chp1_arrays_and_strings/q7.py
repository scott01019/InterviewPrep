# Write an algorithm such that if an element in an MxN matrix is 0, its entire
# row and column is set to 0.

def matrixAlg(matrix):
    print(matrix)
    rows = []
    columns = []
    for i in range(0, len(matrix)):
        for j in range(0, len(matrix[0])):
            if matrix[i][j] == 0:
                rows.append(i)
                columns.append(j)

    for row in set(rows):
        for i in range(0, len(matrix[row])):
            matrix[row][i] = 0

    for column in set(columns):
        for i in range(0, len(matrix)):
            matrix[i][column] = 0

    print(matrix)


mats = [ [ [ 0, 1, 1 ], [2, 2, 2], [3, 3, 3] ],
         [ [1, 1, 1, 1, 1], [1,1,1,1,1], [1, 1,0,1,0] ]
        ]

for mat in mats:
    matrixAlg(mat)
