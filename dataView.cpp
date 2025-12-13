#include "../Course_Project/dataView.h"
#include "../Course_Project/dataSearch.h"

#include <iostream>
#include <iomanip>

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

void viewAllData() {
    cout << "====================== All Clients with Accounts and Transactions ======================\n\n";

    for (int i = 0; i < numClients; i++) {
        const Client& c = clients[i];
        cout << left << setw(10) << "ClientID" << setw(20) << "Name" << setw(25) << "Email"
            << setw(10) << "Type" << setw(10) << "Level" << "\n";
        cout << setw(10) << c.id << setw(20) << c.name << setw(25) << c.email
            << setw(10) << (c.type == INDIVIDUAL ? "Individual" : "Corporate")
            << setw(10) << (c.level == REGULAR ? "Regular" : (c.level == PREMIUM ? "Premium" : "VIP"))
            << "\n";

        // Показать филиал
        Branch* b = searchBranchById(branches, numBranches, c.branchId);
        if (b) {
            cout << "  Branch: " << b->name << ", Address: " << b->address << "\n";
        }

        // Показать счета клиента
        for (int j = 0; j < numAccounts; j++) {
            const Account& a = accounts[j];
            if (a.clientId == c.id) {
                cout << "  " << left << setw(10) << "AccountID" << setw(15) << "Number"
                    << setw(10) << "Balance" << setw(10) << "Currency" << setw(10) << "Type" << "\n";
                cout << "  " << setw(10) << a.id << setw(15) << a.number << setw(10) << a.balance
                    << setw(10) << a.currency << setw(10) << (a.type == SAVINGS ? "Savings" : "Checking") << "\n";

                // Показать транзакции
                for (int k = 0; k < numTransactions; k++) {
                    const Transaction& t = transactions[k];
                    if (t.senderAccountId == a.number || t.recipientAccountId == a.number) {
                        cout << "    " << left << setw(15) << "TransactionID" << setw(10) << "Amount"
                            << setw(50) << "Purpose" << "\n";
                        cout << "    " << setw(15) << t.id << setw(10) << t.amount << setw(50) << t.purpose << "\n";
                    }
                }
            }
        }
        cout << "--------------------------------------------------------------------------------------\n";
    }

    // Сотрудники по филиалам
    cout << "\n====================== Employees by Branch ======================\n\n";
    for (int i = 0; i < numBranches; i++) {
        const Branch& b = branches[i];
        cout << "Branch: " << b.name << " (ID: " << b.id << ")\n";
        cout << left << setw(10) << "EmpID" << setw(20) << "Name" << setw(15) << "Position" << setw(10) << "Level" << "\n";
        for (int j = 0; j < numEmployees; j++) {
            const Employee& e = employees[j];
            if (e.branchId == b.id) {
                cout << setw(10) << e.id << setw(20) << e.name << setw(15) << e.position
                    << setw(10) << (e.level == JUNIOR ? "Junior" : e.level == MID ? "Mid" : "Senior") << "\n";
            }
        }
        cout << "------------------------------------------------------\n";
    }
}