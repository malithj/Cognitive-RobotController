/***************************************************************
 * Name:      RobotControllerMain.h
 * Purpose:   Defines Application Frame
 * Author:    Malith Jayaweera (malith.12@cse.mrt.ac.lk)
 * Created:   2015-08-12
 * Copyright: Malith Jayaweera ()
 * License:
 **************************************************************/

#ifndef ROBOTCONTROLLERMAIN_H
#define ROBOTCONTROLLERMAIN_H

//(*Headers(RobotControllerFrame)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/tglbtn.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include "wx/KWIC/LinearMeter.h"
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)
#include "Emotiv.h"
#include "RobotController.h"
#include "SerialClass.h"
#include <string>
#include <boost/thread/thread.hpp>

class RobotControllerFrame: public wxFrame
{
    public:

        RobotControllerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~RobotControllerFrame();
        void SetEmotivAccess(Emotiv* emo);
        void SetSerialClass(Serial* serial);
        void SetRobotController(RobotController* robot);


    private:

        //(*Handlers(RobotControllerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnPanel_ConsolePaint(wxPaintEvent& event);
        void OnMenuItem_EEngineSelected(wxCommandEvent& event);
        void OnMenuItem_EComposerSelected(wxCommandEvent& event);
        void OnBtn_forwardClick(wxCommandEvent& event);
        void OnBtn_backwardClick(wxCommandEvent& event);
        void OnBtn_grabClick(wxCommandEvent& event);
        void OnBtn_releaseClick(wxCommandEvent& event);
        void OnMenuItem_COMSelection(wxCommandEvent& event);
        void OnCombo_ComPortSelect(wxCommandEvent& event);
        void OnbtnDefaultClick(wxCommandEvent& event);
        void OnComboBoxForwardSelected(wxCommandEvent& event);
        void OnComboBoxGrabSelected(wxCommandEvent& event);
        void OnComboBoxBackwardSelected(wxCommandEvent& event);
        void OnComboBoxReleaseSelected(wxCommandEvent& event);
        void OnComboBoxForwardTextUpdated(wxCommandEvent& event);
        void OnGyroButtonToggle(wxCommandEvent& event);
        void OnPanel3Paint(wxPaintEvent& event);
        void OnPanel2Paint(wxPaintEvent& event);
        //*)

        //(*Identifiers(RobotControllerFrame)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT14;
        static const long ID_STATICTEXT15;
        static const long ID_STATICTEXT16;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT12;
        static const long ID_TOGGLEBUTTON1;
        static const long ID_PANEL5;
        static const long ID_STATICTEXT10;
        static const long ID_STATICTEXT11;
        static const long ID_STATICTEXT21;
        static const long ID_LINEARMETER1;
        static const long ID_PANEL9;
        static const long ID_STATICTEXT17;
        static const long ID_STATICTEXT18;
        static const long ID_STATICTEXT19;
        static const long ID_STATICTEXT20;
        static const long ID_PANEL10;
        static const long ID_PANEL2;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_PANEL6;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_BUTTON5;
        static const long ID_CHOICE2;
        static const long ID_CHOICE3;
        static const long ID_CHOICE4;
        static const long ID_CHOICE5;
        static const long ID_PANEL8;
        static const long ID_PANEL3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT13;
        static const long ID_PANEL7;
        static const long ID_PANEL4;
        static const long ID_NOTEBOOK1;
        static const long ID_PANEL1;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM4;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(RobotControllerFrame)
        wxPanel* Panel_ConsoleContainer;
        wxStaticText* lblUpTime;
        wxPanel* Panel_CogSuite;
        wxChoice* ComboBoxBackward;
        wxMenuItem* MenuItem_EEngine;
        wxStaticText* lblSetting;
        wxToggleButton* GyroButton;
        wxStaticText* lblCogPower;
        wxPanel* Panel_RobotController;
        wxNotebook* Notebook1;
        wxStaticText* lblExpActionTxt;
        wxMenuItem* MenuItem5;
        wxChoice* ComboBoxGrab;
        wxPanel* Panel_Headset;
        wxStaticText* lblRelease;
        wxMenu* Menu_Output;
        wxMenu* Menu_Input;
        wxPanel* PanelDetection;
        wxPanel* PanelKeySelection;
        wxChoice* ComboBoxRelease;
        wxButton* Btn_forward;
        wxButton* Btn_backward;
        wxStaticText* lblNeutral;
        wxStaticText* lblConcentratedText;
        wxStaticText* lblConcentrate;
        wxPanel* PanelOverride;
        wxStaticText* lblBackwards;
        wxStaticText* lblCogResult;
        kwxLinearMeter* CogMeter;
        wxStaticText* lblExpAction;
        wxMenuItem* MenuItem_EComposer;
        wxStaticText* lblForward;
        wxPanel* PanelUserFeed;
        wxStaticText* lblUpTimeTxt;
        wxChoice* ComboBoxForward;
        wxStaticText* lblSettingTxt;
        wxChoice* Combo_ComPort;
        wxStaticText* lblSignalStrengthTxt;
        wxStaticText* lblComPort;
        wxPanel* Panel_Console;
        wxStaticText* lblStatus;
        wxButton* Btn_grab;
        wxPanel* Panel_main;
        wxStaticText* lblNeutralText;
        wxStatusBar* StatusBar;
        wxStaticText* lblGrab;
        wxButton* btnDefault;
        wxStaticText* lblCogResultTxt;
        wxButton* Btn_release;
        wxStaticText* lblStatusTxt;
        //*)
        Emotiv* emotiv;
        Serial* serial;
        bool GyroData;
        RobotController* robotController;
        bool isConnectedToEmoEngine;
        bool isConnectedToEmoComposer;
        void UpdateUI();
        DECLARE_EVENT_TABLE()
        void DetectComPorts(std::vector< tstring >& ports);   //Detect COM ports connected
        void UpdateComPorts();
        void ChangeSerialConnection();
        void SetPort();
};

#endif // ROBOTCONTROLLERMAIN_H
