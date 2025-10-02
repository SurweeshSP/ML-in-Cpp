#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <armadillo>

using namespace std;
using namespace Eigen;   

int main(){

    // STL vector
    vector<int> v ={1,2,3,4,5};
    v.push_back(6);

    for(int i:v){
        cout<<i<<" ";
    }
    cout << "\nthe first element: " << v[0] << endl;
    cout << "the last element: " << v[v.size()-1] << endl;
    cout << "the size of vector: " << v.size() << endl;

    // STL matrix
    vector<vector<int>> mat={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    cout << "the element at 2nd row and 3rd column: " << mat[1][2] << endl;
    cout << "the number of rows: " << mat.size() << endl;
    cout << "the number of columns in 1st row: " << mat[0].size() << endl;

    // Eigen column vector
    Vector3d vec(1,2,3);
    cout << "Eigen vector:\n" << vec << endl;

    // Eigen row vector
    RowVector3d rowVec(4,5,6);
    cout << "Eigen row vector:\n" << rowVec << endl;

    // Eigen matrix
    Matrix3d m;
    m << 2, -1, 0,
        -1, 2, -1,
         0, -1, 2;

    cout << "Eigen Matrix:\n" << m << endl;
    cout << "Inverse of Matrix:\n" << m.inverse() << endl;
    cout << "Determinant of Matrix: " << m.determinant() << endl;

    // Armadillo
    arma::vec v1 = {1, 2, 3};      // column vector
    v1.print("Armadillo vector v:");

    arma::rowvec r1 = {4, 5, 6};   // row vector
    r1.print("Armadillo row vector r:");

    arma::mat M = { {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9} };
    M.print("Armadillo Matrix M:");

    return 0;
}
