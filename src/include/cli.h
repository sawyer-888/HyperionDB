#ifndef CLI_H
#define CLI_H

#include "database.h"

class CLI {
public:
    CLI(Database& db);
    void run();
    
private:
    Database& db;
    void processCommand(const std::string& command);
};

#endif
