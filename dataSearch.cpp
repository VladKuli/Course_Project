#include "dataSearch.h"
#include <cstring>

// ---------------- CLIENT SEARCH ----------------
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

Client* searchClientByEmail(Client* clients, int numClients, const char* email) {
    for (int i = 0; i < numClients; ++i)
        if (strcmp(clients[i].email, email) == 0) return &clients[i];
    return nullptr;
}

// ---------------- EMPLOYEE SEARCH ----------------
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

Employee* searchEmployeeByEmail(Employee* employees, int numEmployees, const char* email) {
    for (int i = 0; i < numEmployees; ++i)
        if (strcmp(employees[i].email, email) == 0) return &employees[i];
    return nullptr;
}

// ---------------- ACCOUNT SEARCH ----------------
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

Account* searchAccountByClientId(Account* accounts, int numAccounts, long clientId) {
    for (int i = 0; i < numAccounts; ++i)
        if (accounts[i].clientId == clientId) return &accounts[i];
    return nullptr;
}

// ---------------- BRANCH SEARCH ----------------
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

Branch* searchByAddress(Branch* branches, int numBranches, const char* address) {
    for (int i = 0; i < numBranches; ++i)
        if (strcmp(branches[i].address, address) == 0) return &branches[i];
    return nullptr;
}

