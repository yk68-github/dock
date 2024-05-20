/***************************************************************
 * Name:      dockMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Y ()
 * Created:   2024-05-20
 * Copyright: Y ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "dockMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(dockFrame)
#include <wx/intl.h>
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

//(*IdInit(dockFrame)
const long dockFrame::ID_AUITOOLBAR1 = wxNewId();
const long dockFrame::ID_CHOICE1 = wxNewId();
const long dockFrame::idMenuQuit = wxNewId();
const long dockFrame::idMenuAbout = wxNewId();
const long dockFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dockFrame,wxFrame)
    //(*EventTable(dockFrame)
    //*)
END_EVENT_TABLE()

dockFrame::dockFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(dockFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    AuiManager1 = new wxAuiManager(this, wxAUI_MGR_DEFAULT);
    AuiToolBar1 = new wxAuiToolBar(this, ID_AUITOOLBAR1, wxPoint(169,202), wxDefaultSize, wxAUI_TB_DEFAULT_STYLE);
    Button3 = new wxButton(AuiToolBar1, wxID_OK, _("Bouton OK"), wxPoint(42,5), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_OK"));
    Button4 = new wxButton(AuiToolBar1, wxID_CANCEL, _("Bonton Annuler"), wxPoint(52,11), wxDefaultSize, 0, wxDefaultValidator, _T("wxID_CANCEL"));
    AuiToolBar1->AddControl(Button3, _("Item label"));
    AuiToolBar1->AddControl(Button4, _("Item label"));
    AuiToolBar1->Realize();
    AuiManager1->AddPane(AuiToolBar1, wxAuiPaneInfo().Name(_T("PaneName2")).ToolbarPane().Caption(_("Pane caption")).Layer(10).Top().Gripper());
    Choice1 = new wxChoice(this, ID_CHOICE1, wxPoint(102,136), wxDLG_UNIT(this,wxSize(300,320)), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    AuiManager1->AddPane(Choice1, wxAuiPaneInfo().Name(_T("PaneName1")).DefaultPane().Caption(_("Pane caption")).CaptionVisible().Left().BestSize(wxDLG_UNIT(this,wxSize(300,320))));
    AuiManager1->Update();
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dockFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&dockFrame::OnAbout);
    //*)
}

dockFrame::~dockFrame()
{
    //(*Destroy(dockFrame)
    //*)
}

void dockFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void dockFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
