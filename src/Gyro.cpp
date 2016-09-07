#include "Gyro.h"

Gyro::Gyro(int x, int y)
{
    //ctor
    gyroX=x;
    gyroY=y;
}

Gyro::~Gyro()
{
    //dtor
}
int Gyro::GetGyroX()
{
    return gyroX;
}

int Gyro::GetGyroY()
{
    return gyroY;
}


void Gyro::SetGyroX(int x)
{
    gyroX = x;
}

void Gyro::SetGyroY(int y)
{
    gyroY = y;
}

