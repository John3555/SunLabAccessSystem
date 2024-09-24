#include "AccessHistoryPanel.h"
#include "Database.h"
#include <sqlite3.h>

AccessHistoryPanel::AccessHistoryPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY) {
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
    
    grid = new wxGrid(this, wxID_ANY);
    grid->CreateGrid(0, 4);
    grid->SetColLabelValue(0, wxT("Log ID"));
    grid->SetColLabelValue(1, wxT("Student ID"));
    grid->SetColLabelValue(2, wxT("Timestamp"));
    grid->SetColLabelValue(3, wxT("Access Type"));

    vbox->Add(grid, 1, wxEXPAND | wxALL, 10);
    SetSizer(vbox);

    LoadLogs();  // Populate grid with access log data
}

void AccessHistoryPanel::LoadLogs() {
    const char* sql = "SELECT log_id, student_id, timestamp, access_type FROM AccessLog";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        wxMessageBox("Failed to load logs from the database.", "Error", wxICON_ERROR);
        return;
    }

    grid->ClearGrid();

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int logId = sqlite3_column_int(stmt, 0);
        int studentId = sqlite3_column_int(stmt, 1);
        const unsigned char* timestamp = sqlite3_column_text(stmt, 2);
        const unsigned char* accessType = sqlite3_column_text(stmt, 3);

        int newRow = grid->GetNumberRows();
        grid->AppendRows(1);
        grid->SetCellValue(newRow, 0, std::to_string(logId));
        grid->SetCellValue(newRow, 1, std::to_string(studentId));
        grid->SetCellValue(newRow, 2, wxString::FromUTF8(reinterpret_cast<const char*>(timestamp)));
        grid->SetCellValue(newRow, 3, wxString::FromUTF8(reinterpret_cast<const char*>(accessType)));
    }

    sqlite3_finalize(stmt);
}
