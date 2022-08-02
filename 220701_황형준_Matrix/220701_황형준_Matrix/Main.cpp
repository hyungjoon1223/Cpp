#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Matrix
{
    int* matrix;
    int row;
    int col;
public:
    explicit Matrix(int _row = 0, int _col = 0) :matrix(nullptr), row(_row), col(_col)
    {
        matrix = new int[_row * _col];
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                matrix[(col * i) + j] = 0;
    }
    Matrix(int _matrix[], int _row = 0, int _col = 0) :matrix(nullptr), row(_row), col(_col)
    {
        matrix = new int[_row * _col];
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                matrix[(col * i) + j] = _matrix[(col * i) + j];
    }
    Matrix(const Matrix& arg) :matrix(nullptr), row(arg.row), col(arg.col)
    {
        matrix = new int[arg.row * arg.col];
        row = arg.row;
        col = arg.col;
        for (int i = 0; i < arg.row; ++i)
            for (int j = 0; j < arg.col; ++j)
                matrix[(arg.col * i) + j] = arg.matrix[(arg.col * i) + j];
    }
    //~Matrix() { cout << "~Matrix" << endl;  delete[] matrix; }
    int* Getmatrix()const
    {
        return matrix;
    }
    int Getrow()const
    {
        return row;
    }
    int Getcol()const
    {
        return col;
    }
    int GetElement(int _row, int _col)const
    {
        return matrix[(col * (_row - 1)) + _col - 1];
    }
    void Setmatrix(int _matrix[], int size)
    {

        if (row * col != size)
            throw 1;

        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                matrix[(col * i) + j] = matrix[(col * i) + j] + _matrix[(col * i) + j];
    }
    void SetElement(int data, int _row, int _col)
    {
        if (row < _row || col < _col)
        {
            throw 1;
        }
        matrix[(col * (_row - 1)) + _col - 1] = data;
    }
    void Setrow(int _row)
    {
        row = _row;
    }
    void Setcol(int _col)
    {
        col = _col;
    }
    void Print()const
    {
        for (int i = 0; i < row; ++i)
        {

            for (int j = 0; j < col; ++j)
            {
                cout << matrix[(col * i) + j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    bool operator==(const Matrix& arg)const
    {
        return this == &arg;
    }
    bool operator!=(const Matrix& arg)const
    {
        return !(*this == arg);
    }
    const Matrix& operator=(const Matrix& arg)
    {
        if (*this == arg)
            return*this;

        delete[] matrix;

        int size = arg.col * arg.row;
        matrix = new int[size];
        row = arg.row;
        col = arg.col;
        for (int i = 0; i < arg.row; ++i)
            for (int j = 0; j < arg.col; ++j)
                matrix[(arg.col * i) + j] = arg.matrix[(arg.col * i) + j];
        return *this;
    }
    const Matrix operator+(const Matrix& arg)
    {

        if (row == arg.row && col == arg.col)
        {
            for (int i = 0; i < arg.row; ++i)
                for (int j = 0; j < arg.col; ++j)
                    matrix[(arg.col * i) + j] = matrix[(arg.col * i) + j] + arg.matrix[(arg.col * i) + j];
        }
        else
            throw 1;

        return *this;
    }
    const Matrix operator-(const Matrix& arg)
    {
        if (row == arg.row && col == arg.col)
        {
            for (int i = 0; i < arg.row; ++i)
                for (int j = 0; j < arg.col; ++j)
                    matrix[(arg.col * i) + j] = matrix[(arg.col * i) + j] - arg.matrix[(arg.col * i) + j];
        }
        else
            throw 1;
        return *this;
    }
    const Matrix operator*(const Matrix& arg)
    {
        if (col == arg.row && row == arg.col)
        {
            Matrix tempMatrix(row, arg.col);
            //mtrix.matrix;

            for (int p = 0; p < row; ++p)
            {
                for (int i = 0; i < arg.col; ++i)
                {
                    for (int j = 0; j < col; ++j)
                    {
                        tempMatrix.matrix[(arg.col * p) + i] = tempMatrix.matrix[(arg.col * p) + i] + (matrix[(col * p) + j] * arg.matrix[(arg.col * j) + i]);
                    }
                }
            }


            return tempMatrix;
        }
        else
            throw 1;
    }

};

int main()
{
    //Matrix arr1(2, 1);
    //Matrix arr2(1, 2);
    //Matrix arr3(2, 2);

    //arr3.Print();

    //arr3 = arr1 * arr2;

    int n[6] = { 3,3,3,3,3,3 };
    //Matrix arr1(3, 1);
    //Matrix arr2(1, 3);
    //Matrix arr3(1, 1);
    Matrix arr1(3, 2);
    Matrix arr2(2, 3);
    Matrix arr3(2, 2);
    arr1.Setmatrix(n, 6);
    arr2.Setmatrix(n, 6);
    arr1.Print();
    arr2.Print();
    arr3.Print();

    arr3 = arr1 * arr2;
    arr3.Print();
}

//#include <iostream>
//using namespace std;
//
//class Matrix
//{
//    int low;
//    int col;
//public:
//
//};
//class SetMatrix
//{
//    int j;
//    int k;
//public:
//
//};
//
//void MultiplyMatrix(int** A, int** B, int** C, int N, int M, int K) {
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < K; j++) {
//            for (int k = 0; k < M; k++) {
//                C[i][j] += A[i][k] * B[k][j];
//            }
//        }
//    }
//}
//
//int main(void) {
//    int N, M, K;
//    cin >> N >> M;
//    int** A = new int* [N];
//    int** B = new int* [M];
//    for (int i = 0; i < N; i++) {
//        A[i] = new int[M];
//        for (int j = 0; j < M; j++) {
//            cin >> A[i][j];
//        }
//    }
//    cin >> M >> K;
//    int** C = new int* [N];
//    for (int i = 0; i < N; i++) {
//        C[i] = new int[K];
//        for (int j = 0; j < K; j++) {
//            C[i][j] = 0;
//        }
//    }
//
//    for (int i = 0; i < M; i++) {
//        B[i] = new int[K];
//        for (int j = 0; j < K; j++) {
//            cin >> B[i][j];
//        }
//    }
//    MultiplyMatrix(A, B, C, N, M, K);
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < K; j++) {
//            cout << C[i][j] << " ";
//        }
//        cout << "\n";
//    }
//
//}
