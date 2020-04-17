#include "Ball.h"
#include <math.h>
#include <iostream>

const double R = 91.25;
const double Y = 2.0;
const double mu = 0.285;
const double C_R = 0.6;
const double A = 0.0003;



// Default constructor
Ball::Ball() {
    this->p = Vec3();
    this->v = Vec3();
    this->w = Vec3();
}

// Overloaded constructor
Ball::Ball(Vec3 p, Vec3 v, Vec3 w) {
    this->p = p;
    this->v = v;
    this->w = w;
}

// Destructor
Ball::~Ball() {}

// Step the ball forward 1 timestep
void Ball::update() {
    this->p = this->p + this->v;
}

//To be called when the ball is touching a surface
void Ball::bounce(Vec3 n) {
    Vec3 v_perp = (this->v.dot(n)) * n;
    Vec3 v_para = this->v - v_perp;
    Vec3 v_spin = R * n.cross(this->w);
    Vec3 s = v_para + v_spin;

    double ratio = v_perp.magnitude() / s.magnitude();

    Vec3 delta_v_perp = (-1.0 - C_R) * v_perp;

    double tomult = - fmin(1.0, Y * ratio) * mu;
    Vec3 delta_v_para = tomult * s;

    this->p = this->p + this->v;
    this->v = this->v + delta_v_perp + delta_v_para;
    this->w = this->w + A * R * delta_v_para.cross(n);

}


Vec3 Ball::getP() {
    return this->p;
}


Vec3 Ball::getV() {
    return this->v;
}

void Ball::print() {
    std::cout << "Position: " << this->p << std::endl << "Velocity: " << this->v << std::endl << "Angular Velocity: " << this->w << std::endl;
}


/*
//helper function for dot products
double Ball::dot(double[3] vec1, double[3] vec2){
    double sum = 0;
    sum += vec1[0] * vec2[0];
    sum += vec1[1] * vec2[1];
    sum += vec1[2] * vec2[2];
    return sum;
}

//helper function for cross products
double * Ball::cross(double[3] vec1, double[3] vec2){
    double product[3];
    product[0] = vec1[1]*vec2[2] - vec1[2]*vec2[1];
    product[1] = vec1[2]*vec2[0] - vec1[0]*vec2[2];
    product[2] = vec1[0]*vec2[1] - vec1[1]*vec2[0];
    return product;
}
*/
