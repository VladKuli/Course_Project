#include "Client.h"
#include "Employee.h"
#include "Account.h"
#include "Branch.h"
#include <cstdio>

// --------------------- UNIVERSAL LOAD FUNCTION ---------------------
template <typename T>
bool loadArray(const char* filename, T** arr, int* count) {
    FILE* file = fopen(filename, "rb");
    if (!file) return false;

    fread(count, sizeof(int), 1, file);

    *arr = new T[*count];
    fread(*arr, sizeof(T), *count, file);

    fclose(file);
    return true;
}

// --------------------- UNIVERSAL SAVE FUNCTION ---------------------
template <typename T>
bool saveArray(const char* filename, T* arr, int count) {
    FILE* file = fopen(filename, "wb");
    if (!file) return false;

    fwrite(&count, sizeof(int), 1, file);
    fwrite(arr, sizeof(T), count, file);

    fclose(file);
    return true;
}

// --------------------- CLIENTS ---------------------
bool loadClients(const char* filename, Client** clients, int* numClients) {
    return loadArray(filename, clients, numClients);
}

bool saveClients(const char* filename, Client* clients, int numClients) {
    return saveArray(filename, clients, numClients);
}

// --------------------- EMPLOYEES ---------------------
bool loadEmployees(const char* filename, Employee** employees, int* numEmployees) {
    return loadArray(filename, employees, numEmployees);
}

bool saveEmployees(const char* filename, Employee* employees, int numEmployees) {
    return saveArray(filename, employees, numEmployees);
}

// --------------------- ACCOUNTS ---------------------
bool loadAccounts(const char* filename, Account** accounts, int* numAccounts) {
    return loadArray(filename, accounts, numAccounts);
}

bool saveAccounts(const char* filename, Account* accounts, int numAccounts) {
    return saveArray(filename, accounts, numAccounts);
}

// --------------------- BRANCHES ---------------------
bool loadBranches(const char* filename, Branch** branches, int* numBranches) {
    return loadArray(filename, branches, numBranches);
}

bool saveBranches(const char* filename, Branch* branches, int numBranches) {
    return saveArray(filename, branches, numBranches);
}
