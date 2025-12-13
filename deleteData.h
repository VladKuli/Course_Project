#pragma once
#ifndef DATADELETE_H
#define DATADELETE_H

#include "../Course_Project/Client.h"
#include "../Course_Project/Employee.h"
#include "../Course_Project/Account.h"
#include "../Course_Project/Transaction.h"
#include "../Course_Project/Branch.h"

// ---------------- CLIENT DELETE ----------------
bool deleteClientById(Client*& clients, int& numClients, long id);
bool deleteClientByName(Client*& clients, int& numClients, const char* name);
bool deleteClientByEmail(Client*& clients, int& numClients, const char* email);

// ---------------- EMPLOYEE DELETE ----------------
bool deleteEmployeeById(Employee*& employees, int& numEmployees, long id);
bool deleteEmployeeByName(Employee*& employees, int& numEmployees, const char* name);
bool deleteEmployeeByEmail(Employee*& employees, int& numEmployees, const char* email);

// ---------------- ACCOUNT DELETE ----------------
bool deleteAccountById(Account*& accounts, int& numAccounts, long id);
bool deleteAccountByNumber(Account*& accounts, int& numAccounts, int number);
bool deleteAccountByClientId(Account*& accounts, int& numAccounts, long clientId);

// ---------------- TRANSACTION DELETE ----------------
bool deleteTransactionById(Transaction*& transactions, int& numTransactions, long id);
bool deleteTransactionByPurpose(Transaction*& transactions, int& numTransactions, const char* purpose);
bool deleteTransactionBySenderAccountId(Transaction*& transactions, int& numTransactions, long senderAccountId);

// ---------------- BRANCH DELETE ----------------
bool deleteBranchById(Branch*& branches, int& numBranches, long id);
bool deleteBranchByName(Branch*& branches, int& numBranches, const char* name);
bool deleteBranchByPhone(Branch*& branches, int& numBranches, const char* phone);

#endif
