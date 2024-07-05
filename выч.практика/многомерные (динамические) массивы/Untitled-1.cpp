#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int calculateMatrixRank(double** matrix, int n, int m) {
    int r = 0;
    for (int i = 0; i < n && r < m; i++) {
        int curr = -1;
        for (int j = r; j < n; j++) {
            if (matrix[j][i] != 0) {
                curr = j;
                break;
            }
        }
        if (curr == -1) {
            continue;
        }
        swap(matrix[r], matrix[curr]);
        for (int j = r + 1; j < n; j++) {
            double ratio = matrix[j][i] / matrix[r][i];
            for (int k = i; k < m; k++) {
                matrix[j][k] -= ratio * matrix[r][k];
            }
        }
        r++;
    }
    return r;
}

int main() {
    int n, m;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> n >> m;
    double** matrix = new double*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[m];
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 21 - 10;
        }
    }
    string filePath = "matrix.txt";
    ofstream outFile(filePath, ios::out | ios::trunc);
    if (!outFile.is_open()) {
        cerr << "Error: could not open file " << filePath << endl;
        return 1;
    }
    outFile.close();
    outFile.open(filePath);
    if (!outFile.is_open()) {
        cerr << "Error: could not open file " << filePath << endl;
        return 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            outFile << matrix[i][j] << " ";
        }
        outFile << endl;
    }
    outFile.close();
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    double** readMatrix = new double*[n];
    for (int i = 0; i < n; i++) {
        readMatrix[i] = new double[m];
    }
    ifstream inFile(filePath);
    if (!inFile.is_open()) {
        cerr << "Error: could not open file " << filePath << endl;
        return 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            inFile >> readMatrix[i][j];
        }
    }
    inFile.close();
    int matrixRank = calculateMatrixRank(readMatrix, n, m);
    cout << "Rank of the matrix: " << matrixRank << endl;
    for (int i = 0; i < n; i++) {
        delete[] readMatrix[i];
    }
    delete[] readMatrix;
    return 0;
}