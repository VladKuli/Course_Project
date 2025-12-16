#include "../Course_Project/dataView.h"
#include "../Course_Project/dataSearch.h"

#include <iostream>
#include <iomanip>

using namespace std;


extern Client* clients;
extern int numClients;
extern Branch* branches;
extern int numBranches;
extern Account* accounts;
extern int numAccounts;
extern Employee* employees;
extern int numEmployees;


void viewClient(const Client& c) {
    cout << "-------------------- Client Information --------------------\n";
    cout << "ID:        " << c.id << "\n";
    cout << "Name:      " << c.name << "\n";
    cout << "Address:   " << c.address << "\n";
    cout << "Phone:     " << c.phone << "\n";
    cout << "Email:     " << c.email << "\n";
    cout << "Type:      " << (c.type == INDIVIDUAL ? "Individual" : "Company") << "\n";
    cout << "Level:     ";
    switch (c.level) {
    case REGULAR: cout << "Regular"; break;
    case PREMIUM: cout << "Premium"; break;
    case VIP:     cout << "VIP"; break;
    default:      cout << "Unknown"; break;
    }
    cout << "\n";

    // Show Branch info
    Branch* b = searchBranchById(branches, numBranches, c.branchId);
    if (b) {
        cout << "Branch:    " << b->name << " (ID: " << b->id << ")\n";
        cout << "           " << b->address << ", Phone: " << b->phone << ", Email: " << b->email << "\n";
    }
    else {
        cout << "Branch:    Not found\n";
    }

    // Show Account info
    bool foundAccount = false;
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].clientId == c.id) {
            cout << "Account:   ID: " << accounts[i].id
                << ", Number: " << accounts[i].number
                << ", Balance: " << accounts[i].balance << "\n";
            foundAccount = true;
            break;
        }
    }
    if (!foundAccount) {
        cout << "Account:   Not found\n";
    }

    cout << "-----------------------------------------------------------\n";
}
void viewEmployee(const Employee& e) {
    cout << "-------------------- Employee Information --------------------\n";
    cout << "ID:        " << e.id << "\n";
    cout << "Name:      " << e.name << "\n";
    cout << "Position:  " << e.position << "\n";
    cout << "Branch ID: " << e.branchId << "\n";
    cout << "Email:     " << e.email << "\n";
    cout << "Phone:     " << e.phone << "\n";
    cout << "Role:      ";
    switch (e.role) {
    case TELLER:  cout << "Teller"; break;
    case MANAGER: cout << "Manager"; break;
    case ADMIN:   cout << "Admin"; break;
    default:      cout << "Unknown"; break;
    }
    cout << "\n";

    // Show Branch info
    Branch* b = searchBranchById(branches, numBranches, e.branchId);
    if (b) {
        cout << "Branch:    " << b->name << " (ID: " << b->id << ")\n";
        cout << "           " << b->address << ", Phone: " << b->phone << ", Email: " << b->email << "\n";
    }
    else {
        cout << "Branch:    Not found\n";
    }

    cout << "-------------------------------------------------------------\n";
}

void viewAccount(const Account& a) {
    cout << "-------------------- Account Information --------------------\n";
    cout << "Account ID:   " << a.id << "\n";
    cout << "Number:       " << a.number << "\n";
    cout << "Balance:      " << a.balance << "\n";
    cout << "Client ID:    " << a.clientId << "\n";

    Client* c = nullptr;
    for (int i = 0; i < numClients; ++i) {
        if (clients[i].id == a.clientId) {
            c = &clients[i];
            break;
        }
    }
    if (c) {
        cout << "Client Name:  " << c->name << "\n";
        cout << "Client Email: " << c->email << "\n";
    }
    else {
        cout << "Client:       Not found\n";
    }

    cout << "------------------------------------------------------------\n";
}

void viewBranch(const Branch& b) {
    cout << "-------------------- Branch Information --------------------\n";
    cout << "ID:        " << b.id << "\n";
    cout << "Name:      " << b.name << "\n";
    cout << "Address:   " << b.address << "\n";
    cout << "Phone:     " << b.phone << "\n";
    cout << "Email:     " << b.email << "\n";
    cout << "Size:      ";
    switch (b.size) {
    case SMALL:  cout << "Small"; break;
    case MEDIUM: cout << "Medium"; break;
    case LARGE:  cout << "Large"; break;
    default:     cout << "Unknown"; break;
    }
    cout << "\n";

    int clientCount = 0;
    for (int i = 0; i < numClients; ++i) {
        if (clients[i].branchId == b.id) { 
            clientCount++;
        }
    }

    int employeeCount = 0;
    for (int i = 0; i < numEmployees; ++i) {
        if (employees[i].branchId == b.id) {
            employeeCount++;
        }
    }

    cout << "Employees: " << employeeCount << "\n";
    cout << "Clients:   " << clientCount << "\n";
    cout << "-----------------------------------------------------------\n";
}




