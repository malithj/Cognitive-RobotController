/**
 * RobotController
 * Copyright (c) Malith Jayaweera
 *
 * Provides an Implementation of Robot Controller function calls .
 * This header file is designed to be includable under C and C++ environment.
 *
 */

#include "RobotController.h"

RobotController::RobotController(Serial* serialObj)
{
    //ctor
    //std::wstring com = L"\\\\.\\COM11";
    //new	Serial(com);
    serial = serialObj;
    SetDefaults();
}

RobotController::~RobotController()
{
    //dtor
}

void RobotController::SetDefaults(){
   /** Default characters */
        neutral="n";
        push="p";
        pull="m";
        up="u";
        down="d";
        moveleft="l";
        moveright="r";
        turnleft="t";
        turnright="o";
        clockwise="c";
        anticlockwise="a";
        rotateforward="f";
        rotatebackward="b";
        vanish="v";
}
void RobotController::SetForward(char* c)
{
    push =c;
}

void RobotController::SetBackward(char* c)
{
    pull=c;
}

void RobotController::SetRelease(char* c)
{
    rotatebackward=c;
}

void RobotController::SetGrab(char* c)
{
    rotateforward=c;
}


void RobotController::IssueCommand(int number)
{
    switch(number){

    case 1:
        serial->WriteData(neutral,1);
        break;
         //neutral

    case 2:
        serial->WriteData(push,1);
        break;
        //push

    case 4:
        serial->WriteData(pull,1);
        break;
         //towards my direction

    case 8:
        serial->WriteData(up,1);
        break;//up

    case 16:
        serial->WriteData(down,1);
        break;//drop

    case 32:
        serial->WriteData(moveleft,1);
        break;//move left

    case 64:
        serial->WriteData(moveright,1);
        break;//move right

    case 128:
        serial->WriteData(turnleft,1);
        break;//turn left

    case 256:
        serial->WriteData(turnright,1);
        break;//turn other way

    case 512:
        serial->WriteData(clockwise,1);
        break;//turn clockwise

    case 1024:
        serial->WriteData(anticlockwise,1);
        break;//turn anti clockwise

    case 2048:
        serial->WriteData(rotateforward,1);
        break;//rotate forward

    case 4096:
        serial->WriteData(rotatebackward,1);
        break;//rotate backwards

    case 8192:
        serial->WriteData(vanish,1);
        break;//vanish

    default:
        serial->WriteData(neutral,1);

    }
}

void RobotController::IssueCommand_Aux_Facial(int number)
{
    switch(number){
    case 1:
        serial->WriteData(rotateforward,1);
        break;

    case 0:
        serial->WriteData(neutral,1);
        break;

    default:
        break;

    }

}

void RobotController::IssueCommand_Aux_Movement(int number)
{
    switch(number){
    case 1:
        serial->WriteData(up,1);
        break;

    case 0:
        serial->WriteData(down,1);
        break;

    default:
        break;
    }

}

void RobotController::setSerialConnection(Serial* serialobj){
    serial=serialobj;
}

