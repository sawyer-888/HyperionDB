#include "include/transaction.h"
#include <iostream>

void Transaction::begin() {
    log.clear();
    std::cout << "Transaction started.\n";
}

void Transaction::commit() {
    log.clear();
    std::cout << "Transaction committed.\n";
}

void Transaction::rollback() {
    std::cout << "Transaction rolled back.\n";
}
