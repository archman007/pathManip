/***************************************************************
 * Name:      pathManipApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Mr. Arch Brooks (arch@archbrooks.com)
 * Created:   2022-10-11
 * Copyright: Mr. Arch Brooks (https://archbrooks.us/b4)
 * License:
 **************************************************************/

#include "pathManipApp.h"

//(*AppHeaders
#include "pathManipMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(pathManipApp);

bool pathManipApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	pathManipFrame* Frame = new pathManipFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
