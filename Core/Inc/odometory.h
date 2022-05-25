#ifndef ODOMETORY_HPP_
#define ODOMETORY_HPP_

#include "main.h"
#include "hardware/encoder.h"
#include "hardware/imu.h"

namespace undercarriage
{
    class Odometory
    {
    private:
        hardware::Encoder encoder;
        hardware::IMU imu;

        float sampling_period; // [s]

    public:
        Odometory(float sampling_period, float tire_radius, float gyro_factor);

        void Initialize();
        void Update();

        float v;
        float omega;
        float x;
        float y;
        float theta;
    };
} //  namespace undercarriage
#endif //  ODOMETORY_HPP_