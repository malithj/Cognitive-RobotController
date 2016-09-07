/**
 * Emotiv API
 * Copyright (c) Malith Jayaweera
 *
 * Provides an interface to encapsulate Emotiv API function calls .
 * None of the API functions are thread-safe.
 * This header file is designed to be includable under C and C++ environment.
 *
 */


#ifndef EMOTIV_H
#define EMOTIV_H

#include <cstdlib>
#include <string>
#include <stdio.h>
#include <iostream>
#include <map>
#include <stdexcept>

#include "EmoStateDLL.h"
#include "edk.h"
#include "edkErrorCode.h"


class Emotiv
{
    public:
        /** Default constructor */
        Emotiv();
        /** Default destructor */
        virtual ~Emotiv();
        /** Access Headset Data  */
        bool ConnectToEmoEngine();
        /** Access Emulator Data */
        bool ConnectToEmoComposer();
        /** Terminate Connections */
        bool TerminateExecution();
        /** ExpressivSuite */
        void GetExpressivSuiteData();
        /** CognitivSuite */
        void GetCognitivSuiteData();
        /** AffectivSuite */
        void GetAffectivSuiteData();
        /** Access Sensor Data */
        int GetSensorData();
        /** Decode Cognitive Action */
        char const* cognitiveDecode(int number);
        /** Log data to log.txt */
        void logEmoState(std::ostream& os, unsigned int userID,EmoStateHandle eState, bool withHeader);
        /** get cognitive action */
        int getCognitiveAction();
        /** get expressive action */
        int getExpressiveAction();
        /** get up time */
        std::string* getHeadsetData();
        /** Headset Movement */
        int getHeadsetMovement();

    protected:
    private:
        bool Connected;
        EmoEngineEventHandle eEvent;
        EmoStateHandle eState;
        int state;
        int previousGyroX;       //last updated gyro Value X Axis
        int previousGyroY;       //last updated gyro Value Y Axis
        unsigned int userID;
	    static const unsigned short composerPort =1726;
        static const int CONTROL_PANEL_PORT=3008;
};

#endif // EMOTIV_H
