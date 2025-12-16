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

void sortEmployeesByRole(Employee* employees, int numEmployees) {
    for (int i = 0; i < numEmployees - 1; i++)
        for (int j = 0; j < numEmployees - i - 1; j++)
            if (employees[j].role > employees[j + 1].role) {
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


void sortBranchesBySize(Branch* branches, int numBranches) {
    for (int i = 0; i < numBranches - 1; i++)
        for (int j = 0; j < numBranches - i - 1; j++)
            if (branches[j].size > branches[j + 1].size) {
                Branch tmp = branches[j];
                branches[j] = branches[j + 1];
                branches[j + 1] = tmp;
            }
}

int countClientsForBranch(const Branch& branch, const Client* clients, int numClients) {
    int count = 0;
    for (int i = 0; i < numClients; ++i) {
        if (clients[i].branchId == branch.id) count++;
    }
    return count;
}

void sortBranchesByClientCount(Branch* branches, int numBranches, const Client* clients, int numClients) {

    for (int i = 0; i < numBranches - 1; ++i) {
        for (int j = 0; j < numBranches - i - 1; ++j) {
            int countA = countClientsForBranch(branches[j], clients, numClients);
            int countB = countClientsForBranch(branches[j + 1], clients, numClients);
            if (countA < countB) {
                Branch temp = branches[j];
                branches[j] = branches[j + 1];
                branches[j + 1] = temp;
            }
        }
    }
}
