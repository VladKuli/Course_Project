#include "dataEdit.h"
#include "numberValidationHelper.h"

#include <cstring>
#include <iostream>

using namespace std;

void editClient(Client& client) {
    cout << "Editing Client ID: " << client.id << endl;

    cout << "Enter new name: ";
    cin.getline(client.name, 50);

    cout << "Enter new address: ";
    cin.getline(client.address, 100);

    cout << "Enter new phone: ";
    cin.getline(client.phone, 15);

    cout << "Enter new email: ";
    cin.getline(client.email, 50);

    cout << "Current type: " << (client.type == INDIVIDUAL
        ? "Individual" 
        : "Company")
 << endl;

    int typeChoice;
    do {
        getValidatedInput(typeChoice, "Select new type (1. Individual, 2. Company): ");
        if (typeChoice < 1 || typeChoice > 2) {
            cout << "Invalid choice. Please enter 1 or 2.\n";
        }
    } while (typeChoice < 1 || typeChoice > 2);
    client.type = (typeChoice == 1) 
        ? INDIVIDUAL 
        : COMPANY;

    cout << "Current level: ";
    switch (client.level) {
    case REGULAR: cout << "Regular"; break;
    case PREMIUM: cout << "Premium"; break;
    case VIP:     cout << "VIP"; break;
    }
    cout << endl;
    int levelChoice;
    do {
        getValidatedInput(levelChoice, "Select new level (1. Regular, 2. Premium, 3. VIP): ");
        if (levelChoice < 1 || levelChoice > 3) {
            cout << "Invalid choice. Please enter a number between 1 and 3.\n";
        }
    } while (levelChoice < 1 || levelChoice > 3);
    switch (levelChoice) {
    case 1: client.level = REGULAR; break;
    case 2: client.level = PREMIUM; break;
    case 3: client.level = VIP; break;
    }
}


void editEmployee(Employee& employee) {
    cout << "Editing Employee ID: " << employee.id << endl;

    cout << "Enter new name: "; 
    cin.getline(employee.name, 50);

    cout << "Enter new position: "; 
    cin.getline(employee.position, 50);

    cout << "Enter new email: "; 
    cin.getline(employee.email, 50);

    cout << "Enter new phone: "; 
    cin.getline(employee.phone, 15);
}

void editAccount(Account& account) {
    cout << "Editing Account ID: " << account.id << endl;

    getValidatedInput(account.number, "Enter new number: ");

    double newBalance;
    do {
        getValidatedInput(newBalance, "Enter new balance: ");
        if (newBalance < 0) {
            cout << "Balance cannot be negative. Please enter 0 or greater.\n";
        }
    } while (newBalance < 0);
    account.balance = newBalance;
}



void editBranch(Branch& branch) {
    cout << "Editing Branch ID: " << branch.id << endl;

    cout << "Enter new name: ";
    cin.getline(branch.name, 50);

    cout << "Enter new address: ";
    cin.getline(branch.address, 100);

    cout << "Enter new phone: ";
    cin.getline(branch.phone, 15);

    cout << "Enter new email: ";
    cin.getline(branch.email, 50);

    cout << "Current size: ";
    switch (branch.size) {
    case SMALL:  cout << "Small"; break;
    case MEDIUM: cout << "Medium"; break;
    case LARGE:  cout << "Large"; break;
    }
    cout << endl;

    int sizeChoice;
    do {
        getValidatedInput(sizeChoice, "Select new size (1. Small, 2. Medium, 3. Large): ");
        if (sizeChoice < 1 || sizeChoice > 3) {
            cout << "Invalid choice. Please enter a number between 1 and 3.\n";
        }
    } while (sizeChoice < 1 || sizeChoice > 3);

    switch (sizeChoice) {
    case 1: branch.size = SMALL; break;
    case 2: branch.size = MEDIUM; break;
    case 3: branch.size = LARGE; break;
    }
}

