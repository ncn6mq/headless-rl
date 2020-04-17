#ifndef BALL_H
#define BALL_H
#include "Vec3.h"

class Vec3;

class Ball {
    public:
        Ball();
        Ball(Vec3 p, Vec3 v, Vec3 w);
        ~Ball();


        void update();
        Vec3 getP();
        Vec3 getV();
        void print();
        void bounce(Vec3 n);


    private:
        Vec3 p;
        Vec3 v;
        Vec3 w;
};


#endif
