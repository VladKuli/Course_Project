#pragma once
#ifndef DATASORT_H
#define DATASORT_H

#include "../models/Client.h"
#include "../models/Employee.h"
#include "../models/Account.h"
#include "../models/Transaction.h"
#include "../models/Branch.h"

void sortClientsByName(Client* clients, int numClients);
void sortEmployeesByName(Employee* employees, int numEmployees);
void sortAccountsByBalance(Account* accounts, int numAccounts);
void sortTransactionsByDate(Transaction* transactions, int numTransactions);
void sortBranchesByName(Branch* branches, int numBranches);

#endif
