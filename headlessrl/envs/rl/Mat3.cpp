#include "Mat3.h"
#include <math.h>
#include <iostream>

Mat3::Mat3(){
    this->a = Vec3();
    this->b = Vec3();
    this->c = Vec3();
}

Mat3::Mat3(const Vec3 &a, const Vec3 &b, const Vec3 &c){
    this->a = a;
    this->b = b;
    this->c = c;
}


Mat3::~Mat3() {}


Mat3 Mat3::dot(const Mat3 &B) const {
    Mat3 ret = Mat3();
    Mat3 trans = B.t();
    ret[0][0] = (*this)[0].dot(B[0]);
    ret[0][1] = (*this)[0].dot(B[1]);
    ret[0][2] = (*this)[0].dot(B[2]);
    ret[1][0] = (*this)[1].dot(B[0]);
    ret[1][1] = (*this)[1].dot(B[1]);
    ret[1][2] = (*this)[1].dot(B[2]);
    ret[2][0] = (*this)[2].dot(B[0]);
    ret[2][1] = (*this)[2].dot(B[1]);
    ret[2][2] = (*this)[2].dot(B[2]);
    return ret;
}


Vec3 Mat3::dot(const Vec3 &u) const {
    return Vec3((*this)[0].dot(u), (*this)[1].dot(u), (*this)[2].dot(u));
}


Mat3 Mat3::t() const {

    Mat3 ted = Mat3();
    ted[0] = Vec3((*this)[0][0], (*this)[1][0], (*this)[2][0]);
    ted[1] = Vec3((*this)[0][1], (*this)[1][1], (*this)[2][1]);
    ted[2] = Vec3((*this)[0][2], (*this)[1][2], (*this)[2][2]);
    return ted;

}


Vec3 Mat3::operator [](int i) const {
    switch (i){
        case 0:
            return this->a;
        case 1:
            return this->b;
        case 2:
            return this->c;
        default:
            std::cout << "Index out of range" << std::endl;
            exit(1);
    }
}

Vec3 & Mat3::operator [](int i) {
    switch (i){
        case 0:
            return this->a;
        case 1:
            return this->b;
        case 2:
            return this->c;
        default:
            std::cout << "Index out of range" << std::endl;
            exit(1);
    }
}


Mat3 operator+(const Mat3 &A, const Mat3 &B){
    Vec3 row1 = A[0] + B[0];
    Vec3 row2 = A[1] + B[1];
    Vec3 row3 = A[2] + B[2];
    return Mat3(row1, row2, row3);
}


Mat3 operator-(const Mat3 &A, const Mat3 &B){
    Vec3 row1 = A[0] - B[0];
    Vec3 row2 = A[1] - B[1];
    Vec3 row3 = A[2] - B[2];
    return Mat3(row1, row2, row3);
}


Mat3 operator*(double scalar, const Mat3 &A){
    Vec3 row1 = A[0] * scalar;
    Vec3 row2 = A[1] * scalar;
    Vec3 row3 = A[2] * scalar;
    return Mat3(row1, row2, row3);
}


Mat3 operator*(const Mat3 &A, double scalar){
    Vec3 row1 = A[0] * scalar;
    Vec3 row2 = A[1] * scalar;
    Vec3 row3 = A[2] * scalar;
    return Mat3(row1, row2, row3);
}


std::ostream& operator<<(std::ostream &out, const Mat3 &u){
    out << u.a << std::endl << u.b << std::endl << u.c;
    return out;
}

Mat3 Mat3::eye(){
    Mat3 identity = Mat3();
    identity[0][0] = 1;
    identity[1][1] = 1;
    identity[2][2] = 1;
    return identity;
}
