#ifndef CAR_H
#define CAR_H
#import <iostream>
#import <math.h>
#import "Vec3.h"
#import "Mat3.h"


class Car {
    public:
        Car();
        ~Car();
        void aerialUpdate(double roll, double pitch, double yaw, double dt);
        void print();
        static Mat3 convertAngles(double roll, double yaw, double pitch);

    private:
        Vec3 p;
        Vec3 v;
        Vec3 a;
        Vec3 w;
        Mat3 theta;

};

#endif
