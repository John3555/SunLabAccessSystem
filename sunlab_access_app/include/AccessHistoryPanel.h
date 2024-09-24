#ifndef ACCESSHISTORYPANEL_H
#define ACCESSHISTORYPANEL_H

#include <wx/wx.h>
#include <wx/grid.h>

class AccessHistoryPanel : public wxPanel {
public:
    AccessHistoryPanel(wxWindow* parent);

private:
    wxGrid* grid;
    void LoadLogs();
};

#endif
