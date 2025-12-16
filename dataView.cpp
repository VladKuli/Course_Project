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
//TODO FIX SORTING (ADD ADMIN IN STATISTICS TOO)
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
    cout << "Account ID: " << a.id << ", Number: " << a.number << ", Balance: " << a.balance << "\n";
}
void viewBranch(const Branch& b) {
    cout << "Branch ID: " << b.id << ", Name: " << b.name << ", Address: " << b.address << "\n";
}

void viewAllData() {
    cout << "====================== All Clients with Accounts ======================\n\n";

    for (int i = 0; i < numClients; i++) {
        const Client& c = clients[i];
        cout << left << setw(10) << "ClientID" << setw(20) << "Name" << setw(25) << "Email"
            << setw(10) << "Type" << setw(10) << "Level" << "\n";
        cout << setw(10) << c.id << setw(20) << c.name << setw(25) << c.email
            << setw(10) << (c.type == INDIVIDUAL ? "Individual" : "Corporate")
            << setw(10) << (c.level == REGULAR ? "Regular" : (c.level == PREMIUM ? "Premium" : "VIP"))
            << "\n";

        Branch* b = searchBranchById(branches, numBranches, c.branchId);
        if (b) {
            cout << "  Branch: " << b->name << ", Address: " << b->address << "\n";
        }
    }
}
