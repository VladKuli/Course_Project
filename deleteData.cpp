#include "deleteData.h"
#include <cstring>

// ---------------- CLIENT DELETE ----------------
bool deleteClientById(Client*& clients, int& numClients, long id) {
    for (int i = 0; i < numClients; i++) {
        if (clients[i].id == id) {
            Client* tmp = new Client[numClients - 1];
            for (int j = 0, k = 0; j < numClients; j++) {
                if (j != i) tmp[k++] = clients[j];
            }
            delete[] clients;
            clients = tmp;
            numClients--;
            return true;
        }
    }
    return false;
}

bool deleteClientByName(Client*& clients, int& numClients, const char* name) {
    for (int i = 0; i < numClients; i++) {
        if (strcmp(clients[i].name, name) == 0) {
            Client* tmp = new Client[numClients - 1];
            for (int j = 0, k = 0; j < numClients; j++) if (j != i) tmp[k++] = clients[j];
            delete[] clients;
            clients = tmp;
            numClients--;
            return true;
        }
    }
    return false;
}

bool deleteClientByEmail(Client*& clients, int& numClients, const char* email) {
    for (int i = 0; i < numClients; i++) {
        if (strcmp(clients[i].email, email) == 0) {
            Client* tmp = new Client[numClients - 1];
            for (int j = 0, k = 0; j < numClients; j++) if (j != i) tmp[k++] = clients[j];
            delete[] clients;
            clients = tmp;
            numClients--;
            return true;
        }
    }
    return false;
}

// ---------------- EMPLOYEE DELETE ----------------
bool deleteEmployeeById(Employee*& employees, int& numEmployees, long id) {
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == id) {
            Employee* tmp = new Employee[numEmployees - 1];
            for (int j = 0, k = 0; j < numEmployees; j++) if (j != i) tmp[k++] = employees[j];
            delete[] employees;
            employees = tmp;
            numEmployees--;
            return true;
        }
    }
    return false;
}

bool deleteEmployeeByName(Employee*& employees, int& numEmployees, const char* name) {
    for (int i = 0; i < numEmployees; i++) {
        if (strcmp(employees[i].name, name) == 0) {
            Employee* tmp = new Employee[numEmployees - 1];
            for (int j = 0, k = 0; j < numEmployees; j++) if (j != i) tmp[k++] = employees[j];
            delete[] employees;
            employees = tmp;
            numEmployees--;
            return true;
        }
    }
    return false;
}

bool deleteEmployeeByEmail(Employee*& employees, int& numEmployees, const char* email) {
    for (int i = 0; i < numEmployees; i++) {
        if (strcmp(employees[i].email, email) == 0) {
            Employee* tmp = new Employee[numEmployees - 1];
            for (int j = 0, k = 0; j < numEmployees; j++) if (j != i) tmp[k++] = employees[j];
            delete[] employees;
            numEmployees--;
            return true;
        }
    }
    return false;
}

// ---------------- ACCOUNT DELETE ----------------
bool deleteAccountById(Account*& accounts, int& numAccounts, long id) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].id == id) {
            Account* tmp = new Account[numAccounts - 1];
            for (int j = 0, k = 0; j < numAccounts; j++) if (j != i) tmp[k++] = accounts[j];
            delete[] accounts;
            accounts = tmp;
            numAccounts--;
            return true;
        }
    }
    return false;
}

bool deleteAccountByNumber(Account*& accounts, int& numAccounts, int number) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].number == number) {
            Account* tmp = new Account[numAccounts - 1];
            for (int j = 0, k = 0; j < numAccounts; j++) if (j != i) tmp[k++] = accounts[j];
            delete[] accounts;
            accounts = tmp;
            numAccounts--;
            return true;
        }
    }
    return false;
}

bool deleteAccountByClientId(Account*& accounts, int& numAccounts, long clientId) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].clientId == clientId) {
            Account* tmp = new Account[numAccounts - 1];
            for (int j = 0, k = 0; j < numAccounts; j++) if (j != i) tmp[k++] = accounts[j];
            delete[] accounts;
            accounts = tmp;
            numAccounts--;
            return true;
        }
    }
    return false;
}

// ---------------- TRANSACTION DELETE ----------------
bool deleteTransactionById(Transaction*& transactions, int& numTransactions, long id) {
    for (int i = 0; i < numTransactions; i++) {
        if (transactions[i].id == id) {
            Transaction* tmp = new Transaction[numTransactions - 1];
            for (int j = 0, k = 0; j < numTransactions; j++) if (j != i) tmp[k++] = transactions[j];
            delete[] transactions;
            transactions = tmp;
            numTransactions--;
            return true;
        }
    }
    return false;
}

bool deleteTransactionByPurpose(Transaction*& transactions, int& numTransactions, const char* purpose) {
    for (int i = 0; i < numTransactions; i++) {
        if (strcmp(transactions[i].purpose, purpose) == 0) {
            Transaction* tmp = new Transaction[numTransactions - 1];
            for (int j = 0, k = 0; j < numTransactions; j++) if (j != i) tmp[k++] = transactions[j];
            delete[] transactions;
            transactions = tmp;
            numTransactions--;
            return true;
        }
    }
    return false;
}

bool deleteTransactionBySenderAccountId(Transaction*& transactions, int& numTransactions, long senderAccountId) {
    for (int i = 0; i < numTransactions; i++) {
        if (transactions[i].senderAccountId == senderAccountId) {
            Transaction* tmp = new Transaction[numTransactions - 1];
            for (int j = 0, k = 0; j < numTransactions; j++) if (j != i) tmp[k++] = transactions[j];
            delete[] transactions;
            transactions = tmp;
            numTransactions--;
            return true;
        }
    }
    return false;
}

// ---------------- BRANCH DELETE ----------------
bool deleteBranchById(Branch*& branches, int& numBranches, long id) {
    for (int i = 0; i < numBranches; i++) {
        if (branches[i].id == id) {
            Branch* tmp = new Branch[numBranches - 1];
            for (int j = 0, k = 0; j < numBranches; j++) if (j != i) tmp[k++] = branches[j];
            delete[] branches;
            branches = tmp;
            numBranches--;
            return true;
        }
    }
    return false;
}

bool deleteBranchByName(Branch*& branches, int& numBranches, const char* name) {
    for (int i = 0; i < numBranches; i++) {
        if (strcmp(branches[i].name, name) == 0) {
            Branch* tmp = new Branch[numBranches - 1];
            for (int j = 0, k = 0; j < numBranches; j++) if (j != i) tmp[k++] = branches[j];
            delete[] branches;
            numBranches--;
            return true;
        }
    }
    return false;
}

bool deleteBranchByManagerId(Branch*& branches, int& numBranches, long managerId) {
    for (int i = 0; i < numBranches; i++) {
        if (branches[i].managerId == managerId) {
            Branch* tmp = new Branch[numBranches - 1];
            for (int j = 0, k = 0; j < numBranches; j++) if (j != i) tmp[k++] = branches[j];
            delete[] branches;
            branches = tmp;
            numBranches--;
            return true;
        }
    }
    return false;
}
