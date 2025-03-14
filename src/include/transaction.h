#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <vector>
#include <string>

class Transaction {
public:
    void begin();
    void commit();
    void rollback();
private:
    std::vector<std::string> log;
};

#endif
