#include "include/cli.h"
#include <iostream>
#include <sstream>

CLI::CLI(Database& db) : db(db) {}

void CLI::run() {
    std::string command;
    std::cout << "HyperionDB CLI - Type 'exit' to quit ok have fun\n";
    while (true) {
        std::cout << "HyperionDB> ";
        std::getline(std::cin, command);
        if (command == "exit") {
            std::cout << "Saving all data...\n";
            db.saveAllTables(); 
            std::cout << "Exiting HyperionDB...\n";
            exit(0);
        }
        
        processCommand(command);
    }
}

void CLI::processCommand(const std::string& command) {
    std::istringstream ss(command);
    std::string keyword;
    ss >> keyword;

    if (keyword == "CREATE") {
        std::string table;
        ss >> table;
        db.createTable(table);
    } else if (keyword == "INSERT") {
        std::string table, value;
        ss >> table;
        std::vector<std::string> values;
        while (ss >> value) values.push_back(value);
        db.insert(table, values);
    } else if (keyword == "SELECT") {
        std::string table;
        ss >> table;
        
        std::string whereClause;
        ss >> whereClause;  

        if (whereClause == "WHERE") {
            int column;
            std::string equalSign, value;
            ss >> column >> equalSign >> value;

            if (equalSign == "=") {
                auto result = db.query(table, column, value);
                for (const auto& row : result) {
                    for (const auto& val : row) {
                        std::cout << val << " ";
                    }
                    std::cout << "\n";
                }
            } else {
                std::cout << "Invalid query syntax.\n";
            }
        } else {
            db.select(table);
        }

    } else if (keyword == "DELETE") {
        std::string table;
        int id;
        ss >> table >> id;
        db.deleteRow(table, id);
    } else {
        std::cout << "Unknown command :(\n";
    }
}
