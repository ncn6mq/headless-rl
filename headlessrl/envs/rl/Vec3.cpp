#include "Vec3.h"
#include "Mat3.h"
#include <math.h>

Vec3::Vec3(){
    this->a = 0.0;
    this->b = 0.0;
    this->c = 0.0;
}

Vec3::Vec3(double a, double b, double c){
    this->a = a;
    this->b = b;
    this->c = c;
}

Vec3::Vec3(const Vec3 &u){
    this->a = u.a;
    this->b = u.b;
    this->c = u.c;
}

Vec3::~Vec3() {}

/*
void Vec3::set(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

void Vec3::set(Vec3 u) {
    this->a = u.a;
    this->b = u.b;
    this->c = u.c;
}
*/
Vec3 Vec3::cross(Vec3 u) {
    Vec3 crossed = Vec3();
    crossed.a = this->b*u.c - this->c*u.b;
    crossed.b = this->c*u.a - this->a*u.c;
    crossed.c = this->a*u.b - this->b*u.a;
    return crossed;
}

double Vec3::dot(Vec3 u) {
    double sum = 0;
    sum += this->a * u.a;
    sum += this->b * u.b;
    sum += this->c * u.c;
    return sum;
}

Vec3 Vec3::dot(const Mat3 &B) {
    Mat3 ted = B.t();
    return Vec3(this->dot(ted[0]), this->dot(ted[1]), this->dot(ted[2]));
}

double Vec3::magnitude() {
    double sum = 0;
    sum += this->a * this->a;
    sum += this->b * this->b;
    sum += this->c * this->c;
    return sqrt(sum);
}

Vec3 Vec3::multScalar(double x) {
    Vec3 toret = Vec3();
    toret.a = this->a * x;
    toret.b = this->b * x;
    toret.c = this->c * x;
    return toret;
}

Vec3 Vec3::subtract(Vec3 u) {
    Vec3 toret = Vec3();
    toret.a = this->a - u.a;
    toret.b = this->b - u.b;
    toret.c = this->c - u.c;
    return toret;
}

Vec3 Vec3::add(Vec3 u) {
    Vec3 toret = Vec3();
    toret.a = this->a + u.a;
    toret.b = this->b + u.b;
    toret.c = this->c + u.c;
    return toret;
}

double Vec3::operator [](int i) const {
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

double & Vec3::operator [](int i) {
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

Vec3 operator+(const Vec3 &u, const Vec3 &v){
    Vec3 ret = Vec3(u);
    ret.a += v.a;
    ret.b += v.b;
    ret.c += v.c;
    return ret;
}

Vec3 operator-(const Vec3 &u, const Vec3 &v){
    Vec3 ret = Vec3(u);
    ret.a -= v.a;
    ret.b -= v.b;
    ret.c -= v.c;
    return ret;
}

Vec3 operator*(double scalar, const Vec3 &u){
    Vec3 ret = Vec3(u);
    ret.a *= scalar;
    ret.b *= scalar;
    ret.c *= scalar;
    return ret;
}

Vec3 operator*(const Vec3 &u, double scalar){
    Vec3 ret = Vec3(u);
    ret.a *= scalar;
    ret.b *= scalar;
    ret.c *= scalar;
    return ret;
}

std::ostream& operator<<(std::ostream &out, const Vec3 &u){
    out << u.a << " " << u.b << " " << u.c;
    return out;
}


void Vec3::print() {
    std::cout << this->a << " " << this->b << " " << this->c << std::endl;
}
