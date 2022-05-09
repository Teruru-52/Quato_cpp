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

    float v;
    float omega;
    static float x = 0;
    static float y = 0;
    float theta;

private:
    hardware::Encoder encoder;
    hardware::IMU imu;

    float sampling_period; // [s]
};
#endif //  ODOMETORY_HPP_