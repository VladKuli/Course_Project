#include "../Course_Project/menu.h"
#include "../Course_Project/dataView.h"
#include "../Course_Project/dataEdit.h"
#include "../Course_Project/dataSearch.h"
#include "../Course_Project/dataSort.h"
#include "../Course_Project/dataCalc.h"
#include "../Course_Project/fileIO.h"
#include <iostream>

using namespace std;

// Динамические массивы
Client* clients = nullptr;
int numClients = 0;

Employee* employees = nullptr;
int numEmployees = 0;

Account* accounts = nullptr;
int numAccounts = 0;

Transaction* transactions = nullptr;
int numTransactions = 0;

Branch* branches = nullptr;
int numBranches = 0;

// ---------------- ADD / VIEW / EDIT ----------------
void addClient() {
    Client c;
    c.id = numClients + 1;
    cin.ignore();
    cout << "Enter client name: "; cin.getline(c.name, 50);
    cout << "Enter address: "; cin.getline(c.address, 100);
    cout << "Enter phone: "; cin.getline(c.phone, 15);
    cout << "Enter email: "; cin.getline(c.email, 50);
    c.accountId = 0;
    c.type = INDIVIDUAL;
    c.level = REGULAR;

    Client* tmp = new Client[numClients + 1];
    for (int i = 0; i < numClients; i++) tmp[i] = clients[i];
    tmp[numClients] = c;
    delete[] clients;
    clients = tmp;
    numClients++;
    cout << "Client added.\n";
}

void viewAllClients() {
    for (int i = 0; i < numClients; i++) viewClient(clients[i]);
}

void handleClientMenu() {
    int choice;
    do {
        displayClientMenu();
        cout << "Enter choice: "; cin >> choice;
        switch (choice) {
        case 1: addClient(); break;
        case 2: viewAllClients(); break;
        case 3: {
            long id; cout << "Enter ID to edit: "; cin >> id;
            Client* c = searchClientById(clients, numClients, id);
            if (c) editClient(*c); else cout << "Not found\n";
            break;
        }
        case 4: {
            char name[50]; cin.ignore();
            cout << "Enter name to search: "; cin.getline(name, 50);
            Client* c = searchClientByName(clients, numClients, name);
            if (c) viewClient(*c); else cout << "Not found\n";
            break;
        }
        case 5: sortClientsByName(clients, numClients); cout << "Sorted by name\n"; break;
        case 0: break;
        default: cout << "Invalid\n";
        }
    } while (choice != 0);
}

// ---------------- Employee ----------------
void handleEmployeeMenu() {
    int choice;
    do {
        displayEmployeeMenu();
        cout << "Enter choice: "; cin >> choice;
        switch (choice) {
        case 0: break;
        default: cout << "Employee menu not implemented yet.\n";
        }
    } while (choice != 0);
}

// ---------------- MAIN ----------------
int main() {
    // Загрузка данных из файлов
    loadClients("clients.dat", &clients, &numClients);
    loadEmployees("employees.dat", &employees, &numEmployees);
    loadAccounts("accounts.dat", &accounts, &numAccounts);
    loadTransactions("transactions.dat", &transactions, &numTransactions);
    loadBranches("branches.dat", &branches, &numBranches);

    int choice;
    do {
        displayMainMenu();
        cout << "Enter choice: "; cin >> choice;
        switch (choice) {
        case 1: handleClientMenu(); break;
        case 2: handleEmployeeMenu(); break;
        case 3: cout << "Account menu not implemented yet.\n"; break;
        case 4: cout << "Transaction menu not implemented yet.\n"; break;
        case 5: cout << "Branch menu not implemented yet.\n"; break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice\n";
        }
    } while (choice != 0);

    // Сохранение данных
    saveClients("clients.dat", clients, numClients);
    saveEmployees("employees.dat", employees, numEmployees);
    saveAccounts("accounts.dat", accounts, numAccounts);
    saveTransactions("transactions.dat", transactions, numTransactions);
    saveBranches("branches.dat", branches, numBranches);

    delete[] clients;
    delete[] employees;
    delete[] accounts;
    delete[] transactions;
    delete[] branches;

    return 0;
}
