#include "../Course_Project/dataSearch.h"
#include <cstring>

Client* searchClientById(Client* clients, int numClients, long id) {
    for (int i = 0; i < numClients; ++i)
        if (clients[i].id == id) return &clients[i];
    return nullptr;
}

Client* searchClientByName(Client* clients, int numClients, const char* name) {
    for (int i = 0; i < numClients; ++i)
        if (strcmp(clients[i].name, name) == 0) return &clients[i];
    return nullptr;
}

Employee* searchEmployeeById(Employee* employees, int numEmployees, long id) {
    for (int i = 0; i < numEmployees; ++i)
        if (employees[i].id == id) return &employees[i];
    return nullptr;
}

Employee* searchEmployeeByName(Employee* employees, int numEmployees, const char* name) {
    for (int i = 0; i < numEmployees; ++i)
        if (strcmp(employees[i].name, name) == 0) return &employees[i];
    return nullptr;
}

Account* searchAccountById(Account* accounts, int numAccounts, long id) {
    for (int i = 0; i < numAccounts; ++i)
        if (accounts[i].id == id) return &accounts[i];
    return nullptr;
}

Account* searchAccountByNumber(Account* accounts, int numAccounts, int number) {
    for (int i = 0; i < numAccounts; ++i)
        if (accounts[i].number == number) return &accounts[i];
    return nullptr;
}

Transaction* searchTransactionById(Transaction* transactions, int numTransactions, long id) {
    for (int i = 0; i < numTransactions; ++i)
        if (transactions[i].id == id) return &transactions[i];
    return nullptr;
}

Transaction* searchTransactionByPurpose(Transaction* transactions, int numTransactions, const char* purpose) {
    for (int i = 0; i < numTransactions; ++i)
        if (strcmp(transactions[i].purpose, purpose) == 0) return &transactions[i];
    return nullptr;
}

Branch* searchBranchById(Branch* branches, int numBranches, long id) {
    for (int i = 0; i < numBranches; ++i)
        if (branches[i].id == id) return &branches[i];
    return nullptr;
}

Branch* searchBranchByName(Branch* branches, int numBranches, const char* name) {
    for (int i = 0; i < numBranches; ++i)
        if (strcmp(branches[i].name, name) == 0) return &branches[i];
    return nullptr;
}
