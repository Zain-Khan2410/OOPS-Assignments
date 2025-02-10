#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int** matrix;
public:
 Matrix(int r, int c) {
        rows = r;
        cols = c;
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
        }
    }
    int getrows(){
        return rows;
    }
    int getcols(){
        return cols;
    }
        void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            matrix[i][j] = value;
        } else {
            cout << "Invalid position!\n";
        }
    }

    void inputMatrix() {
        cout << "Enter elements for a " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Element [" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }
    }

    void displayMatrix() {
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
   Matrix add(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols) {
            cout << "Matrices cannot be added" << endl;
            return Matrix(0, 0);  
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix product(const Matrix& other) const {
        if (cols != other.rows) {
            cout << "Matrices cannot be multiplied (incompatible sizes)." << endl;
            return Matrix(0, 0); 
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.matrix[i][j]=0;
                for (int k = 0; k < cols; k++) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }
    


};  
int main(){
 int rows1, cols1, rows2, cols2;

    cout << "Enter the number of rows and columns for Matrix 1: ";
    cin >> rows1 >> cols1;
    Matrix m1(rows1, cols1);
    m1.inputMatrix();

    cout << "Enter the number of rows and columns for Matrix 2: ";
    cin >> rows2 >> cols2;
    Matrix m2(rows2, cols2);
    m2.inputMatrix();

    // Display matrices
    cout << "\nMatrix 1:" << endl;
    m1.displayMatrix();

    cout << "\nMatrix 2:" << endl;
    m2.displayMatrix();

    Matrix sum = m1.add(m2);

        cout << "Sum of Matrix 1 and Matrix 2:" << endl;
        sum.displayMatrix();
    
    Matrix product = m1.product(m2);
    cout<<"Product of Matrix 1 aand Matrix 2: " << endl;
    product.displayMatrix();
    }
   
  
 