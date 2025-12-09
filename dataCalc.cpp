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

int calculateBranchesByRegion(Branch* branches, int numBranches, BranchRegion region) {
    int count = 0;
    for (int i = 0; i < numBranches; i++)
        if (branches[i].region == region) count++;
    return count;
}

int calculateBranchesByType(Branch* branches, int numBranches, BranchType type) {
    int count = 0;
    for (int i = 0; i < numBranches; i++)
        if (branches[i].type == type) count++;
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

int calculateTransactionsByType(Transaction* transactions, int numTransactions, TransactionType type) {
    int count = 0;
    for (int i = 0; i < numTransactions; i++)
        if (transactions[i].type == type) count++;
    return count;
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
