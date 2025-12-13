#include "dataCalc.h"
#include <cstring>
#include <ctime>

// ---------------- CLIENT CALCULATIONS ----------------
int calculateTotalClients(Client* clients, int numClients) {
    return numClients;
}

int calculateClientsByLevel(Client* clients, int numClients, ClientLevel level) {
    int count = 0;
    for (int i = 0; i < numClients; i++)
        if (clients[i].level == level) count++;
    return count;
}

int calculateClientsByType(Client* clients, int numClients, ClientType type) {
    int count = 0;
    for (int i = 0; i < numClients; i++)
        if (clients[i].type == type) count++;
    return count;
}

// ---------------- EMPLOYEE CALCULATIONS ----------------
int calculateTotalEmployees(Employee* employees, int numEmployees) {
    return numEmployees;
}

int calculateEmployeesByRole(Employee* employees, int numEmployees, EmployeeRole role) {
    int count = 0;
    for (int i = 0; i < numEmployees; i++)
        if (employees[i].role == role) count++;
    return count;
}

int calculateEmployeesByLevel(Employee* employees, int numEmployees, EmployeeLevel level) {
    int count = 0;
    for (int i = 0; i < numEmployees; i++)
        if (employees[i].level == level) count++;
    return count;
}

// ---------------- BRANCH CALCULATIONS ----------------
int calculateTotalBranches(Branch* branches, int numBranches) {
    return numBranches;
}

int calculateBranchesBySize(Branch* branches, int numBranches, BranchSize size) {
    int count = 0;
    for (int i = 0; i < numBranches; i++)
        if (branches[i].size == size) count++;
    return count;
}

int calculateBranchesByClientCount(Branch* branches, int numBranches, int minClients) {
    int count = 0;
    for (int i = 0; i < numBranches; i++)
        if (branches[i].numClients >= minClients) count++;
    return count;
}

// ---------------- ACCOUNT CALCULATIONS ----------------
int calculateTotalAccounts(Account* accounts, int numAccounts) {
    return numAccounts;
}

int calculateAccountsByType(Account* accounts, int numAccounts, AccountType type) {
    int count = 0;
    for (int i = 0; i < numAccounts; i++)
        if (accounts[i].type == type) count++;
    return count;
}

int calculateAccountsByCurrency(Account* accounts, int numAccounts, const char* currency) {
    int count = 0;
    for (int i = 0; i < numAccounts; i++)
        if (strcmp(accounts[i].currency, currency) == 0) count++;
    return count;
}

// ---------------- TRANSACTION CALCULATIONS ----------------
int calculateTotalTransactions(Transaction* transactions, int numTransactions) {
    return numTransactions;
}

int calculateTransactionsByDate(Transaction* transactions, int numTransactions, time_t date) {
    int count = 0;
    tm* target = localtime(&date);

    for (int i = 0; i < numTransactions; i++) {
        tm* t = localtime(&transactions[i].date);
        if (t->tm_year == target->tm_year &&
            t->tm_mon == target->tm_mon &&
            t->tm_mday == target->tm_mday)
            count++;
    }
    return count;
}
 int calculateTransactionsBySenderAccount(Transaction * transactions, int numTransactions, long senderAccountId) {
        int count = 0;
        for (int i = 0; i < numTransactions; i++)
            if (transactions[i].senderAccountId == senderAccountId) count++;
        return count;
 }

