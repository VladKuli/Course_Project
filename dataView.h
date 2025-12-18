#pragma once
#ifndef DATAVIEW_H
#define DATAVIEW_H

#include "Client.h"
#include "Employee.h"
#include "Account.h"
#include "Branch.h"

extern Client* clients;
extern int numClients;
extern Employee* employees;
extern int numEmployees;
extern Account* accounts;
extern int numAccounts;
extern int numTransactions;
extern Branch* branches;
extern int numBranches;

void viewClient(const Client& client);
void viewEmployee(const Employee& employee);
void viewAccount(const Account& account);
void viewBranch(const Branch& branch);

#endif
