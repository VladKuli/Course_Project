#pragma once
#ifndef DATAEDIT_H
#define DATAEDIT_H

#include "../Course_Project/Client.h"
#include "../Course_Project/Employee.h"
#include "../Course_Project/Account.h"
#include "../Course_Project/Transaction.h"
#include "../Course_Project/Branch.h"

void editClient(Client& client);
void editEmployee(Employee& employee);
void editAccount(Account& account);
void editTransaction(Transaction& transaction);
void editBranch(Branch& branch);

#endif
