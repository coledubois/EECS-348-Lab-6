#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//Problem 1 (Read in the file)
void readMatrixFromFile(const string& filename, int matrix1[3][3], int matrix2[3][3]) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        return;
    }

    string line;
    getline(file, line);

    int row = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        int num;
        int col = 0;
        while (ss >> num) {
            if (row < 3) {
                matrix1[row][col] = num;
            } else {
                matrix2[row - 3][col] = num;
            }
            col++;
        }
        row++;
    }
    file.close();
}

//Problem 2 (Print the Function)
void print_matrix(int matrix[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << "\n" << endl;
    }
    cout << endl;
}

//Problem 3 (Add two matrices and print the sum)
void matrix_addition(int matrix_1[3][3], int matrix_2[3][3]){
    int sum[3][3] = {{matrix_1[0][0] + matrix_2[0][0], matrix_1[0][1] + matrix_2[0][1], matrix_1[0][2] + matrix_2[0][2]},
                     {matrix_1[1][0] + matrix_2[1][0], matrix_1[1][1] + matrix_2[1][1], matrix_1[1][2] + matrix_2[1][2]},
                     {matrix_1[2][0] + matrix_2[2][0], matrix_1[2][1] + matrix_2[2][1], matrix_1[2][2] + matrix_2[2][2]}};

    cout << "The sum is:" << endl;
    print_matrix(sum);   
}

//Problem 4 (Multiply two matrices)
void matrix_multiplication(int matrix_1[3][3], int matrix_2[3][3]){
    cout << "Matrix 1 * Matrix 2:\n" << endl;
    int output_matrix[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                output_matrix[i][j] = output_matrix[i][j] + matrix_1[i][k] * matrix_2[k][j];
            }         
        }
    }
    print_matrix(output_matrix);
}

//Problem 5 (Subtract two matrices and print the difference)
void matrix_subtraction(int matrix_1[3][3], int matrix_2[3][3]){
    int difference[3][3] = {{matrix_1[0][0] - matrix_2[0][0], matrix_1[0][1] - matrix_2[0][1], matrix_1[0][2] - matrix_2[0][2]},
                            {matrix_1[1][0] - matrix_2[1][0], matrix_1[1][1] - matrix_2[1][1], matrix_1[1][2] - matrix_2[1][2]},
                            {matrix_1[2][0] - matrix_2[2][0], matrix_1[2][1] - matrix_2[2][1], matrix_1[2][2] - matrix_2[2][2]}};

    cout << "The difference is:" << endl;
    print_matrix(difference);   
}

//Problem 6 (Update an element of the first matrix; print the result)
void update_element(int (&matrix)[3][3], int row, int col, int new_value){
    matrix[row][col] = new_value;
    cout << "Replaced element at " << row << "," << col << " with " << new_value << endl;
    print_matrix(matrix);
}

//Problem 7 (Get the max value of the first matrix)
int find_max(int matrix[3][3]){
    int max = matrix[0][0];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(matrix[i][j] > max){
                max = matrix[i][j];
            }
        }
    }
    return max;
}

//Problem 8 (Transpose a matrix)
void transpose(int matrix[3][3]){
    int transposed_matrix[3][3] = {{matrix[0][0], matrix[1][0], matrix[2][0]},
                                   {matrix[0][1], matrix[1][1], matrix[2][1]},
                                   {matrix[0][2], matrix[1][2], matrix[2][2]}};
    cout << "The transpose is:" << endl;
    print_matrix(transposed_matrix);
}

int main(){

    int matrix_1[3][3], matrix_2[3][3];
    readMatrixFromFile("matrix_input.txt", matrix_1, matrix_2); //reads the file

    cout << "Matrix 1:" << endl;    print_matrix(matrix_1); //Prob 1: Prints the first matrix 
    cout << "Matrix 2:" << endl;    print_matrix(matrix_2); //Prob 2: Prints the second matrix
    matrix_addition(matrix_1, matrix_2); //Prob 3: Adds the two matrices
    matrix_multiplication(matrix_1, matrix_2); //Prob 4: Multiplies two matrices
    matrix_subtraction(matrix_1, matrix_2); //Prob 5: Subtracts matrix 2 from matrix 1 (matrix_1 - matrix_2)
    update_element(matrix_1, 2, 1, 15); //Problem 6: Updates an element in the matrix
    cout << "\nThe max from matrix 1 is: " << find_max(matrix_1) << "\n" << endl; //Prob 7: Finds the largest element in the matrix
    transpose(matrix_1); //Prob 8: Transposes matrix 1

    return 0;
}

