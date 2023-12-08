#include <iostream>
#include <string>
#include "Matrix.h"
using namespace std;

int main()
{
    //   int
    /*Matrix<> matrix(43);
    cin >> matrix;
    cout << matrix << endl;
    matrix.Show();
    cout << "Max :: " << matrix.max() << endl;
    cout << "Min :: " << matrix.min() << endl;
    if (matrix.element(2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << matrix(1, 1) << endl;
    cout << "Sum :: " << matrix.sum() << endl;
    Matrix<> sum_matrix, matrix_2(1);
    sum_matrix = matrix + matrix_2;
    cout << "Sum matrix_1 + matrix_2 :: " << endl;
    cout << sum_matrix << endl;
    sum_matrix = matrix + 4;
    cout << sum_matrix << endl;
    sum_matrix = 10 + matrix;
    cout << sum_matrix << endl;

    cout << " == " << endl;
    if (matrix == matrix_2) cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << " != " << endl;
    if (matrix != matrix_2) cout << "Yes" << endl;
    else
        cout << "No" << endl;


    cout << matrix << endl;
    matrix += 5;
    cout << matrix << endl;*/

    // float

    /*Matrix<double> matrix(43.3);
    cin >> matrix;
    cout << matrix << endl;
    matrix.Show();
    cout << "Max :: " << matrix.max() << endl;
    cout << "Min :: " << matrix.min() << endl;
    if (matrix.element(2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << matrix(1, 1) << endl;
    cout << "Sum :: " << matrix.sum() << endl;
    Matrix<double> sum_matrix, matrix_2(1);
    sum_matrix = matrix + matrix_2;
    cout << "Sum matrix_1 + matrix_2 :: " << endl;
    cout << sum_matrix << endl;
    sum_matrix = matrix + 4;
    cout << sum_matrix << endl;
    sum_matrix = 10. + matrix;
    cout << sum_matrix << endl;

    cout << " == " << endl;
    if (matrix == matrix_2) cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << " != " << endl;
    if (matrix != matrix_2) cout << "Yes" << endl;
    else
        cout << "No" << endl;


    cout << matrix << endl;
    matrix += 5;
    cout << matrix << endl;*/

    // string

    Matrix<string> matrix("hello");
    cin >> matrix;
    cout << matrix << endl;
    matrix.Show();
    cout << "Max :: " << matrix.max() << endl;
    cout << "Min :: " << matrix.min() << endl;
    if (matrix.element("hello"))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    cout << matrix(1, 1) << endl;
    cout << "Sum :: " << matrix.sum() << endl;
    Matrix<string> sum_matrix, matrix_2("sun");
    sum_matrix = matrix + matrix_2;
    cout << "Sum matrix_1 + matrix_2 :: " << endl;
    cout << sum_matrix << endl;
    cout << matrix + "word" << endl;
    string name = "word";
    sum_matrix = name + matrix;
    cout << sum_matrix << endl;

    cout << " == " << endl;
    if (matrix == matrix_2) cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << " != " << endl;
    if (matrix != matrix_2) cout << "Yes" << endl;
    else
        cout << "No" << endl;


    cout << matrix << endl;
    matrix += "word";
    cout << matrix << endl;
}

