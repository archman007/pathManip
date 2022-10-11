/***************************************************************
 * Name:      pathManipMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Mr. Arch Brooks (arch@archbrooks.com)
 * Created:   2022-10-11
 * Copyright: Mr. Arch Brooks (https://archbrooks.us/b4)
 * License:
 **************************************************************/

#include "pathManipMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(pathManipFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

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

//(*IdInit(pathManipFrame)
const long pathManipFrame::ID_MENUITEM1 = wxNewId();
const long pathManipFrame::idMenuQuit = wxNewId();
const long pathManipFrame::idMenuAbout = wxNewId();
const long pathManipFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(pathManipFrame,wxFrame)
    //(*EventTable(pathManipFrame)
    //*)
END_EVENT_TABLE()

using namespace std;

struct rPath_area
{
    string rawPath = "/home/archman/workspace/cb/cpp/pathManip/pathManip.cbp";
    int eop; // Value used for scannind
    string pathOnly; // Just the file path
    string fileNameOnly; // File name and extension
    string xqt; // Executable file name
    string xqtFs; // Command line to run the release version of the project
    string compileCl; // Command line for compling the project in CodeBlocks

};

rPath_area pm;

pathManipFrame::pathManipFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(pathManipFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    menManipFs = new wxMenuItem(Menu1, ID_MENUITEM1, _("Manipulate File Spec"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(menManipFs);
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

    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pathManipFrame::OnmenManipFsSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pathManipFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&pathManipFrame::OnAbout);
    //*)
}

pathManipFrame::~pathManipFrame()
{
    //(*Destroy(pathManipFrame)
    //*)
}

void pathManipFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void pathManipFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void pathManipFrame::OnmenManipFsSelected(wxCommandEvent& event)
{
    pm.eop = pm.rawPath.find_last_of("/");
    pm.pathOnly = pm.rawPath.substr(0, pm.eop);
    pm.fileNameOnly = pm.rawPath.substr(pm.eop+1);
    pm.xqt = pm.fileNameOnly.substr(0, pm.fileNameOnly.find_last_of("."));
    pm.xqtFs = pm.pathOnly + "/bin/Release/" + pm.xqt;
    pm.compileCl = "/usr/bin/codeblocks ";
    pm.compileCl = pm.compileCl + pm.rawPath;
    pm = pm;

}
