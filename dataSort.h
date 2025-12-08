#pragma once
#ifndef DATASORT_H
#define DATASORT_H

#include "../Course_Project/Client.h"
#include "../Course_Project/Employee.h"
#include "../Course_Project/Account.h"
#include "../Course_Project/Transaction.h"
#include "../Course_Project/Branch.h"

void sortClientsByName(Client* clients, int numClients);
void sortEmployeesByName(Employee* employees, int numEmployees);
void sortAccountsByBalance(Account* accounts, int numAccounts);
void sortTransactionsByDate(Transaction* transactions, int numTransactions);
void sortBranchesByName(Branch* branches, int numBranches);

#endif
