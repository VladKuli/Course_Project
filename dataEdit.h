#pragma once
#ifndef DATAEDIT_H
#define DATAEDIT_H

#include "../models/Client.h"
#include "../models/Employee.h"
#include "../models/Account.h"
#include "../models/Transaction.h"
#include "../models/Branch.h"

void editClient(Client& client);
void editEmployee(Employee& employee);
void editAccount(Account& account);
void editTransaction(Transaction& transaction);
void editBranch(Branch& branch);

#endif
