#include "Ball.h"
#include "Vec3.h"
#include <iostream>
#include <math.h>
#include "Mat3.h"
#include "Car.h"

const double dt = 1;

int main() {
    Car car = Car();
    car.aerialUpdate(1, 0, 0, dt);
    car.convertAngles()
    car.aerialUpdate(0, 0, 0, dt);
    car.aerialUpdate(0, 0, 0, dt);
    return(0);
}

/*
int main() {
    Vec3 startP = Vec3(0, 0 ,0);
    Vec3 startV = Vec3(409.6, 0, 0);
    Vec3 startW = Vec3(0, 0 ,0);
    Ball ball = Ball(startP, startV, startW);

    Vec3 normal = Vec3(-5, 0, 0);
    for(int i = 0; i < 13; i++){
        ball.print();
        ball.update();
        if (i == 9){
            ball.bounce(normal);
        }
        cout << std::endl;
    }

    return 0;
}
*/
