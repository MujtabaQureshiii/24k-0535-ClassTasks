#include <iostream> 
using namespace std; 
 
class DynamicMatrix { 
private: 
    int** matrix; 
    int rows; 
    int cols; 
 
public: 
    DynamicMatrix(int r, int c) { 
        rows = r; 
        cols = c; 
        matrix = new int*[rows]; 
        for (int i = 0; i < rows; i++) { 
            matrix[i] = new int[cols]; 
        } 
    } 
 
    ~DynamicMatrix() { 
        for (int i = 0; i < rows; i++) { 
            delete[] matrix[i]; 
        } 
        delete[] matrix; 
    } 
 
    void resize(int newRows, int newCols, int fillValue) { 
        int** newMatrix = new int*[newRows]; 
        for (int i = 0; i < newRows; i++) { 
            newMatrix[i] = new int[newCols]; 
            for (int j = 0; j < newCols; j++) { 
                if (i < rows && j < cols) { 
                    newMatrix[i][j] = matrix[i][j]; 
                } else { 
                    newMatrix[i][j] = fillValue; 
                } 
            } 
        } 
 
        for (int i = 0; i < rows; i++) { 
            delete[] matrix[i]; 
        } 
        delete[] matrix; 
 
        matrix = newMatrix; 
        rows = newRows; 
        cols = newCols; 
    } 
 
    void transpose() { 
        int** transposed = new int*[cols]; 
        for (int i = 0; i < cols; i++) { 
            transposed[i] = new int[rows]; 
            for (int j = 0; j < rows; j++) { 
                transposed[i][j] = matrix[j][i]; 
            } 
        } 
 
        for (int i = 0; i < rows; i++) { 
            delete[] matrix[i]; 
        } 
        delete[] matrix; 
 
        matrix = transposed; 
        swap(rows, cols); 
    } 
 
    void addToOddIndex(int value) { 
        for (int i = 0; i < rows; i++) { 
            for (int j = 0; j < cols; j++) { 
                if ((i + j) % 2 != 0) { 
                    matrix[i][j] += value; 
                } 
            } 
        } 
    } 
 
    void print() const { 
        for (int i = 0; i < rows; i++) { 
            for (int j = 0; j < cols; j++) { 
                cout << matrix[i][j] << " "; 
            } 
            cout << endl; 
        } 
    } 
 
    void fill(int value) { 
        for (int i = 0; i < rows; i++) { 
            for (int j = 0; j < cols; j++) { 
                matrix[i][j] = value; 
            } 
        } 
    } 
 
    int getRows() const { 
        return rows; 
    } 
 
    int getCols() const { 
        return cols; 
    } 
}; 
 
int main() { 
    DynamicMatrix mat(3, 3); 
    mat.fill(5); 
 
    cout << "Original Matrix: \n"; 
    mat.print(); 
 
    mat.addToOddIndex(2); 
    cout << "Matrix after adding 2 to odd indices: \n"; 
    mat.print(); 
 
    mat.resize(4, 4, 0); 
    cout << "Resized Matrix (4x4): \n"; 
    mat.print(); 
 
    mat.transpose(); 
    cout << "Transposed Matrix: \n"; 
    mat.print(); 
 
    return 0; 
} 
