#pragma once
#ifndef MENU_H
#define MENU_H

#include "../Course_Project/Client.h"
#include "../Course_Project/Employee.h"
#include "../Course_Project/Account.h"
#include "../Course_Project/Transaction.h"
#include "../Course_Project/Branch.h"
#include "../Course_Project/dataCalc.h"
#include "../Course_Project/dataView.h"
#include "../Course_Project/dataEdit.h"
#include "../Course_Project/dataSearch.h"
#include "../Course_Project/dataSort.h"
#include "../Course_Project/fileIO.h"

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
