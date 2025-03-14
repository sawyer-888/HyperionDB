#ifndef DATABASE_H
#define DATABASE_H
#define BOOST_ASIO_USE_TS_EXECUTOR_AS_DEFAULT
#include <boost/asio.hpp>


#ifdef _WIN32
    #define EXPORT __declspec(dllexport)  
#else
    #define EXPORT
#endif

#include "table.h"
#include <unordered_map>
#include <vector>
#include <string>

class EXPORT Database {
private:
    std::unordered_map<std::string, Table> tables;  

public:
    Database();
    void createTable(const std::string& name);
    void insert(const std::string& name, const std::vector<std::string>& values);
    void select(const std::string& name);
    void deleteRow(const std::string& name, int id);
    void saveAllTables();
    std::vector<std::vector<std::string>> query(const std::string& table, int column, const std::string& value);
};

#endif
