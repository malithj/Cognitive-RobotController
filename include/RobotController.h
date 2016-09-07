/**
 * RobotController
 * Copyright (c) Malith Jayaweera
 *
 * Provides an interface to encapsulate Robot Controller function calls .
 * This header file is designed to be includable under C and C++ environment.
 *
 */

#ifndef ROBOTCONTROLLER_H
#define ROBOTCONTROLLER_H

#include "SerialClass.h"
#include <iostream>
#include <string>

#pragma GCC diagnostic ignored "-Wwrite-strings"

class RobotController
{
    public:
        /** Default commands */
        static const int STATIONARY=1;
        static const int FORWARD=2;
        static const int BACKWARD=4;
        static const int UP=8;
        static const int DOWN=16;
        static const int ROTATE_CLOCKWISE=512;
        static const int ROTATE_COUNTERCLOCKWISE=1024;
        static const int GRAB=2048;
        static const int RELEASE=4096;

        /** Default constructor */
        RobotController(Serial* serialObj);
        /** Default destructor */
        virtual ~RobotController();
        /** Set defaults */
        void SetDefaults();
        /** Set Forward */
        void SetForward(char* c);
        /** Set Backward */
        void SetBackward(char* c);
        /** Set Release */
        void SetRelease(char* c);
        /** Set Grab */
        void SetGrab(char* c);
        /** Issue the command to robot */
        void IssueCommand(int number);
        /** Serial Write function */
        void SerialWrite(char* message_to_robot);
        /** Refresh the Serial Connection */
        void setSerialConnection(Serial* serial);
        /** Auxiliary movement using facial expressions */
        void IssueCommand_Aux_Facial(int number);
        /** Auxiliary movement using HeadsetGyro */
        void IssueCommand_Aux_Movement(int number);

    protected:
    private:
        Serial* serial;
        /** Default characters */
         char* neutral;
         char* push;
         char* pull;
         char* up;
         char* down;
         char* moveleft;
         char* moveright;
         char* turnleft;
         char* turnright;
         char* clockwise;
         char* anticlockwise;
         char* rotateforward;
         char* rotatebackward;
         char* vanish;



};

#endif // ROBOTCONTROLLER_H
