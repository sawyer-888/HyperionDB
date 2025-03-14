#include "include/database.h"
#include <iostream>

Database::Database() {}

void Database::createTable(const std::string& name) {
    tables[name] = Table(name);
}

void Database::insert(const std::string& name, const std::vector<std::string>& values) {
    tables[name].insert(values);
}

void Database::select(const std::string& name) {
    tables[name].select();
}

void Database::deleteRow(const std::string& name, int id) {
    tables[name].deleteRow(id);
}

void Database::saveAllTables() {
    for (auto& [name, table] : tables) {
        table.saveToFile();
    }
}

extern "C" {
    EXPORT Database* createDatabase() { return new Database(); }
    EXPORT void destroyDatabase(Database* db) { delete db; }
    EXPORT void createTable(Database* db, const char* name) { db->createTable(name); }
    EXPORT void insertRow(Database* db, const char* name, const char* values) { 
        db->insert(name, {values}); 
    }
    EXPORT void selectTable(Database* db, const char* name) { db->select(name); }
    EXPORT void deleteRow(Database* db, const char* name, int id) { db->deleteRow(name, id); }
    EXPORT void saveAll(Database* db) { db->saveAllTables(); }
}

std::vector<std::vector<std::string>> Database::query(const std::string& table, int column, const std::string& value) {
    if (tables.find(table) != tables.end()) {
        return tables[table].filterRows(column, value);
    }
    return {};
}
