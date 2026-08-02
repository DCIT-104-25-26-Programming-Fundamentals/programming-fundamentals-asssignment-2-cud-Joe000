// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Function to display a matrix in a neat grid
void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Function to read a matrix from the user
void readMatrix(int matrix[][MAX_SIZE], int rows, int cols, string name) {
    cout << "Enter elements for matrix " << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// PART A: Transpose a Matrix
// Computes the transpose of a matrix and displays it
void transposeMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix, rows, cols);
    
    cout << "\nTransposed Matrix:" << endl;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART B: Add Two Matrices
// Reads two matrices and displays their element-wise sum
void addMatrices() {
    int rows, cols;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    
    cout << "\n--- Matrix Addition ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    // Read both matrices
    readMatrix(matrixA, rows, cols, "A");
    readMatrix(matrixB, rows, cols, "B");
    
    // Compute sum
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    
    // Display results
    cout << "\nMatrix A:" << endl;
    displayMatrix(matrixA, rows, cols);
    
    cout << "\nMatrix B:" << endl;
    displayMatrix(matrixB, rows, cols);
    
    cout << "\nSum (A + B):" << endl;
    displayMatrix(result, rows, cols);
}

// PART C: Multiply Two Matrices
// Reads two matrices and displays their product
void multiplyMatrices() {
    int M, N, P;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE] = {0}; // Initialize to 0
    
    cout << "\n--- Matrix Multiplication ---" << endl;
    
    // Read dimensions for matrix A
    cout << "Enter rows for matrix A (M): ";
    cin >> M;
    cout << "Enter columns for matrix A (N): ";
    cin >> N;
    
    // Read matrix A
    readMatrix(matrixA, M, N, "A");
    
    // Read dimensions for matrix B
    cout << "Enter rows for matrix B: " << N << " (must equal columns of A)" << endl;
    cout << "Enter columns for matrix B (P): ";
    cin >> P;
    
    // Read matrix B
    readMatrix(matrixB, N, P, "B");
    
    // Compute product A x B
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    
    // Display results
    cout << "\nMatrix A (" << M << " x " << N << "):" << endl;
    displayMatrix(matrixA, M, N);
    
    cout << "\nMatrix B (" << N << " x " << P << "):" << endl;
    displayMatrix(matrixB, N, P);
    
    cout << "\nProduct (A x B) (" << M << " x " << P << "):" << endl;
    displayMatrix(result, M, P);
}

int main() {
    int choice;
    int rows, cols;
    int matrix[MAX_SIZE][MAX_SIZE];
    
    do {
        cout << "\n===== MATRIX OPERATIONS MENU =====" << endl;
        cout << "1. Transpose a Matrix" << endl;
        cout << "2. Add Two Matrices" << endl;
        cout << "3. Multiply Two Matrices" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "\n--- Matrix Transpose ---" << endl;
                cout << "Enter number of rows: ";
                cin >> rows;
                cout << "Enter number of columns: ";
                cin >> cols;
                readMatrix(matrix, rows, cols, "");
                transposeMatrix(matrix, rows, cols);
                break;
                
            case 2:
                addMatrices();
                break;
                
            case 3:
                multiplyMatrices();
                break;
                
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}
