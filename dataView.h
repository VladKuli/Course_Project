#pragma once
#ifndef DATAVIEW_H
#define DATAVIEW_H


#include "../"
#include "../models/Employee.h"
#include "../models/Account.h"
#include "../models/Transaction.h"
#include "../models/Branch.h"

void viewClient(const Client& client);
void viewEmployee(const Employee& employee);
void viewAccount(const Account& account);
void viewTransaction(const Transaction& transaction);
void viewBranch(const Branch& branch);

#endif
