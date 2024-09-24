#ifndef STUDENTMANAGEMENTPANEL_H
#define STUDENTMANAGEMENTPANEL_H

#include <wx/wx.h>

class StudentManagementPanel : public wxPanel {
public:
    StudentManagementPanel(wxWindow* parent);

private:
    void OnActivateStudent(wxCommandEvent& event);
    void OnSuspendStudent(wxCommandEvent& event);
    void OnReactivateStudent(wxCommandEvent& event);
    void UpdateStudentStatus(int studentId, const std::string& status);
};

#endif
