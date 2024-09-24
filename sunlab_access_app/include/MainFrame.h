#ifndef MAINFRAME_H
#define MAINFRAME_H

#include wxwx.h

class MainFrame  public wxFrame {
public
    MainFrame(const wxString& title);

private
    void OnViewLogs(wxCommandEvent& event);
    void OnManageStudents(wxCommandEvent& event);
};

#endif
