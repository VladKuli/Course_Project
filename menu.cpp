#include <iostream>
#include "../Course_Project/menu.h"
using namespace std;

void displayMainMenu() {
    cout << endl;
    cout << "==== Main Menu ====\n";
    cout << "1. Clients\n";
    cout << "2. Employees\n";
    cout << "3. Accounts\n";
    cout << "4. Transactions\n";
    cout << "5. Branches\n";
    cout << "0. Exit\n";
}

void displayClientMenu() {
    cout << endl;
    cout << "---- Client Menu ----\n";
    cout << "1. Add Client\n";
    cout << "2. View All Clients\n";
    cout << "3. Edit Client\n";
    cout << "4. Search Client\n";
    cout << "5. Sort Clients by Name\n";
    cout << "0. Back to Main Menu\n";
}

void displayEmployeeMenu() {
    cout << endl;
    cout << "---- Employee Menu ----\n";
    cout << "1. Add Employee\n";
    cout << "2. View All Employees\n";
    cout << "3. Edit Employee\n";
    cout << "4. Search Employee\n";
    cout << "5. Sort Employees by Name\n";
    cout << "0. Back to Main Menu\n";
}

void displayAccountMenu() {
    cout << endl;
    cout << "---- Account Menu ----\n";
    cout << "1. Add Account\n";
    cout << "2. View All Accounts\n";
    cout << "3. Edit Account\n";
    cout << "4. Search Account\n";
    cout << "5. Sort Accounts by Balance\n";
    cout << "0. Back to Main Menu\n";
}

void displayTransactionMenu() {
	cout << endl;
    cout << "---- Transaction Menu ----\n";
    cout << "1. Add Transaction\n";
    cout << "2. View All Transactions\n";
    cout << "3. Edit Transaction\n";
    cout << "4. Search Transaction\n";
    cout << "5. Sort Transactions by Date\n";
    cout << "0. Back to Main Menu\n";
}

void displayBranchMenu() {
	cout << endl;
    cout << "---- Branch Menu ----\n";
    cout << "1. Add Branch\n";
    cout << "2. View All Branches\n";
    cout << "3. Edit Branch\n";
    cout << "4. Search Branch\n";
    cout << "5. Sort Branches by Name\n";
    cout << "0. Back to Main Menu\n";
}
