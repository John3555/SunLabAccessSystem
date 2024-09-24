#include "MainFrame.h"
#include "Database.h"
#include <wx/wx.h>

class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

bool MyApp::OnInit() {
    SetupDatabase();  // Ensure the database is ready

    MainFrame* frame = new MainFrame("SUN Lab Access System");
    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(MyApp);
