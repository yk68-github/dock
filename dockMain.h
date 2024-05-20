/***************************************************************
 * Name:      dockMain.h
 * Purpose:   Defines Application Frame
 * Author:    Y ()
 * Created:   2024-05-20
 * Copyright: Y ()
 * License:
 **************************************************************/

#ifndef DOCKMAIN_H
#define DOCKMAIN_H

//(*Headers(dockFrame)
#include <wx/aui/aui.h>
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class dockFrame: public wxFrame
{
    public:

        dockFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~dockFrame();

    private:

        //(*Handlers(dockFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(dockFrame)
        static const long ID_AUITOOLBAR1;
        static const long ID_CHOICE1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(dockFrame)
        wxAuiManager* AuiManager1;
        wxAuiToolBar* AuiToolBar1;
        wxButton* Button3;
        wxButton* Button4;
        wxChoice* Choice1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // DOCKMAIN_H
