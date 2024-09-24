#include "Database.h"
#include <iostream>

sqlite3* db;

void SetupDatabase() {
    int rc = sqlite3_open("sunlab_access.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // Create tables
    const char* createStudentsTable = 
        "CREATE TABLE IF NOT EXISTS Students ("
        "student_id INTEGER PRIMARY KEY, "
        "name TEXT NOT NULL, "
        "status TEXT DEFAULT 'active');";

    const char* createAccessLogTable = 
        "CREATE TABLE IF NOT EXISTS AccessLog ("
        "log_id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "student_id INTEGER, "
        "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
        "access_type TEXT, "
        "FOREIGN KEY(student_id) REFERENCES Students(student_id));";

    sqlite3_exec(db, createStudentsTable, 0, 0, NULL);
    sqlite3_exec(db, createAccessLogTable, 0, 0, NULL);
}
