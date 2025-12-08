#pragma once
#ifndef MENU_H
#define MENU_H

#include "../../models/Client.h"
#include "../../models/Employee.h"
#include "../../models/Account.h"
#include "../../models/Transaction.h"
#include "../../models/Branch.h"
#include "../../services/dataCalc.h"
#include "../../services/dataView.h"
#include "../../services/dataEdit.h"
#include "../../services/dataSearch.h"
#include "../../services/dataSort.h"
#include "../../io/fileIO.h"

// --------------------- DISPLAY MENUS ---------------------
void displayMainMenu();
void displayClientMenu();
void displayEmployeeMenu();
void displayAccountMenu();
void displayTransactionMenu();
void displayBranchMenu();

// --------------------- HANDLERS ---------------------
void handleClientMenu(Client** clients, int* numClients);
void handleEmployeeMenu(Employee** employees, int* numEmployees);
void handleAccountMenu(Account** accounts, int* numAccounts);
void handleTransactionMenu(Transaction** transactions, int* numTransactions);
void handleBranchMenu(Branch** branches, int* numBranches);

void handleLoadData(Client** clients, int* numClients,
    Employee** employees, int* numEmployees,
    Account** accounts, int* numAccounts,
    Transaction** transactions, int* numTransactions,
    Branch** branches, int* numBranches);

void handleSaveData(Client* clients, int numClients,
    Employee* employees, int numEmployees,
    Account* accounts, int numAccounts,
    Transaction* transactions, int numTransactions,
    Branch* branches, int numBranches);

void handleCalculateData(Client* clients, int numClients,
    Employee* employees, int numEmployees,
    Branch* branches, int numBranches);

void handleSortData(Client* clients, int numClients,
    Employee* employees, int numEmployees,
    Account* accounts, int numAccounts,
    Transaction* transactions, int numTransactions,
    Branch* branches, int numBranches);

// --------------------- MENU LOOP & PAUSE ---------------------
void runMenu(Client** clients, int* numClients,
    Employee** employees, int* numEmployees,
    Account** accounts, int* numAccounts,
    Transaction** transactions, int* numTransactions,
    Branch** branches, int* numBranches);

void pause();

#endif
