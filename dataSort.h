#pragma once
#ifndef DATASORT_H
#define DATASORT_H

#include "Client.h"
#include "Employee.h"
#include "Account.h"
#include "Branch.h"

void sortClientsByName(Client* clients, int numClients);
void sortClientByPhone(Client* clients, int numClients);
void sortClientByEmail(Client* clients, int numClients);

void sortEmployeesByName(Employee* employees, int numEmployees);
void sortEmployeesByRole(Employee* employees, int numEmployees);

void sortAccountsByBalance(Account* accounts, int numAccounts);

void sortBranchesByName(Branch* branches, int numBranches);
void sortBranchesBySize(Branch* branches, int numBranches);
void sortBranchesByClientCount(Branch* branches, int numBranches, const Client* clients, int numClients);
int countClientsForBranch(const Branch& branch, const Client* clients, int numClients);
#endif
