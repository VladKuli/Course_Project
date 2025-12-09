#pragma once
#ifndef DATASORT_H
#define DATASORT_H

#include "../Course_Project/Client.h"
#include "../Course_Project/Employee.h"
#include "../Course_Project/Account.h"
#include "../Course_Project/Transaction.h"
#include "../Course_Project/Branch.h"

void sortClientsByName(Client* clients, int numClients);
void sortClientByPhone(Client* clients, int numClients);
void sortClientByEmail(Client* clients, int numClients);

void sortEmployeesByName(Employee* employees, int numEmployees);
void sortEmployeeByLevel(Employee* employees, int numEmployees);
void sortEmployeeByDepartment(Employee* employees, int numEmployees);

void sortAccountsByBalance(Account* accounts, int numAccounts);
void sortAccountsByType(Account* accounts, int numAccounts);
void sortAccountsByCurrency(Account* accounts, int numAccounts);

void sortTransactionsByDate(Transaction* transactions, int numTransactions);
void sortTransactionsByAmount(Transaction* transactions, int numTransactions);
void sortTransactionsByType(Transaction* transactions, int numTransactions);

void sortBranchesByName(Branch* branches, int numBranches);
void sortBranchesByRegion(Branch* branches, int numBranches);
void sortBranchesBySize(Branch* branches, int numBranches);

#endif
