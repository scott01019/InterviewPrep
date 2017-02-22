# Given an image represented by an NxN matrix, where each pixel in the image
# is 4 bytes, write a method to rotate the image by 90 degrees. Can you do this
# in place?

def rotate(matrix):
    for layer in range(0, int(len(matrix)/2)):
        first = layer
        last = len(matrix) - 1 - layer
        for i in range(first, last):
            offset = i - first
            top = matrix[first][i]
            matrix[first][i] = matrix[last-offset][first]
            matrix[last-offset][first] = matrix[last][last-offset]
            matrix[last][last-offset] = matrix[i][last]
            matrix[i][last] = top

mat = [ [ 'a', 'b', 'c', 'd', 'e' ],
        [ 'f', 'g', 'h', 'i', 'j' ],
        [ 'k', 'l', 'm', 'n', 'o' ],
        [ 'p', 'q', 'r', 's', 't' ],
        [ 'u', 'v', 'w', 'x', 'y' ] ]

for row in mat:
    print(row)

rotate(mat)
print()
print()

for row in mat:
    print(row)
