#pragma once
#ifndef DATAVIEW_H
#define DATAVIEW_H

#include "../Course_Project/Client.h"
#include "../Course_Project/Employee.h"
#include "../Course_Project/Account.h"
#include "../Course_Project/Transaction.h"
#include "../Course_Project/Branch.h"

void viewClient(const Client& client);
void viewEmployee(const Employee& employee);
void viewAccount(const Account& account);
void viewTransaction(const Transaction& transaction);
void viewBranch(const Branch& branch);

#endif
