//
// Created by caizixiang on 2019-07-27.
//

#include <iostream>
#include <cmath>

using namespace std;

#include <Eigen/Geometry>

int main()
{
    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();

    Eigen::AngleAxisd rotation_vector(M_PI/4, Eigen::Vector3d(0, 0, 1));

    cout .precision(3);
    cout << "rotation matrix" << endl << rotation_vector.matrix() << endl;

    rotation_matrix = rotation_vector.toRotationMatrix();

//    rotation_matrix = rotation_vector.toRotationMatrix();

    Eigen::Vector3d v(1, 0, 0);
    Eigen::Vector3d v_rotated = rotation_vector*v;

    cout << "(1, 0, 0) after rotation" << endl << v_rotated.transpose() << endl;

    // euler angle
    Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0);
    cout << "yaw pitch roll" << endl << euler_angles.transpose() << endl;

    Eigen::Isometry3d T = Eigen::Isometry3d::Identity();
    T.rotate(rotation_vector);
    T.pretranslate(Eigen::Vector3d(1, 3, 4));
    cout << "transform matrix" << endl << T.matrix() << endl;

    Eigen::Vector3d v_transformed = T*v;
    cout << "v transformed" << endl << v_transformed.transpose() << endl;

    // quaternion
    Eigen::Quaterniond q = Eigen::Quaterniond(rotation_vector);
    cout << "quaternion" << endl << q.coeffs() << endl;

    q = Eigen::Quaterniond(rotation_matrix);
    cout << "quaternion" << endl << q.coeffs() << endl;

    v_rotated = q*v;
    cout << "(1, 0, 0) after rotation" << endl << v_rotated.transpose() << endl;

    return 0;
}
