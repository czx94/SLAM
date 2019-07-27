//
// Created by caizixiang on 2019-07-26.
//

#include <iostream>
#include <ctime>

using namespace std;

#include <Eigen/Core>
#include <Eigen/Dense>

#define MATRIX_SIZE 5

int main(int argc, char** argv)
{
    // define a float matrix 2*3
    Eigen::Matrix<float, 2, 3> matrix_23;
    // define a double vector
    Eigen::Vector3d v_3d;
    // initialize an all zero matrix
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero();
    // define dynamic matrix
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> matrix_dynamic;
    // more convinient
    Eigen::MatrixXd matrix_x;

    matrix_23 << 1, 2, 3, 4, 5, 6;
    cout << "matrix_23" << endl << matrix_23 << endl;

//    for (int i = 0; i < 1; i++)
//    {
//        for (int j = 0; j < 2; j++)
//            cout << matrix_23(i, j) << endl;
//    }


    v_3d << 1, 2, 3;
    cout << "v_3d" << endl << v_3d << endl;

    Eigen::Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
    cout << "matrix_23*v_3d" << endl << result << endl;

    // some calcul
    matrix_33 = Eigen::Matrix3d::Random();
    cout << "matrix_33" << endl << matrix_33 << endl;

    cout << "transpose" << endl << matrix_33.transpose() << endl;
    cout << "sum" << endl << matrix_33.sum() << endl;
    cout << "trace" << endl << matrix_33.trace() << endl;
    cout << "10*" << endl << 10*matrix_33 << endl;
    // A^-1
    cout << "inverse" << endl << matrix_33.inverse() << endl;
    cout << "determinant" << endl << matrix_33.determinant() << endl;

    // eigen value
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver(matrix_33.transpose()*matrix_33);
    cout << "eigen values " << endl << eigen_solver.eigenvalues() << endl;
    cout << "eigen vectors " << endl << eigen_solver.eigenvectors() << endl;

    // solve equations
    Eigen::Matrix<double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    Eigen::Matrix<double, MATRIX_SIZE, 1> v_Nd = Eigen::MatrixXd::Random(MATRIX_SIZE, 1);
    cout << "matrix_nn" << endl << matrix_NN << endl;
    cout << "v_Nd" << endl << v_Nd << endl;

    clock_t time_stt = clock(); // time counter

    // cal reverse
    Eigen::Matrix<double, MATRIX_SIZE, 1> x = matrix_NN.inverse()*v_Nd;
    cout << "time used in inverse " << 1000*(clock() - time_stt)/(double) CLOCKS_PER_SEC << "ms" << endl;
    cout << "x" << endl << x << endl;

    // cal matrix split
    time_stt = clock();
    x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    cout << "time used in matrix split " << 1000*(clock() - time_stt)/(double) CLOCKS_PER_SEC << "ms" << endl;
    cout << "x" << endl << x << endl;

    return 0;
}
