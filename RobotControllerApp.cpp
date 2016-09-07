/***************************************************************
 * Name:      RobotControllerApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Malith Jayaweera (malith.12@cse.mrt.ac.lk)
 * Created:   2015-08-12
 * Copyright: Malith Jayaweera ()
 * License:
 **************************************************************/
#include "SerialClass.h"
#include "Emotiv.h"
#include "RobotController.h"
#include "wx_pch.h"
#include "RobotControllerApp.h"
#include <wx/icon.h>

//(*AppHeaders
#include "RobotControllerMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(RobotControllerApp);

bool RobotControllerApp::OnInit()
{
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	RobotControllerFrame* Frame = new RobotControllerFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }

    return wxsOK;

}
