#include "StudentManagementPanel.h"
#include "Database.h"
#include <sqlite3.h>

StudentManagementPanel::StudentManagementPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    
    wxButton* activateButton = new wxButton(this, wxID_ANY, wxT("Activate Student"));
    wxButton* suspendButton = new wxButton(this, wxID_ANY, wxT("Suspend Student"));
    wxButton* reactivateButton = new wxButton(this, wxID_ANY, wxT("Reactivate Student"));

    vbox->Add(activateButton, 0, wxALL, 10);
    vbox->Add(suspendButton, 0, wxALL, 10);
    vbox->Add(reactivateButton, 0, wxALL, 10);
    
    SetSizer(vbox);

    Connect(activateButton->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(StudentManagementPanel::OnActivateStudent));
    Connect(suspendButton->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(StudentManagementPanel::OnSuspendStudent));
    Connect(reactivateButton->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(StudentManagementPanel::OnReactivateStudent));
}

void StudentManagementPanel::UpdateStudentStatus(int studentId, const std::string& status) {
    std::string sql = "UPDATE Students SET status = '" + status + "' WHERE student_id = ?";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, studentId);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        wxMessageBox("Failed to update student status.", "Error", wxICON_ERROR);
    }

    sqlite3_finalize(stmt);
}

void StudentManagementPanel::OnActivateStudent(wxCommandEvent& event) {
    UpdateStudentStatus(1, "active");  // Example: Activate student with ID 1
}

void StudentManagementPanel::OnSuspendStudent(wxCommandEvent& event) {
    UpdateStudentStatus(1, "suspended");  // Example: Suspend student with ID 1
}

void StudentManagementPanel::OnReactivateStudent(wxCommandEvent& event) {
    UpdateStudentStatus(1, "active");  // Example: Reactivate student with ID 1
}
