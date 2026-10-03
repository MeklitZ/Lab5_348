#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <utility>

using namespace std;
// Prints a matrix in a formatted way
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << setw(4) << value;
        }
        cout << endl;
    }
}
// Problem 1: Read two matrices from a file
bool loadMatrices(const string& filename,
                  vector<vector<int>>& A,
                  vector<vector<int>>& B,
                  int& N) {
    
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Could not open file." << endl;
        return false;
    }
    inputFile >> N;
    if (N <= 0) {
        cerr << "Error: Matrix size must be positive." << endl;
        return false;
    }
    A.assign(N, vector<int>(N));
    B.assign(N, vector<int>(N));
    // Read Matrix A
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!(inputFile >> A[i][j])) {
                cerr << "Error: Not enough values for Matrix A." << endl;
                return false;
            }
        }
    }
    // Read Matrix B
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!(inputFile >> B[i][j])) {
                cerr << "Error: Not enough values for Matrix B." << endl;
                return false;
            }
        }
    }
    return true;
}

// Problem 2: Add two matrices
vector<vector<int>> addMatrices(const vector<vector<int>>& A,
                                const vector<vector<int>>& B) {
    
    int N = A.size();
    vector<vector<int>> result(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// Problem 3: Multiply two matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A,
                                     const vector<vector<int>>& B) {
    
    int N = A.size();
    vector<vector<int>> result(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Problem 4: Calculate diagonal sums
void diagonalSums(const vector<vector<int>>& matrix) {
    int N = matrix.size();

    int mainSum = 0;
    int secondarySum = 0;

    for (int i = 0; i < N; i++) {
        mainSum += matrix[i][i];
        secondarySum += matrix[i][N - 1 - i];
    }
    cout << "Main diagonal sum: " << mainSum << endl;
    cout << "Secondary diagonal sum: " << secondarySum << endl;
}

// Problem 5: Swap two rows
void swapRows(vector<vector<int>>& matrix, int row1, int row2) {
    int N = matrix.size();

    if (row1 < 0 || row1 >= N || row2 < 0 || row2 >= N) {
        cout << "Error: Invalid row index." << endl;
        return;
    }
    swap(matrix[row1], matrix[row2]);
}

// Problem 6: Swap two columns
void swapColumns(vector<vector<int>>& matrix, int col1, int col2) {
    int N = matrix.size();

    if (col1 < 0 || col1 >= N || col2 < 0 || col2 >= N) {
        cout << "Error: Invalid column index." << endl;
        return;
    }
    for (int i = 0; i < N; i++) {
        swap(matrix[i][col1], matrix[i][col2]);
    }
}

// Problem 7: Update one matrix element
void updateElement(vector<vector<int>>& matrix,
                   int row,
                   int column,
                   int newValue) {
    
    int N = matrix.size();
    if (row < 0 || row >= N || column < 0 || column >= N) {
        cout << "Error: Invalid matrix index." << endl;
        return;
    }
    matrix[row][column] = newValue;
}

int main() {
    string filename;
    cout << "Enter input filename: ";
    cin >> filename;

    vector<vector<int>> A;
    vector<vector<int>> B;
    int N;

    // Problem 1
    if (!loadMatrices(filename, A, B, N)) {
        return 1;
    }
    cout << "\nMatrix A:" << endl;
    printMatrix(A);

    cout << "\nMatrix B:" << endl;
    printMatrix(B);

    // Problem 2
    vector<vector<int>> sum = addMatrices(A, B);

    cout << "\nA + B:" << endl;
    printMatrix(sum);

    // Problem 3
    vector<vector<int>> product = multiplyMatrices(A, B);

    cout << "\nA * B:" << endl;
    printMatrix(product);

    // Problem 4
    cout << "\nDiagonal sums for Matrix A:" << endl;
    diagonalSums(A);

    // Problem 5
    vector<vector<int>> rowMatrix = A;
    swapRows(rowMatrix, 0, 2);

    cout << "\nProblem 5 - Rows 0 and 2 swapped:" << endl;
    printMatrix(rowMatrix);

    // Problem6
    vector<vector<int>> columnMatrix = A;
    swapColumns(columnMatrix, 0, 2);

    cout << "\nProblem 6 - Columns 0 and 2 swapped:" << endl;
    printMatrix(columnMatrix);

    // Problem 7
    vector<vector<int>> updatedMatrix = A;
    updateElement(updatedMatrix, 1, 2, 99);

    cout << "\nProblem 7 - Updated matrix:" << endl;
    printMatrix(updatedMatrix);

    return 0;
}