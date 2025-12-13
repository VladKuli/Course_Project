#include "../Course_Project/dataEdit.h"
#include <cstring>
#include <iostream>

using namespace std;

void editClient(Client& client) {
    cout << "Editing Client ID: " << client.id << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter new name: "; 
    cin.getline(client.name, 50);

    cout << "Enter new address: "; 
    cin.getline(client.address, 100);

    cout << "Enter new phone: "; 
    cin.getline(client.phone, 15);

    cout << "Enter new email: "; 
    cin.getline(client.email, 50);
}

void editEmployee(Employee& employee) {
    cout << "Editing Employee ID: " << employee.id << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter new number: "; 
    cin >> account.number; cin.ignore();

    cout << "Enter new balance: "; 
    cin >> account.balance; cin.ignore();
}

void editTransaction(Transaction& transaction) {
    cout << "Editing Transaction ID: " << transaction.id << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter new amount: "; 
    cin >> transaction.amount; cin.ignore();

    cout << "Enter new purpose: "; 
    cin.getline(transaction.purpose, 100);
}

void editBranch(Branch& branch) {
    cout << "Editing Branch ID: " << branch.id << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter new name: "; 
    cin.getline(branch.name, 50);

    cout << "Enter new address: "; 
    cin.getline(branch.address, 100);

    cout << "Enter new phone: "; 
    cin.getline(branch.phone, 15);

    cout << "Enter new email: ";
    cin.getline(branch.email, 50);
}
