#include "odometory.hpp"

#include <cmath>

Odometory::Odometory(float sampling_period, float tire_radius, float gyro_factor)
    : encoder(float sampling_period, float tire_radius),
      imu(float sampling_period, float gyro_factor),
      sampling_period(sampling_period) {}

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