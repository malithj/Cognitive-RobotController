#ifndef GYRO_H
#define GYRO_H


class Gyro
{
    public:
        /** Default constructor */
        Gyro(int x, int y);
        /** Default destructor */
        virtual ~Gyro();
        /** getX */
        int GetGyroX();
        /** getY */
        int GetGyroY();
        /** setX */
        void SetGyroX(int x);
        /** setY */
        void SetGyroY(int y);

    protected:
    private:
        int gyroX;
        int gyroY;
};

#endif // GYRO_H
