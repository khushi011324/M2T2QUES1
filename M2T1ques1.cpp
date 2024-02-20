#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to perform matrix multiplication
void matrixMultiplication(int **A, int **B, int **C, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int **matrix, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Set the size of the matrices
    const int N = 3; // You can change this to any desired size

    // Initialize matrices A, B, and C with random values
    int **A = new int*[N];
    int **B = new int*[N];
    int **C = new int*[N];

    for (int i = 0; i < N; ++i) {
        A[i] = new int[N];
        B[i] = new int[N];
        C[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            A[i][j] = rand() % 10; // Assign random values between 0 and 9
            B[i][j] = rand() % 10;
        }
    }

    // Perform matrix multiplication
    matrixMultiplication(A, B, C, N);

    // Print matrices A, B, and C
    cout << "Matrix A:" << endl;
    printMatrix(A, N);
    cout << endl;

    cout << "Matrix B:" << endl;
    printMatrix(B, N);
    cout << endl;

    cout << "Matrix C (Result of A * B):" << endl;
    printMatrix(C, N);
    cout << endl;

    // Write the result matrix C to a file
    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                outputFile << C[i][j] << " ";
            }
            outputFile << endl;
        }
        outputFile.close();
        cout << "Result written to output.txt" << endl;
    } else {
        cerr << "Unable to open output.txt for writing." << endl;
    }

    // Deallocate memory
    for (int i = 0; i < N; ++i) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
