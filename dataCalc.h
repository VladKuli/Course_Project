#pragma once
#ifndef DATACALC_H
#define DATACALC_H

#include "../models/Client.h"
#include "../models/Employee.h"
#include "../models/Branch.h"

int calculateTotalClients(Client* clients, int numClients);
int calculateTotalEmployees(Employee* employees, int numEmployees);
int calculateTotalBranches(Branch* branches, int numBranches);

#endif
