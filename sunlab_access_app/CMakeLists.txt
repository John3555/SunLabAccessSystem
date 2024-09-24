cmake_minimum_required(VERSION 3.0)
project(SunLabAccess)

# Find and link wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Add executable
add_executable(sunlab_access main.cpp MainFrame.cpp AccessHistoryPanel.cpp StudentManagementPanel.cpp Database.cpp)

# Link wxWidgets and SQLite
target_link_libraries(sunlab_access ${wxWidgets_LIBRARIES} sqlite3)
