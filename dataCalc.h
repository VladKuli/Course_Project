#pragma once
#ifndef DATACALC_H
#define DATACALC_H

#include "../Course_Project/Client.h"
#include "../Course_Project/Employee.h"
#include "../Course_Project/Branch.h"
#include "../Course_Project/Account.h"
#include "../Course_Project/Transaction.h"

int calculateTotalClients(Client* clients, int numClients);
int calculateClientsByLevel(Client* clients, int numClients, ClientLevel level);
int clalculateEmployeesByRole(Employee* employees, int numEmployees, EmployeeRole role);

int calculateTotalEmployees(Employee* employees, int numEmployees);
int calculateEmployeesByRole(Employee* employees, int numEmployees, EmployeeRole role);
int calculateEmployeesByLevel(Employee* employees, int numEmployees, EmployeeLevel level);

int calculateTotalBranches(Branch* branches, int numBranches);
int calculateBranchesByRegion(Branch* branches, int numBranches, BranchRegion region);
int calculateBranchesByType(Branch* branches, int numBranches, BranchType type);

int calculateTotalAccounts(Account* accounts, int numAccounts);
int calculateAccountsByType(Account* accounts, int numAccounts, AccountType type);
int calculateAccountsByCurrency(Account* accounts, int numAccounts, const char* currency);

int calculateTotalTransactions(Transaction* transactions, int numTransactions);
int calculateTransactionsByType(Transaction* transactions, int numTransactions, TransactionType type);
int calculateTransactionsByDate(Transaction* transactions, int numTransactions, time_t date);

#endif
