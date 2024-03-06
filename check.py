def read_matrix_from_file(fname):
    matrix = []
    with open(fname, "rb") as f:
        while True:
            row = f.read(4)
            if not row:
                break
            matrix.append(int.from_bytes(row, byteorder='little'))
    return matrix

def compare_matrices(file1, file2):
    matrix1 = read_matrix_from_file(file1)
    matrix2 = read_matrix_from_file(file2)

    if len(matrix1) != len(matrix2):
        print("Matrices have different sizes.")
        return

    for i in range(len(matrix1)):
        if matrix1[i] != matrix2[i]:
            print("Difference found at index:", i)
            print("Value in", file1, ":", matrix1[i])
            print("Value in", file2, ":", matrix2[i])
            return

    print("Matrices are identical.")

def main():
    file1 = input("Enter the path to the first file: ")
    file2 = input("Enter the path to the second file: ")

    compare_matrices(file1, file2)

if __name__ == "__main__":
    main()
