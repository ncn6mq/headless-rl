#import "Car.h"

const double omega_max = 5.5;
const double T_r = -36.07956616966136; // torque coefficient for roll
const double T_p = -12.14599781908070; // torque coefficient for pitch
const double T_y =   8.91962804287785; // torque coefficient for yaw
const double D_r =  -4.47166302201591; // drag coefficient for roll
const double D_p = -2.798194258050845; // drag coefficient for pitch
const double D_y = -1.886491900437232; // drag coefficient for yaw

const Mat3 T = Mat3(
    Vec3(T_r, 0.0, 0.0),
    Vec3(0.0, T_p, 0.0),
    Vec3(0.0, 0.0, T_y)
);

Car::Car(){
    this->p = Vec3();
    this->v = Vec3();
    this->a = Vec3();
    this->w = Vec3();
    this->theta = Mat3::eye();
}

Car::~Car(){}

void Car::aerialUpdate(double roll, double pitch, double yaw, double dt) {



    Mat3 D = Mat3(
        Vec3(D_r, 0.0, 0.0),
        Vec3(0.0, D_p * (1.0 - fabs(pitch)), 0.0),
        Vec3(0.0, 0.0, D_y * (1.0 - fabs(yaw)))
    );

  // compute the net torque on the car
  Vec3 tau = D.dot((this->theta.t()).dot(this->w));

  //if(roll == 0.0 && pitch == 0.0 && yaw == 0.0){
  //    Vec3 omega_next = this->w + tau * dt;

  tau = tau + T.dot(Vec3(roll, pitch, yaw));
  tau = this->theta.dot(tau);

  // use the torque to get the update angular velocity
  Vec3 omega_next = this->w + tau * dt;

  // prevent the angular velocity from exceeding a threshold
  omega_next = omega_next * fmin(1.0, omega_max / this->w.magnitude());

  // compute the average angular velocity for this step
  Vec3 omega_avg = 0.5 * (this->w + omega_next);
  double phi = omega_avg.magnitude() * dt;

  std::cout << omega_avg << std::endl;

  Mat3 Omega_dt = Mat3(
    Vec3(0.0, -omega_avg[2] * dt, omega_avg[1] * dt),
    Vec3(omega_avg[2] * dt, 0.0, -omega_avg[0] * dt),
    Vec3(-omega_avg[1] * dt, omega_avg[0] * dt, 0.0)
  );

  Mat3 R = Mat3::eye();


  R = R + (sin(phi) / phi) * Omega_dt;

  R = R + ((1.0 - cos(phi) / (phi*phi)) * Omega_dt.dot(Omega_dt));



  this->w = omega_next;

  Mat3 almostTheta = R.dot(this->theta);

  almostTheta = almostTheta.t();
  almostTheta[0] = almostTheta[0] *(1/almostTheta[0].magnitude());
  almostTheta[1] = almostTheta[1] *(1/almostTheta[1].magnitude());
  almostTheta[2] = almostTheta[2] *(1/almostTheta[2].magnitude());

  std::cout << almostTheta.t() << '\n';

 // this->theta = almostTheta.t();

  this->theta = R.dot(this->theta);
  std::cout << this->theta << '\n';
  std::cout << '\n';

}


void Car::print() {
    std::cout << this->p << std::endl << this->theta << std::endl;
}


Mat3 Car::convertAngles(double roll, double yaw, double pitch){
    double CR = cos(roll);
    double SR = sin(roll);
    double CY = cos(yaw);
    double SY = sin(yaw);
    double CP = cos(pitch);
    double SP = sin(pitch);

    Mat3 theta = Mat3();

    // front direction
    theta[0][0] = CP * CY;
    theta[1][0] = CP * SY;
    theta[2][0] = SP;

    // left direction
    theta[0][1] = CY * SP * SR - CR * SY;
    theta[1][1] = SY * SP * SR + CR * CY;
    theta[2][1] = -CP * SR;

    // up direction
    theta[0][2] = -CR * CY * SP - SR * SY;
    theta[1][2] = -CR * SY * SP + SR * CY;
    theta[2][2] = CP * CR;

    return theta;
}
