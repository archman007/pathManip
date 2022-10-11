/***************************************************************
 * Name:      pathManipMain.h
 * Purpose:   Defines Application Frame
 * Author:    Mr. Arch Brooks (arch@archbrooks.com)
 * Created:   2022-10-11
 * Copyright: Mr. Arch Brooks (https://archbrooks.us/b4)
 * License:
 **************************************************************/

#ifndef PATHMANIPMAIN_H
#define PATHMANIPMAIN_H

//(*Headers(pathManipFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class pathManipFrame: public wxFrame
{
    public:

        pathManipFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~pathManipFrame();

    private:

        //(*Handlers(pathManipFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnmenManipFsSelected(wxCommandEvent& event);
        //*)

        //(*Identifiers(pathManipFrame)
        static const long ID_MENUITEM1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(pathManipFrame)
        wxMenuItem* menManipFs;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PATHMANIPMAIN_H
