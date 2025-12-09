#include "datasort.h"
#include <cstring>

// ---------------- CLIENT SORT ----------------
void sortClientsByName(Client* clients, int numClients) {
    for (int i = 0; i < numClients - 1; i++)
        for (int j = 0; j < numClients - i - 1; j++)
            if (strcmp(clients[j].name, clients[j + 1].name) > 0) {
                Client tmp = clients[j];
                clients[j] = clients[j + 1];
                clients[j + 1] = tmp;
            }
}

void sortClientByPhone(Client* clients, int numClients) {
    for (int i = 0; i < numClients - 1; i++)
        for (int j = 0; j < numClients - i - 1; j++)
            if (strcmp(clients[j].phone, clients[j + 1].phone) > 0) {
                Client tmp = clients[j];
                clients[j] = clients[j + 1];
                clients[j + 1] = tmp;
            }
}

void sortClientByEmail(Client* clients, int numClients) {
    for (int i = 0; i < numClients - 1; i++)
        for (int j = 0; j < numClients - i - 1; j++)
            if (strcmp(clients[j].email, clients[j + 1].email) > 0) {
                Client tmp = clients[j];
                clients[j] = clients[j + 1];
                clients[j + 1] = tmp;
            }
}

// ---------------- EMPLOYEE SORT ----------------
void sortEmployeesByName(Employee* employees, int numEmployees) {
    for (int i = 0; i < numEmployees - 1; i++)
        for (int j = 0; j < numEmployees - i - 1; j++)
            if (strcmp(employees[j].name, employees[j + 1].name) > 0) {
                Employee tmp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = tmp;
            }
}

void sortEmployeeByLevel(Employee* employees, int numEmployees) {
    for (int i = 0; i < numEmployees - 1; i++)
        for (int j = 0; j < numEmployees - i - 1; j++)
            if (employees[j].level > employees[j + 1].level) {
                Employee tmp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = tmp;
            }
}

void sortEmployeeByDepartment(Employee* employees, int numEmployees) {
    for (int i = 0; i < numEmployees - 1; i++)
        for (int j = 0; j < numEmployees - i - 1; j++)
            if (strcmp(employees[j].department, employees[j + 1].department) > 0) {
                Employee tmp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = tmp;
            }
}

// ---------------- ACCOUNT SORT ----------------
void sortAccountsByBalance(Account* accounts, int numAccounts) {
    for (int i = 0; i < numAccounts - 1; i++)
        for (int j = 0; j < numAccounts - i - 1; j++)
            if (accounts[j].balance > accounts[j + 1].balance) {
                Account tmp = accounts[j];
                accounts[j] = accounts[j + 1];
                accounts[j + 1] = tmp;
            }
}

void sortAccountsByType(Account* accounts, int numAccounts) {
    for (int i = 0; i < numAccounts - 1; i++)
        for (int j = 0; j < numAccounts - i - 1; j++)
            if (accounts[j].type > accounts[j + 1].type) {
                Account tmp = accounts[j];
                accounts[j] = accounts[j + 1];
                accounts[j + 1] = tmp;
            }
}

void sortAccountsByCurrency(Account* accounts, int numAccounts) {
    for (int i = 0; i < numAccounts - 1; i++)
        for (int j = 0; j < numAccounts - i - 1; j++)
            if (strcmp(accounts[j].currency, accounts[j + 1].currency) > 0) {
                Account tmp = accounts[j];
                accounts[j] = accounts[j + 1];
                accounts[j + 1] = tmp;
            }
}

// ---------------- TRANSACTION SORT ----------------
void sortTransactionsByDate(Transaction* transactions, int numTransactions) {
    for (int i = 0; i < numTransactions - 1; i++)
        for (int j = 0; j < numTransactions - i - 1; j++)
            if (transactions[j].date > transactions[j + 1].date) {
                Transaction tmp = transactions[j];
                transactions[j] = transactions[j + 1];
                transactions[j + 1] = tmp;
            }
}

void sortTransactionsByAmount(Transaction* transactions, int numTransactions) {
    for (int i = 0; i < numTransactions - 1; i++)
        for (int j = 0; j < numTransactions - i - 1; j++)
            if (transactions[j].amount > transactions[j + 1].amount) {
                Transaction tmp = transactions[j];
                transactions[j] = transactions[j + 1];
                transactions[j + 1] = tmp;
            }
}

void sortTransactionsByType(Transaction* transactions, int numTransactions) {
    for (int i = 0; i < numTransactions - 1; i++)
        for (int j = 0; j < numTransactions - i - 1; j++)
            if (transactions[j].type > transactions[j + 1].type) {
                Transaction tmp = transactions[j];
                transactions[j] = transactions[j + 1];
                transactions[j + 1] = tmp;
            }
}

// ---------------- BRANCH SORT ----------------
void sortBranchesByName(Branch* branches, int numBranches) {
    for (int i = 0; i < numBranches - 1; i++)
        for (int j = 0; j < numBranches - i - 1; j++)
            if (strcmp(branches[j].name, branches[j + 1].name) > 0) {
                Branch tmp = branches[j];
                branches[j] = branches[j + 1];
                branches[j + 1] = tmp;
            }
}

void sortBranchesByRegion(Branch* branches, int numBranches) {
    for (int i = 0; i < numBranches - 1; i++)
        for (int j = 0; j < numBranches - i - 1; j++)
            if (branches[j].region > branches[j + 1].region) {
                Branch tmp = branches[j];
                branches[j] = branches[j + 1];
                branches[j + 1] = tmp;
            }
}

void sortBranchesBySize(Branch* branches, int numBranches) {
    for (int i = 0; i < numBranches - 1; i++)
        for (int j = 0; j < numBranches - i - 1; j++)
            if (branches[j].size > branches[j + 1].size) {
                Branch tmp = branches[j];
                branches[j] = branches[j + 1];
                branches[j + 1] = tmp;
            }
}
