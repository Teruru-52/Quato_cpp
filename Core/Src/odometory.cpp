#include "odometory.h"

#include <cmath>

namespace undercarriage
{
  Odometory::Odometory(float sampling_period, float tire_radius, float gyro_factor)
      : encoder(sampling_period, tire_radius),
        imu(sampling_period, gyro_factor),
        sampling_period(sampling_period),
        x(0),
        y(0) {}

  void Odometory::Initialize()
  {
    imu.Initialize();
    imu.CalcOffset();
  }

  void Odometory::Update()
  {
    encoder.Update();
    imu.Update();

    v = encoder.GetVelocity();
    omega = imu.GetAngularVelocity();
    theta = imu.GetAngle();
    x += v * cos(theta) * sampling_period;
    y += v * sin(theta) * sampling_period;
  }
} //  namespace undercarriage