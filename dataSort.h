#pragma once
#ifndef DATASORT_H
#define DATASORT_H

#include "../Course_Project/Client.h"
#include "../Course_Project/Employee.h"
#include "../Course_Project/Account.h"
#include "../Course_Project/Branch.h"

void sortClientsByName(Client* clients, int numClients);
void sortClientByPhone(Client* clients, int numClients);
void sortClientByEmail(Client* clients, int numClients);

void sortEmployeesByName(Employee* employees, int numEmployees);
void sortEmployeeByLevel(Employee* employees, int numEmployees);
void sortEmployeesByRole(Employee* employees, int numEmployees);

void sortAccountsByBalance(Account* accounts, int numAccounts);
void sortAccountsByType(Account* accounts, int numAccounts);
void sortAccountsByCurrency(Account* accounts, int numAccounts);

void sortBranchesByName(Branch* branches, int numBranches);
void sortBranchesBySize(Branch* branches, int numBranches);
void sortBranchesByClientCount(Branch* branches, int numBranches);

#endif
