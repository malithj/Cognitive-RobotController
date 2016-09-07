/***************************************************************
 * Name:      RobotControllerMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Malith Jayaweera (malith.12@cse.mrt.ac.lk)
 * Created:   2015-08-12
 * Copyright: Malith Jayaweera (c)
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "RobotControllerMain.h"
#include <wx/msgdlg.h>
#include <string>
#include <sstream>

//(*InternalHeaders(RobotControllerFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(RobotControllerFrame)
const long RobotControllerFrame::ID_STATICTEXT1 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT2 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT3 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT9 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT14 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT15 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT16 = wxNewId();
const long RobotControllerFrame::ID_CHOICE1 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT12 = wxNewId();
const long RobotControllerFrame::ID_TOGGLEBUTTON1 = wxNewId();
const long RobotControllerFrame::ID_PANEL5 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT10 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT11 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT21 = wxNewId();
const long RobotControllerFrame::ID_LINEARMETER1 = wxNewId();
const long RobotControllerFrame::ID_PANEL9 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT17 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT18 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT19 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT20 = wxNewId();
const long RobotControllerFrame::ID_PANEL10 = wxNewId();
const long RobotControllerFrame::ID_PANEL2 = wxNewId();
const long RobotControllerFrame::ID_BUTTON1 = wxNewId();
const long RobotControllerFrame::ID_BUTTON2 = wxNewId();
const long RobotControllerFrame::ID_BUTTON3 = wxNewId();
const long RobotControllerFrame::ID_BUTTON4 = wxNewId();
const long RobotControllerFrame::ID_PANEL6 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT5 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT6 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT7 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT8 = wxNewId();
const long RobotControllerFrame::ID_BUTTON5 = wxNewId();
const long RobotControllerFrame::ID_CHOICE2 = wxNewId();
const long RobotControllerFrame::ID_CHOICE3 = wxNewId();
const long RobotControllerFrame::ID_CHOICE4 = wxNewId();
const long RobotControllerFrame::ID_CHOICE5 = wxNewId();
const long RobotControllerFrame::ID_PANEL8 = wxNewId();
const long RobotControllerFrame::ID_PANEL3 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT4 = wxNewId();
const long RobotControllerFrame::ID_STATICTEXT13 = wxNewId();
const long RobotControllerFrame::ID_PANEL7 = wxNewId();
const long RobotControllerFrame::ID_PANEL4 = wxNewId();
const long RobotControllerFrame::ID_NOTEBOOK1 = wxNewId();
const long RobotControllerFrame::ID_PANEL1 = wxNewId();
const long RobotControllerFrame::ID_MENUITEM1 = wxNewId();
const long RobotControllerFrame::ID_MENUITEM2 = wxNewId();
const long RobotControllerFrame::ID_MENUITEM3 = wxNewId();
const long RobotControllerFrame::ID_MENUITEM4 = wxNewId();
const long RobotControllerFrame::idMenuAbout = wxNewId();
const long RobotControllerFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(RobotControllerFrame,wxFrame)
    //(*EventTable(RobotControllerFrame)
    //*)
END_EVENT_TABLE()

RobotControllerFrame::RobotControllerFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(RobotControllerFrame)
    wxStaticBoxSizer* StaticBoxSizer_Detection;
    wxStaticBoxSizer* StaticBoxSizer_EmotivCenter;
    wxStaticBoxSizer* StaticBoxSizer_Automated;
    wxStaticBoxSizer* StaticBoxSizer_Animation;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer_Manual;
    wxMenu* Menu_App;
    wxMenuItem* MenuItem1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer_Console;
    wxMenu* Menu2;
    wxMenuBar* MenuBar;
    wxBoxSizer* BoxSizer_EmotivCenter;

    Create(parent, wxID_ANY, _("Robot Controller"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(664,398));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("D:\\Programmer\\Code Blocks\\UX\\RobotController\\images\\robot.png"))));
    	SetIcon(FrameIcon);
    }
    Panel_main = new wxPanel(this, ID_PANEL1, wxPoint(288,112), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer_EmotivCenter = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer_EmotivCenter = new wxStaticBoxSizer(wxHORIZONTAL, Panel_main, _("Emotiv EPOC Headset"));
    Panel_Headset = new wxPanel(Panel_main, ID_PANEL5, wxDefaultPosition, wxSize(634,117), wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    lblStatus = new wxStaticText(Panel_Headset, ID_STATICTEXT1, _("STATUS"), wxPoint(8,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont lblStatusFont(8,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    lblStatus->SetFont(lblStatusFont);
    lblSetting = new wxStaticText(Panel_Headset, ID_STATICTEXT2, _("SETTING"), wxPoint(8,32), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont lblSettingFont(8,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    lblSetting->SetFont(lblSettingFont);
    lblUpTime = new wxStaticText(Panel_Headset, ID_STATICTEXT3, _("UP TIME"), wxPoint(8,56), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont lblUpTimeFont(8,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    lblUpTime->SetFont(lblUpTimeFont);
    lblStatusTxt = new wxStaticText(Panel_Headset, ID_STATICTEXT9, _("Engine Faliure"), wxPoint(120,8), wxSize(64,13), 0, _T("ID_STATICTEXT9"));
    wxFont lblStatusTxtFont(9,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Consolas"),wxFONTENCODING_DEFAULT);
    lblStatusTxt->SetFont(lblStatusTxtFont);
    lblSettingTxt = new wxStaticText(Panel_Headset, ID_STATICTEXT14, _("Emo Engine"), wxPoint(120,32), wxSize(96,13), 0, _T("ID_STATICTEXT14"));
    wxFont lblSettingTxtFont(8,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    lblSettingTxt->SetFont(lblSettingTxtFont);
    lblUpTimeTxt = new wxStaticText(Panel_Headset, ID_STATICTEXT15, wxEmptyString, wxPoint(120,56), wxSize(96,13), 0, _T("ID_STATICTEXT15"));
    lblSignalStrengthTxt = new wxStaticText(Panel_Headset, ID_STATICTEXT16, wxEmptyString, wxPoint(120,80), wxSize(96,13), 0, _T("ID_STATICTEXT16"));
    Combo_ComPort = new wxChoice(Panel_Headset, ID_CHOICE1, wxPoint(512,8), wxSize(66,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Combo_ComPort->SetSelection( Combo_ComPort->Append(_("COM1")) );
    lblComPort = new wxStaticText(Panel_Headset, ID_STATICTEXT12, _("COM PORT"), wxPoint(432,8), wxSize(58,24), 0, _T("ID_STATICTEXT12"));
    wxFont lblComPortFont(8,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    lblComPort->SetFont(lblComPortFont);
    GyroButton = new wxToggleButton(Panel_Headset, ID_TOGGLEBUTTON1, _("GYRO ON"), wxPoint(432,40), wxSize(144,23), 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
    StaticBoxSizer_EmotivCenter->Add(Panel_Headset, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer_EmotivCenter->Add(StaticBoxSizer_EmotivCenter, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Notebook1 = new wxNotebook(Panel_main, ID_NOTEBOOK1, wxDefaultPosition, wxSize(619,173), 0, _T("ID_NOTEBOOK1"));
    Panel_CogSuite = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer_Detection = new wxStaticBoxSizer(wxHORIZONTAL, Panel_CogSuite, _("Detection"));
    PanelDetection = new wxPanel(Panel_CogSuite, ID_PANEL9, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL9"));
    lblCogResult = new wxStaticText(PanelDetection, ID_STATICTEXT10, _("Cognitive Result"), wxPoint(16,24), wxSize(40,16), 0, _T("ID_STATICTEXT10"));
    wxFont lblCogResultFont(8,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    lblCogResult->SetFont(lblCogResultFont);
    lblCogResultTxt = new wxStaticText(PanelDetection, ID_STATICTEXT11, wxEmptyString, wxPoint(144,24), wxSize(104,13), 0, _T("ID_STATICTEXT11"));
    lblCogPower = new wxStaticText(PanelDetection, ID_STATICTEXT21, _("Cognitive Power"), wxPoint(16,64), wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    wxFont lblCogPowerFont(8,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    lblCogPower->SetFont(lblCogPowerFont);
    CogMeter = new kwxLinearMeter(PanelDetection,ID_LINEARMETER1,wxPoint(136,64),wxSize(112,16));
    CogMeter->ShowCurrent(false);
    CogMeter->ShowLimits(false);
    CogMeter->SetActiveBarColour(wxColour(160,132,35));
    CogMeter->SetPassiveBarColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
    CogMeter->SetBorderColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNSHADOW));
    CogMeter->SetTxtValueColour(wxColour(0,0,0));
    CogMeter->SetTagsColour(wxColour(0,0,160));
    StaticBoxSizer_Detection->Add(PanelDetection, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer_Detection, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer_Animation = new wxStaticBoxSizer(wxHORIZONTAL, Panel_CogSuite, wxEmptyString);
    PanelUserFeed = new wxPanel(Panel_CogSuite, ID_PANEL10, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL10"));
    lblNeutral = new wxStaticText(PanelUserFeed, ID_STATICTEXT17, wxEmptyString, wxPoint(32,56), wxSize(96,40), wxSIMPLE_BORDER, _T("ID_STATICTEXT17"));
    lblConcentrate = new wxStaticText(PanelUserFeed, ID_STATICTEXT18, wxEmptyString, wxPoint(160,56), wxSize(96,40), wxSIMPLE_BORDER, _T("ID_STATICTEXT18"));
    lblNeutralText = new wxStaticText(PanelUserFeed, ID_STATICTEXT19, _("Relaxation"), wxPoint(48,24), wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    wxFont lblNeutralTextFont(8,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    lblNeutralText->SetFont(lblNeutralTextFont);
    lblConcentratedText = new wxStaticText(PanelUserFeed, ID_STATICTEXT20, _("Concentration"), wxPoint(168,24), wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    wxFont lblConcentratedTextFont(8,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,_T("Tahoma"),wxFONTENCODING_DEFAULT);
    lblConcentratedText->SetFont(lblConcentratedTextFont);
    StaticBoxSizer_Animation->Add(PanelUserFeed, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(StaticBoxSizer_Animation, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel_CogSuite->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel_CogSuite);
    BoxSizer1->SetSizeHints(Panel_CogSuite);
    Panel_RobotController = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer_Manual = new wxStaticBoxSizer(wxHORIZONTAL, Panel_RobotController, _("Manual Override"));
    PanelOverride = new wxPanel(Panel_RobotController, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    Btn_forward = new wxButton(PanelOverride, ID_BUTTON1, _("FORWARD"), wxPoint(8,16), wxSize(88,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Btn_backward = new wxButton(PanelOverride, ID_BUTTON2, _("BACKWARDS"), wxPoint(8,48), wxSize(88,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Btn_grab = new wxButton(PanelOverride, ID_BUTTON3, _("GRAB"), wxPoint(144,16), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Btn_release = new wxButton(PanelOverride, ID_BUTTON4, _("RELEASE"), wxPoint(144,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    StaticBoxSizer_Manual->Add(PanelOverride, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer_Manual, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer_Automated = new wxStaticBoxSizer(wxHORIZONTAL, Panel_RobotController, _("Automated: Key Selection"));
    PanelKeySelection = new wxPanel(Panel_RobotController, ID_PANEL8, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    lblForward = new wxStaticText(PanelKeySelection, ID_STATICTEXT5, _("FORWARD"), wxPoint(8,16), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    lblBackwards = new wxStaticText(PanelKeySelection, ID_STATICTEXT6, _("BACKWARDS"), wxPoint(8,48), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    lblGrab = new wxStaticText(PanelKeySelection, ID_STATICTEXT7, _("GRAB"), wxPoint(152,16), wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    lblRelease = new wxStaticText(PanelKeySelection, ID_STATICTEXT8, _("RELEASE"), wxPoint(152,48), wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    btnDefault = new wxButton(PanelKeySelection, ID_BUTTON5, _("DEFAULT"), wxPoint(104,80), wxSize(72,24), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    ComboBoxForward = new wxChoice(PanelKeySelection, ID_CHOICE2, wxPoint(88,16), wxSize(40,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    ComboBoxForward->Append(_("p"));
    ComboBoxForward->Append(_("u"));
    ComboBoxForward->Append(_("d"));
    ComboBoxForward->Append(_("f"));
    ComboBoxForward->Append(_("b"));
    ComboBoxForward->Append(_("m"));
    ComboBoxGrab = new wxChoice(PanelKeySelection, ID_CHOICE3, wxPoint(200,16), wxSize(48,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
    ComboBoxGrab->Append(_("b"));
    ComboBoxGrab->Append(_("f"));
    ComboBoxGrab->Append(_("n"));
    ComboBoxGrab->Append(_("s"));
    ComboBoxBackward = new wxChoice(PanelKeySelection, ID_CHOICE4, wxPoint(88,48), wxSize(40,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
    ComboBoxBackward->Append(_("m"));
    ComboBoxBackward->Append(_("u"));
    ComboBoxBackward->Append(_("d"));
    ComboBoxBackward->Append(_("t"));
    ComboBoxBackward->Append(_("f"));
    ComboBoxBackward->Append(_("b"));
    ComboBoxRelease = new wxChoice(PanelKeySelection, ID_CHOICE5, wxPoint(200,48), wxSize(48,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
    ComboBoxRelease->Append(_("b"));
    ComboBoxRelease->Append(_("f"));
    ComboBoxRelease->Append(_("n"));
    ComboBoxRelease->Append(_("r"));
    StaticBoxSizer_Automated->Add(PanelKeySelection, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer_Automated, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel_RobotController->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel_RobotController);
    BoxSizer2->SetSizeHints(Panel_RobotController);
    Panel_ConsoleContainer = new wxPanel(Notebook1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    BoxSizer_Console = new wxBoxSizer(wxHORIZONTAL);
    Panel_Console = new wxPanel(Panel_ConsoleContainer, ID_PANEL7, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    lblExpAction = new wxStaticText(Panel_Console, ID_STATICTEXT4, _("Expressiv Action : Clench"), wxPoint(32,24), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    lblExpActionTxt = new wxStaticText(Panel_Console, ID_STATICTEXT13, wxEmptyString, wxPoint(176,24), wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    BoxSizer_Console->Add(Panel_Console, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel_ConsoleContainer->SetSizer(BoxSizer_Console);
    BoxSizer_Console->Fit(Panel_ConsoleContainer);
    BoxSizer_Console->SetSizeHints(Panel_ConsoleContainer);
    Notebook1->AddPage(Panel_CogSuite, _("Cognitiv Suite"), false);
    Notebook1->AddPage(Panel_RobotController, _("Robot Controller"), false);
    Notebook1->AddPage(Panel_ConsoleContainer, _("Expressiv Suite"), false);
    BoxSizer_EmotivCenter->Add(Notebook1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel_main->SetSizer(BoxSizer_EmotivCenter);
    BoxSizer_EmotivCenter->Fit(Panel_main);
    BoxSizer_EmotivCenter->SetSizeHints(Panel_main);
    MenuBar = new wxMenuBar();
    Menu_App = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu_App, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu_App->Append(MenuItem1);
    MenuBar->Append(Menu_App, _("&Application"));
    Menu_Input = new wxMenu();
    MenuItem_EEngine = new wxMenuItem(Menu_Input, ID_MENUITEM2, _("Emo Engine"), _("Connects to Emotiv Engine"), wxITEM_RADIO);
    Menu_Input->Append(MenuItem_EEngine);
    MenuItem_EComposer = new wxMenuItem(Menu_Input, ID_MENUITEM3, _("Emo Composer"), _("Connects to Emotiv Xavier Composer"), wxITEM_RADIO);
    Menu_Input->Append(MenuItem_EComposer);
    MenuBar->Append(Menu_Input, _("Input"));
    Menu_Output = new wxMenu();
    MenuItem5 = new wxMenuItem(Menu_Output, ID_MENUITEM4, _("COM Port Selection"), _("Refresh COM Port selection"), wxITEM_NORMAL);
    Menu_Output->Append(MenuItem5);
    MenuBar->Append(Menu_Output, _("Output"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar);
    StatusBar = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar);

    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&RobotControllerFrame::OnCombo_ComPortSelect);
    Connect(ID_TOGGLEBUTTON1,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&RobotControllerFrame::OnGyroButtonToggle);
    PanelDetection->Connect(wxEVT_PAINT,(wxObjectEventFunction)&RobotControllerFrame::OnPanel2Paint,0,this);
    PanelUserFeed->Connect(wxEVT_PAINT,(wxObjectEventFunction)&RobotControllerFrame::OnPanel3Paint,0,this);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RobotControllerFrame::OnBtn_forwardClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RobotControllerFrame::OnBtn_backwardClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RobotControllerFrame::OnBtn_grabClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RobotControllerFrame::OnBtn_releaseClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&RobotControllerFrame::OnbtnDefaultClick);
    Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&RobotControllerFrame::OnComboBoxForwardSelected);
    Connect(ID_CHOICE3,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&RobotControllerFrame::OnComboBoxGrabSelected);
    Connect(ID_CHOICE4,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&RobotControllerFrame::OnComboBoxBackwardSelected);
    Connect(ID_CHOICE5,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&RobotControllerFrame::OnComboBoxForwardTextUpdated);
    Panel_Console->Connect(wxEVT_PAINT,(wxObjectEventFunction)&RobotControllerFrame::OnPanel_ConsolePaint,0,this);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&RobotControllerFrame::OnQuit);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&RobotControllerFrame::OnMenuItem_EEngineSelected);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&RobotControllerFrame::OnMenuItem_EComposerSelected);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&RobotControllerFrame::OnMenuItem_COMSelection);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&RobotControllerFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&RobotControllerFrame::OnClose);
    //*)


    /** Variable initialization **/
    //robotController = new RobotController(new Serial(L"\\\\.\\COM11"));    //define a new robot controller hardcoded
    isConnectedToEmoEngine = false;      //initially there is no connection
    isConnectedToEmoComposer= false;      //initially there is no connection
    emotiv = new Emotiv();    //define an Emotiv object to read values from the headset
    boost::thread bgWorker(boost::bind(&RobotControllerFrame::UpdateUI,this)); //background thread to refresh UI
    UpdateComPorts();         //get the available ports
    SetPort();                //set the current selected port
    robotController = new RobotController(serial);   //create the robotController
    GyroData=false;           //GyroData is not taken
    isConnectedToEmoEngine=emotiv->ConnectToEmoEngine();   //Connect to the headset directly
    isConnectedToEmoEngine == true ? lblStatusTxt->SetLabel("Connected") : lblStatusTxt->SetLabel("Engine Faliure");
}

RobotControllerFrame::~RobotControllerFrame()
{
    //(*Destroy(RobotControllerFrame)
    //*)
}

void RobotControllerFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void RobotControllerFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = "Controller by Malith";
    wxMessageBox(msg, _("About"));
}


void RobotControllerFrame::OnClose(wxCloseEvent& event)
{
    exit(0);
}

void RobotControllerFrame::OnPanel_ConsolePaint(wxPaintEvent& event)
{
}

void RobotControllerFrame::OnMenuItem_EEngineSelected(wxCommandEvent& event)
{
    lblSettingTxt->SetLabel("Emo Engine");
    EE_EngineDisconnect();
    isConnectedToEmoComposer = false;
    if(!isConnectedToEmoEngine){
            isConnectedToEmoEngine=emotiv->ConnectToEmoEngine();
            if(isConnectedToEmoEngine){
                    lblStatusTxt->SetLabel("Connected");
            }
            else{
                    lblStatusTxt->SetLabel("Engine Faliure");
            }
    }
}

void RobotControllerFrame::OnMenuItem_EComposerSelected(wxCommandEvent& event)
{
    lblSettingTxt->SetLabel("Emo Composer");
    EE_EngineDisconnect();
    isConnectedToEmoEngine = false;
    if(!isConnectedToEmoComposer){
            isConnectedToEmoComposer=emotiv->ConnectToEmoComposer();
              if(isConnectedToEmoComposer){
                    lblStatusTxt->SetLabel("Connected");
            }
            else{
                    lblStatusTxt->SetLabel("Engine Faliure");
            }
    }

}

void RobotControllerFrame::OnBtn_forwardClick(wxCommandEvent& event)
{
    robotController->IssueCommand(robotController->FORWARD);
}

void RobotControllerFrame::OnBtn_backwardClick(wxCommandEvent& event)
{
    robotController->IssueCommand(robotController->BACKWARD);
}


void RobotControllerFrame::OnBtn_grabClick(wxCommandEvent& event)
{
    robotController->IssueCommand(robotController->GRAB);
}

void RobotControllerFrame::OnBtn_releaseClick(wxCommandEvent& event)
{
    robotController->IssueCommand(robotController->RELEASE);
}

void RobotControllerFrame::UpdateUI(){
    while(true){
    int command_cognitiv=1;                      //variable to decode the command
    int command_expressiv=1;
    int command_movement=1;

    /** Get the data from the headset **/
    std::string* values = emotiv->getHeadsetData();
    std::stringstream ss(values[5]);
    double number;
    int threshold = 20;
    ss>>number;
    number*=100;

    /** Refresh the User Interface **/

    /** Refresh even if it's not updated
    lblUpTimeTxt->SetLabel(values[0]);
    lblCogResultTxt->SetLabel(values[1]);
    CogMeter->SetValue((int)number); **/

    /** Refresh only if it's updated excluding errors upto 30%**/
    if(values[0]!=""){
        lblUpTimeTxt->SetLabel(values[0]);
        /** set label colors **/
        if(values[1]=="Neutral"){

            lblCogResultTxt->SetLabel(values[1]);
            CogMeter->SetValue((int)number);

            lblNeutral->SetBackgroundColour(wxColour(0,210,0));
            lblNeutral->SetLabel("");
            lblConcentrate->SetBackgroundColour(wxColour(255,255,255));
            lblConcentrate->SetLabel("");
        }
        else if(number>threshold){

            lblCogResultTxt->SetLabel(values[1]);
            CogMeter->SetValue((int)number);

            lblConcentrate->SetBackgroundColour(wxColour(210,0,0));
            lblConcentrate->SetLabel("");
            lblNeutral->SetBackgroundColour(wxColour(255,255,255));
            lblNeutral->SetLabel("");
        }
        else if(values[1] != "Neutral" && number<=threshold){

            lblCogResultTxt->SetLabel("Neutral");
            CogMeter->SetValue(0);

            lblNeutral->SetBackgroundColour(wxColour(0,210,0));
            lblNeutral->SetLabel("");
            lblConcentrate->SetBackgroundColour(wxColour(255,255,255));
            lblConcentrate->SetLabel("");
        }
    }


    if(values[3]=="1"){
        lblExpActionTxt ->SetLabel("Detected");
    }
    else{
        lblExpActionTxt ->SetLabel("");
    }



    /** Formulate and Issue the command to the robot excluding errors upto 30%**/
    command_cognitiv = atoi(values[2].c_str());
    command_expressiv = atoi(values[3].c_str());
    command_movement = atoi(values[4].c_str());

    if(values[0]!=""){
            if(values[1]=="Neutral"){
                robotController->IssueCommand(command_cognitiv);
                //robotController->IssueCommand_Aux_Facial(command_expressiv);
                if(GyroData){robotController->IssueCommand_Aux_Movement(command_movement);}
            }
            else if(number>threshold){
                robotController->IssueCommand(command_cognitiv);
                //robotController->IssueCommand_Aux_Facial(command_expressiv);
                if(GyroData){robotController->IssueCommand_Aux_Movement(command_movement);}
            }
            else if(values[1]!="Neutral" && number<=threshold){
                robotController->IssueCommand(1);
                //robotController->IssueCommand_Aux_Facial(command_expressiv);
                if(GyroData){robotController->IssueCommand_Aux_Movement(command_movement);}

            }

    }  //send command only if updated
    boost::this_thread::sleep(boost::posix_time::milliseconds(50));
    }
}

void RobotControllerFrame::DetectComPorts(std::vector< tstring >& ports)
{
  size_t upperLimit = 32;               //although the upperlimit should be 128.I made it 32 because it reduces the startup time by 75%
  for(size_t i=1; i<=upperLimit; i++)
  {
	TCHAR strPort[32] = {0};
	_stprintf(strPort, _T("COM%d"), i);

	DWORD dwSize = 0;
	LPCOMMCONFIG lpCC = (LPCOMMCONFIG) new BYTE[1];
	BOOL ret = GetDefaultCommConfig(strPort, lpCC, &dwSize);
	delete [] lpCC;

	lpCC = (LPCOMMCONFIG) new BYTE[dwSize];
	ret = GetDefaultCommConfig(strPort, lpCC, &dwSize);
	delete [] lpCC;
	if(ret) ports.push_back(strPort);
  }
}

void RobotControllerFrame::OnMenuItem_COMSelection(wxCommandEvent& event)
{
    UpdateComPorts();
}

void RobotControllerFrame::UpdateComPorts(){
  std::vector< tstring > ports;
  DetectComPorts(ports);
  int i=0;
  for(std::vector< tstring >::const_iterator it = ports.begin(); it != ports.end(); ++it)
  {
    Combo_ComPort->SetString(i,*it);
    i++;
  }
}

void RobotControllerFrame::OnCombo_ComPortSelect(wxCommandEvent& event)
{
    SetPort();
    robotController->setSerialConnection(serial);
}

void RobotControllerFrame::SetPort(){
   std::string s="\\\\.\\"+Combo_ComPort->GetString(Combo_ComPort->GetCurrentSelection()).ToStdString();
   std::wstring ws;
   serial=new Serial(ws.assign(s.begin(),s.end()));
}

void RobotControllerFrame::OnbtnDefaultClick(wxCommandEvent& event)
{
    robotController->SetDefaults();
    ComboBoxForward->SetLabel("");
    ComboBoxBackward->SetLabel("");
    ComboBoxGrab->SetLabel("");
    ComboBoxRelease->SetLabel("");
}

void RobotControllerFrame::OnComboBoxForwardSelected(wxCommandEvent& event)
{
        std::string str=ComboBoxForward->GetString(ComboBoxForward->GetCurrentSelection()).ToStdString();
        char* writable = new char[str.size()+1];
        std::copy(str.begin(), str.end(), writable);
        writable[str.size()] = '\0';
        robotController->SetForward(writable);
}

void RobotControllerFrame::OnComboBoxForwardTextUpdated(wxCommandEvent& event)
{
    //To Do Text here
}


void RobotControllerFrame::OnComboBoxGrabSelected(wxCommandEvent& event)
{
        std::string str=ComboBoxGrab->GetString(ComboBoxGrab->GetCurrentSelection()).ToStdString();
        char* writable = new char[str.size()+1];
        std::copy(str.begin(), str.end(), writable);
        writable[str.size()] = '\0';
        robotController->SetGrab(writable);
}

void RobotControllerFrame::OnComboBoxBackwardSelected(wxCommandEvent& event)
{
        std::string str=ComboBoxBackward->GetString(ComboBoxBackward->GetCurrentSelection()).ToStdString();
        char* writable = new char[str.size()+1];
        std::copy(str.begin(), str.end(), writable);
        writable[str.size()] = '\0';
        robotController->SetBackward(writable);
}


void RobotControllerFrame::OnComboBoxReleaseSelected(wxCommandEvent& event)
{
        std::string str=ComboBoxRelease->GetString(ComboBoxRelease->GetCurrentSelection()).ToStdString();
        char* writable = new char[str.size()+1];
        std::copy(str.begin(), str.end(), writable);
        writable[str.size()] = '\0';
        robotController->SetRelease(writable);
}


void RobotControllerFrame::OnGyroButtonToggle(wxCommandEvent& event)
{
    if(GyroData){
        GyroData=false;
    }
    else{
        GyroData=true;
    }
}

void RobotControllerFrame::OnPanel3Paint(wxPaintEvent& event)
{
}

void RobotControllerFrame::OnPanel2Paint(wxPaintEvent& event)
{
}

void RobotControllerFrame::SetEmotivAccess(Emotiv* emo)
{
    emotiv=emo;
}

void RobotControllerFrame::SetSerialClass(Serial* serialObj)
{
    serial=serialObj;
}

void RobotControllerFrame::SetRobotController(RobotController* robot)
{
    robotController=robot;
}
