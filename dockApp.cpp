/***************************************************************
 * Name:      dockApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Y ()
 * Created:   2024-05-20
 * Copyright: Y ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "dockApp.h"

//(*AppHeaders
#include "dockMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(dockApp);

bool dockApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	dockFrame* Frame = new dockFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
