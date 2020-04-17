#ifndef VEC_H
#define VEC_H

#include <iostream>
//#include "Mat3.h"

class Mat3;

class Vec3 {
    public:
        Vec3();
        Vec3(double a, double b, double c);
        Vec3(const Vec3 &u);
        ~Vec3();

        double a;
        double b;
        double c;

//        void set(double a, double b, double c);
//        void set(Vec3 u);
        Vec3 cross(Vec3 u);
        double dot(Vec3 u);
        Vec3 dot(const Mat3 &B);
        double magnitude();

        //see if you can overload operators for these
        Vec3 multScalar(double x);
        Vec3 subtract(Vec3 u);
        Vec3 add(Vec3 u);

        friend Vec3 operator+(const Vec3 &u, const Vec3 &v);
        friend Vec3 operator-(const Vec3 &u, const Vec3 &v);

        friend Vec3 operator*(double scalar, const Vec3 &u);
        friend Vec3 operator*(const Vec3 &u, double scalar);

        friend std::ostream& operator<<(std::ostream &out, const Vec3 &u);

        //todo: create print function, equals, and [] overload
        double operator [](int i) const;
        double & operator [](int i);

        void print();
};

#endif
