#include "include/database.h"
#include "include/cli.h"
#include <iostream>
#include <csignal>  
#include <cstdlib>

Database db;  

void handleExit(int signum) { 
    std::cout << "\n[HyperionDB] Saving all data before exit...\n";
    db.saveAllTables();
    std::cout << "[HyperionDB] Data saved. Exiting safely.\n";
    exit(signum);
}

int main() {
    signal(SIGINT, handleExit); 
    signal(SIGTERM, handleExit); 

    std::cout << "Welcome to HyperionDB by Sawyer888!\n";
    std::cout << "HyperionDB CLI – Type 'exit' to quit.\n";

    CLI cli(db);
    cli.run();

    return 0;
}
