#pragma once
#ifndef DATACALC_H
#define DATACALC_H

#include "Client.h"
#include "Employee.h"
#include "Branch.h"
#include "Account.h"

int calculateTotalClients(Client* clients, int numClients);
int calculateClientsByLevel(Client* clients, int numClients, ClientLevel level);
int calculateClientsByType(Client* clients, int numClients, ClientType type);

int calculateTotalEmployees(Employee* employees, int numEmployees);
int calculateEmployeesByRole(Employee* employees, int numEmployees, EmployeeRole role);

int calculateTotalBranches(Branch* branches, int numBranches);
int calculateBranchesBySize(Branch* branches, int numBranches, BranchSize size);
int calculateBranchesByClientCount(Branch* branches, int numBranches, int minClients);


int calculateTotalAccounts(Account* accounts, int numAccounts);

#endif
