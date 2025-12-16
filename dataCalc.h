#pragma once
#ifndef DATACALC_H
#define DATACALC_H

#include "../Course_Project/Client.h"
#include "../Course_Project/Employee.h"
#include "../Course_Project/Branch.h"
#include "../Course_Project/Account.h"

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
