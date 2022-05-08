#ifndef HARDWARE_IMU_HPP_
#define HARDWARE_IMU_HPP_

class IMU
{
public:
    IMU(float sampling_period, float gyro_factor);

    uint8_t read_byte(uint8_t reg);
    void write_byte(uint8_t reg, uint8_t data);

    void Initialize();
    void CalcOffset();
    void Update();
    void UpdateGyro();
    void UpdateAcc();
    float GetAngle();
    float GetAngularVelocity();

private:
    float sampling_period;
    float gyro_factor;

    static float theta = 0;
    float gyro_z;
    static float offset_gz = 0;
};
#endif // HARDWARE_IMU_HPP_