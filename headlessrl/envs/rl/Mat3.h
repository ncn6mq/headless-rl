#ifndef MAT_H
#define MAT_H

#include "Vec3.h"
#include <iostream>


class Mat3 {
    public:
        Mat3();
        Mat3(const Vec3 &a, const Vec3 &b, const Vec3 &c);
        ~Mat3();

        Mat3 dot(const Mat3 &B) const;
        Vec3 dot(const Vec3 &u) const;
        Mat3 t() const;

        friend Mat3 operator+(const Mat3 &A, const Mat3 &B);
        friend Mat3 operator-(const Mat3 &A, const Mat3 &B);

        friend Mat3 operator*(double scalar, const Mat3 &A);
        friend Mat3 operator*(const Mat3 &A, double scalar);

        friend std::ostream& operator<<(std::ostream &out, const Mat3 &u);

        //todo: create print function, equals, and [] overload
        Vec3 operator [](int i) const;
        Vec3 & operator [](int i);

        static Mat3 eye();


    private:
        Vec3 a;
        Vec3 b;
        Vec3 c;

};

#endif
