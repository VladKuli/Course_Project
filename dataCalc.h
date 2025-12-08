#pragma once
#ifndef DATACALC_H
#define DATACALC_H

#include "../Course_Project/Client.h"
#include "../Course_Project/Employee.h"
#include "../Course_Project/Branch.h"

int calculateTotalClients(Client* clients, int numClients);
int calculateTotalEmployees(Employee* employees, int numEmployees);
int calculateTotalBranches(Branch* branches, int numBranches);

#endif
