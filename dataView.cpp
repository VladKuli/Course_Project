#include "../Course_Project/dataView.h"
#include <iostream>
using namespace std;

void viewClient(const Client& c) {
    cout << "Client ID: " << c.id << ", Name: " << c.name << ", Email: " << c.email << "\n";
}
void viewEmployee(const Employee& e) {
    cout << "Employee ID: " << e.id << ", Name: " << e.name << ", Position: " << e.position << "\n";
}
void viewAccount(const Account& a) {
    cout << "Account ID: " << a.id << ", Number: " << a.number << ", Balance: " << a.balance << "\n";
}
void viewTransaction(const Transaction& t) {
    cout << "Transaction ID: " << t.id << ", Amount: " << t.amount << ", Purpose: " << t.purpose << "\n";
}
void viewBranch(const Branch& b) {
    cout << "Branch ID: " << b.id << ", Name: " << b.name << ", Address: " << b.address << "\n";
}
