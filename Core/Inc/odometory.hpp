#ifndef ODOMETORY_HPP_
#define ODOMETORY_HPP_

#include "main.h"
#include "hardware/encoder.hpp"
#include "hardware/imu.hpp"

class Odometory
{
public:
    Odometory(float sampling_period, float tire_radius, float gyro_factor);

    void Update();

private:
    hardware::Encoder encoder;
    hardware::IMU imu;

    float v;
    float omega;
    float x;
    float y;
    float theta;
};
#endif //  ODOMETORY_HPP_