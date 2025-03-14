#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>

class Table {
public:
    Table();
    Table(const std::string& name);
    
    void insert(const std::vector<std::string>& values);
    void select();
    void deleteRow(int id);
    std::vector<std::vector<std::string>> filterRows(int column, const std::string& value);  

    void saveToFile();
    void loadFromFile();

private:
    std::string name;
    std::vector<std::vector<std::string>> data;
};

#endif
