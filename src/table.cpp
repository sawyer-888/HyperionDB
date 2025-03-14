#include "include/table.h"
#include <iostream>
#include <fstream>

Table::Table() : name("default") {}

Table::Table(const std::string& name) : name(name) {
    loadFromFile();  
}

void Table::insert(const std::vector<std::string>& values) {
    data.push_back(values);
    saveToFile();  
}

void Table::select() {
    std::cout << "Table: " << name << "\n";
    for (size_t i = 0; i < data.size(); i++) {
        std::cout << "Row " << i << ": ";
        for (const auto& value : data[i]) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}

void Table::deleteRow(int id) {
    if (id < 0 || id >= static_cast<int>(data.size())) {
        std::cout << "Invalid row ID\n";
        return;
    }
    data.erase(data.begin() + id);
    saveToFile();  
}

void Table::saveToFile() {
    std::ofstream file("db_" + name + ".txt");  
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); i++) {
            file << row[i] << (i + 1 < row.size() ? "," : "\n");
        }
    }
    file.close();
}

void Table::loadFromFile() {
    std::ifstream file("db_" + name + ".txt");
    if (!file) return; 

    data.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        size_t start = 0, end;
        while ((end = line.find(',', start)) != std::string::npos) {
            row.push_back(line.substr(start, end - start));
            start = end + 1;
        }
        row.push_back(line.substr(start));
        data.push_back(row);
    }
    file.close();
}
std::vector<std::vector<std::string>> Table::filterRows(int column, const std::string& value) {
    std::vector<std::vector<std::string>> result;
    
    for (const auto& row : data) {
        if (column < static_cast<int>(row.size()) && row[column] == value) {
            result.push_back(row);
        }
    }
    
    return result;
}
