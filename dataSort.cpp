#include "../Course_Project/dataSort.h"
#include <cstring>

void sortClientsByName(Client* clients, int numClients) {
    for (int i = 0; i < numClients - 1; i++) {
        for (int j = i + 1; j < numClients; j++) {
            if (strcmp(clients[i].name, clients[j].name) > 0) {
                Client tmp = clients[i]; clients[i] = clients[j]; clients[j] = tmp;
            }
        }
    }
}

void sortEmployeesByName(Employee* employees, int numEmployees) {
    for (int i = 0; i < numEmployees - 1; i++) {
        for (int j = i + 1; j < numEmployees; j++) {
            if (strcmp(employees[i].name, employees[j].name) > 0) {
                Employee tmp = employees[i]; employees[i] = employees[j]; employees[j] = tmp;
            }
        }
    }
}

void sortAccountsByBalance(Account* accounts, int numAccounts) {
    for (int i = 0; i < numAccounts - 1; i++) {
        for (int j = i + 1; j < numAccounts; j++) {
            if (accounts[i].balance > accounts[j].balance) {
                Account tmp = accounts[i]; accounts[i] = accounts[j]; accounts[j] = tmp;
            }
        }
    }
}

void sortTransactionsByDate(Transaction* transactions, int numTransactions) {
    for (int i = 0; i < numTransactions - 1; i++) {
        for (int j = i + 1; j < numTransactions; j++) {
            if (transactions[i].date > transactions[j].date) {
                Transaction tmp = transactions[i]; transactions[i] = transactions[j]; transactions[j] = tmp;
            }
        }
    }
}

void sortBranchesByName(Branch* branches, int numBranches) {
    for (int i = 0; i < numBranches - 1; i++) {
        for (int j = i + 1; j < numBranches; j++) {
            if (strcmp(branches[i].name, branches[j].name) > 0) {
                Branch tmp = branches[i]; branches[i] = branches[j]; branches[j] = tmp;
            }
        }
    }
}
