/**
 * Emotiv API
 * Copyright (c) Malith Jayaweera
 *
 * Provides an implementation of Emotiv API function calls .
 * None of the API functions are thread-safe.
 * This header file is designed to be includable under C and C++ environment.
 *
 */


#include "Emotiv.h"
#include <sstream>


Emotiv::Emotiv()
{
    //ctor
    userID=0;
    state=0;
    previousGyroX=0;
    previousGyroY=0;
    eEvent	= EE_EmoEngineEventCreate();
	eState	= EE_EmoStateCreate();

}

Emotiv::~Emotiv()
{
    //dtor
    EE_EngineDisconnect();
	EE_EmoStateFree(eState);
	EE_EmoEngineEventFree(eEvent);
}

bool Emotiv::ConnectToEmoEngine()
{
    if (EE_EngineConnect() != EDK_OK) {
        if(EE_EngineRemoteConnect("127.0.0.1", CONTROL_PANEL_PORT)!=EDK_OK){
                    return false;
        }
        else{
                Connected = true;
                return true;
        }
    }
    else{
        Connected=true;
        return true;
    }
}

bool Emotiv::ConnectToEmoComposer()
{
    std::string input = std::string("127.0.0.1");
    if (EE_EngineRemoteConnect(input.c_str(), composerPort) != EDK_OK) {
            std::string errMsg = "Cannot connect to EmoComposer on ["+ input + "]";
            return false;
    }
    else{
        Connected = true;
        return true;
    }
}


bool Emotiv::TerminateExecution()
{
    return true;
}

void Emotiv::GetExpressivSuiteData()
{
    ES_ExpressivIsBlink(eState);
	ES_ExpressivIsLeftWink(eState);
	ES_ExpressivIsRightWink(eState);
    ES_ExpressivIsLookingLeft(eState);
    ES_ExpressivIsLookingRight(eState);

	std::map<EE_ExpressivAlgo_t, float> expressivStates;

	EE_ExpressivAlgo_t upperFaceAction = ES_ExpressivGetUpperFaceAction(eState);
	float			   upperFacePower  = ES_ExpressivGetUpperFaceActionPower(eState);

	EE_ExpressivAlgo_t lowerFaceAction = ES_ExpressivGetLowerFaceAction(eState);
	float			   lowerFacePower  = ES_ExpressivGetLowerFaceActionPower(eState);

	expressivStates[ upperFaceAction ] = upperFacePower;
	expressivStates[ lowerFaceAction ] = lowerFacePower;

    expressivStates[ EXP_EYEBROW     ]; // eyebrow
	expressivStates[ EXP_FURROW      ]; // furrow
	expressivStates[ EXP_SMILE       ]; // smile
	expressivStates[ EXP_CLENCH      ]; // clench
	expressivStates[ EXP_SMIRK_LEFT  ]; // smirk left
	expressivStates[ EXP_SMIRK_RIGHT ]; // smirk right
	expressivStates[ EXP_LAUGH       ]; // laugh

}

void Emotiv::GetCognitivSuiteData()
{
    static_cast<int>(ES_CognitivGetCurrentAction(eState));
	ES_CognitivGetCurrentActionPower(eState);
}

void Emotiv::GetAffectivSuiteData()
{
    ES_AffectivGetExcitementShortTermScore(eState);
    ES_AffectivGetExcitementLongTermScore(eState);
	ES_AffectivGetEngagementBoredomScore(eState);

}

int Emotiv::GetSensorData()
{
    return static_cast<int>(ES_GetWirelessSignalStatus(eState));
}

char const* Emotiv::cognitiveDecode(int number){
    switch(number){
    case 1:
        return "Neutral";       //neutral

    case 2:
        return "Push";          //push

    case 4:
        return "Pull";          //towards my direction

    case 8:
        return "Lift";          //up

    case 16:
        return "Drop";          //drop

    case 32:
        return "Left";          //move left

    case 64:
        return "Right";         //move right

    case 128:
        return "Rotate Left";  //turn left

    case 256:
        return "Rotate Right";  //turn other way

    case 512:
        return "Rotate Clockwise"; //turn clockwise

    case 1024:
        return "Rotate Counterclockwise";  //turn anti clockwise

    case 2048:
        return "Rotate Forward"; //rotate forward

    case 4096:
        return "Rotate Reverse"; //rotate backwards

    case 8192:
        return "Dissapear";  //vanish

    default:
        return "Unknown";

    }
}

std::string* Emotiv::getHeadsetData(){
    std::stringstream ss1,ss2,ss3,ss4,ss5,ss6;
    std::string* value = new std::string[6];
    //Initialize the values array to null
    value[0]="";
    value[1]="";
    value[2]="1";
    value[3]="";
    value[4]="";
    value[5]="";

    //get the values from the Engine
    state = EE_EngineGetNextEvent(eEvent);

			// New event needs to be handled
			if (state == EDK_OK) {
				EE_Event_t eventType = EE_EmoEngineEventGetType(eEvent);

				// Log the EmoState if it has been updated
				if (eventType == EE_EmoStateUpdated) {
					EE_EmoEngineEventGetEmoState(eEvent, eState);
					ss1 << (ES_GetTimeFromStart(eState));
					value[0] = ss1.str();
					int temp=static_cast<int>(ES_CognitivGetCurrentAction(eState));
					ss2 << cognitiveDecode(temp);
					value[1] = ss2.str();
					ss3 << temp;
					value[2] = ss3.str();
					ss4 << getExpressiveAction();
					value[3] = ss4.str();
					ss5 << getHeadsetMovement();
					value[4] = ss5.str();
					ss6 << ES_CognitivGetCurrentActionPower(eState);
					value[5] = ss6.str();
					return value;
				}
			}
            return value;
}



void Emotiv::logEmoState(std::ostream& os, unsigned int userID, EmoStateHandle eState, bool withHeader)
{
    // Create the top header
	if (withHeader) {
		os << "Time,";
		os << "UserID,";
		os << "Wireless Signal Status,";
		os << "Blink,";
		os << "Wink Left,";
		os << "Wink Right,";
		os << "Look Left,";
		os << "Look Right,";
		os << "Eyebrow,";
		os << "Furrow,";
		os << "Smile,";
		os << "Clench,";
		os << "Smirk Left,";
		os << "Smirk Right,";
		os << "Laugh,";
		os << "Short Term Excitement,";
		os << "Long Term Excitement,";
		os << "Engagement/Boredom,";
		os << "Cognitiv Action,";
		os << "Cognitiv Power,";
		os << std::endl;
	}

	// Log the time stamp and user ID
	os << ES_GetTimeFromStart(eState) << ",";
	os << userID << ",";
	os << static_cast<int>(ES_GetWirelessSignalStatus(eState)) << ",";

	// Expressiv Suite results
	os << ES_ExpressivIsBlink(eState) << ",";
	os << ES_ExpressivIsLeftWink(eState) << ",";
	os << ES_ExpressivIsRightWink(eState) << ",";

	os << ES_ExpressivIsLookingLeft(eState) << ",";
	os << ES_ExpressivIsLookingRight(eState) << ",";

	std::map<EE_ExpressivAlgo_t, float> expressivStates;

	EE_ExpressivAlgo_t upperFaceAction = ES_ExpressivGetUpperFaceAction(eState);
	float			   upperFacePower  = ES_ExpressivGetUpperFaceActionPower(eState);

	EE_ExpressivAlgo_t lowerFaceAction = ES_ExpressivGetLowerFaceAction(eState);
	float			   lowerFacePower  = ES_ExpressivGetLowerFaceActionPower(eState);

	expressivStates[ upperFaceAction ] = upperFacePower;
	expressivStates[ lowerFaceAction ] = lowerFacePower;

	os << expressivStates[ EXP_EYEBROW     ] << ","; // eyebrow
	os << expressivStates[ EXP_FURROW      ] << ","; // furrow
	os << expressivStates[ EXP_SMILE       ] << ","; // smile
	os << expressivStates[ EXP_CLENCH      ] << ","; // clench
	os << expressivStates[ EXP_SMIRK_LEFT  ] << ","; // smirk left
	os << expressivStates[ EXP_SMIRK_RIGHT ] << ","; // smirk right
	os << expressivStates[ EXP_LAUGH       ] << ","; // laugh

	// Affectiv Suite results
	os << ES_AffectivGetExcitementShortTermScore(eState) << ",";
	os << ES_AffectivGetExcitementLongTermScore(eState) << ",";

	os << ES_AffectivGetEngagementBoredomScore(eState) << ",";

	// Cognitiv Suite results
	os << static_cast<int>(ES_CognitivGetCurrentAction(eState)) << ",";
	os << ES_CognitivGetCurrentActionPower(eState);

	os << std::endl;
}

int Emotiv::getCognitiveAction()
{
    return static_cast<int>(ES_CognitivGetCurrentAction(eState));
}

int Emotiv::getExpressiveAction()
{
    std::map<EE_ExpressivAlgo_t, float> expressivStates;
    EE_ExpressivAlgo_t upperFaceAction = ES_ExpressivGetUpperFaceAction(eState);
	float			   upperFacePower  = ES_ExpressivGetUpperFaceActionPower(eState);

	EE_ExpressivAlgo_t lowerFaceAction = ES_ExpressivGetLowerFaceAction(eState);
	float			   lowerFacePower  = ES_ExpressivGetLowerFaceActionPower(eState);

	expressivStates[ upperFaceAction ] = upperFacePower;
	expressivStates[ lowerFaceAction ] = lowerFacePower;
    return static_cast<int>(expressivStates[EXP_CLENCH]);
}

int Emotiv::getHeadsetMovement()
{
     //gyro Data
    int gyroX, gyroY;
    EE_HeadsetGetGyroDelta(0,&gyroX,&gyroY);
    if(gyroY<0){
        return 1;
    }
    else if(gyroY>0){
        return 0;
    }
    else{
        return -1;
    }
}
