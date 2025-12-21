#include "menu.h"
#include "dataView.h"
#include "dataEdit.h"
#include "dataSearch.h"
#include "dataSort.h"
#include "dataCalc.h"
#include "deleteData.h"
#include "fileIO.h"
#include "numberValidationHelper.h"

#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

Client* clients = nullptr;
int numClients = 0;

Employee* employees = nullptr;
int numEmployees = 0;

Account* accounts = nullptr;
int numAccounts = 0;

Branch* branches = nullptr;
int numBranches = 0;

void handleClientMenu() {
    int choice;
    do {
        displayClientMenu();

        cout << "\n";
		cout << "----------------\n";
        getValidatedInput(choice, "Your choice: ");

        switch (choice) {
        case 1: { // ADD
            if (numBranches == 0) {
                cout << "No branches available. Please add a branch first.\n";
                break;
            }
			cout << "\n";
            Client c;
            c.id = numClients + 1;
            cout << "Available branches:\n";
            for (int i = 0; i < numBranches; ++i) {
                cout << "  " << branches[i].id << ". " << branches[i].name << " (" << branches[i].address << ")\n";
            }

            long branchId;
            bool validBranch = false;
            do {
                getValidatedInput(branchId, "Enter branch ID for this client: ");
                
                // Check if branch ID exists
                validBranch = false;
                for (int i = 0; i < numBranches; ++i) {
                    if (branches[i].id == branchId) {
                        validBranch = true;
                        break;
                    }
                }
                
                if (!validBranch) {
                    cout << "Invalid branch ID. Please select from the available branches." << endl;
                }
            } while (!validBranch);
            
            c.branchId = branchId;

            cout << "Name: ";
            cin.getline(c.name, 50);

            cout << "Address: ";
            cin.getline(c.address, 100);

            cout << "Phone: ";
            cin.getline(c.phone, 15);

            cout << "Email: ";
            cin.getline(c.email, 50);

            int typeChoice;
            do {
                getValidatedInput(typeChoice, "Type of the client (1. Individual, 2. Company): ");
                if (typeChoice < 1 || typeChoice > 2) {
                    cout << "Invalid choice. Please enter 1 or 2.\n";
                }
            } while (typeChoice < 1 || typeChoice > 2);

            c.type = (typeChoice == 1)
                ? INDIVIDUAL
                : COMPANY;

            int levelChoice;
            do {
                getValidatedInput(levelChoice, "Client level (1. Regular, 2. Premium, 3. VIP): ");
                if (levelChoice < 1 || levelChoice > 3) {
                    cout << "Invalid choice. Please enter a number between 1 and 3.\n";
                }
            } while (levelChoice < 1 || levelChoice > 3);

            if (levelChoice == 1) {
                c.level = REGULAR;
            }
            else if (levelChoice == 2) {
                c.level = PREMIUM;
            }
            else {
                c.level = VIP;
            }

            Client* tmp = new Client[numClients + 1];
            for (int i = 0; i < numClients; i++) {
                tmp[i] = clients[i];
            }
            tmp[numClients] = c;
            delete[] clients;
            clients = tmp;
            numClients++;

            cout << "Client added." << endl;

            Account a;
            a.id = numAccounts + 1;
            a.clientId = c.id;

            getValidatedInput(a.number, "\nAccount number: ");

            do {
                getValidatedInput(a.balance, "Initial balance: ");
                if (a.balance < 0) {
                    cout << "Balance cannot be negative. Please enter 0 or greater.\n";
                }
            } while (a.balance < 0);


            Account* atmp = new Account[numAccounts + 1];
            for (int i = 0; i < numAccounts; i++) {
                atmp[i] = accounts[i];
            }

            atmp[numAccounts] = a;
            delete[] accounts;
            accounts = atmp;
            numAccounts++;

            cout << "Account created and linked to client.\n";
            break;
        }
        case 2: { // VIEW ALL
            if (numClients == 0) {
                cout << "No client data available.\n";
                break;
            }
            for (int i = 0; i < numClients; i++) {
                viewClient(clients[i]);
            }
            break;
        }
        case 3: { // EDIT
            long id;

            getValidatedInput(id, "ID: ");

            Client* c = searchClientById(clients, numClients, id);

            if (c) {
                editClient(*c);
            }
            else {
                cout << "Not found\n";
            }
            break;
        }
        case 4: { // SEARCH
            int s;

            getValidatedInput(s, "Search: 1.ID 2.Name 3.Email: ");

            if (s == 1) {
                long id;

                getValidatedInput(id, "ID: ");

                Client* c = searchClientById(clients, numClients, id);

                if (c) {
                    viewClient(*c);
                }
                else {
                    cout << "Not found\n";
                }
            }
            else if (s == 2) {
                char name[50];

                cout << "Name: ";
                cin.getline(name, 50);

                Client* c = searchClientByName(clients, numClients, name);

                if (c) {
                    viewClient(*c);
                }
                else {
                    cout << "Not found\n";
                }
            }
            else if (s == 3) {
                char email[50];

                cout << "Email: ";
                cin.getline(email, 50);

                Client* c = searchClientByEmail(clients, numClients, email);

                if (c) {
                    viewClient(*c);
                }
                else {
                    cout << "Not found\n";
                }
            }
            break;
        }
        case 5: { // SORT
            if (numClients == 0) {
                cout << "No client data to sort.\n";
                break;
            }
            int sortChoice;

            getValidatedInput(sortChoice, "Sort: 1.Name 2.Phone 3.Email: ");

            if (sortChoice == 1) {
                sortClientsByName(clients, numClients);
            }
            else if (sortChoice == 2) {
                sortClientByPhone(clients, numClients);
            }
            else if (sortChoice == 3) {
                sortClientByEmail(clients, numClients);
            }
            cout << "\nSorted list:\n";
            for (int i = 0; i < numClients; i++) {
                viewClient(clients[i]);
            }
            break;
        }
        case 6: { // DELETE
            int d;
            getValidatedInput(d, "Delete: 1.ID 2.Name 3.Email: ");

            bool result = false;

            if (d == 1) {
                long id;
                getValidatedInput(id, "ID: ");
                result = deleteClientById(clients, numClients, id);
            }
            else if (d == 2) {
                char name[50];
                cout << "Name: ";
                cin.getline(name, 50);
                result = deleteClientByName(clients, numClients, name);
            }
            else if (d == 3) {
                char email[50];
                cout << "Email: ";
                cin.getline(email, 50);
                result = deleteClientByEmail(clients, numClients, email);
            }
            cout << (result
                ? "Deleted.\n"
                : "Not found.\n");
            break;
        }
        case 7: { // CALCULATIONS
            cout << "Total: " << calculateTotalClients(clients, numClients) << endl;
            cout << "Regular: " << calculateClientsByLevel(clients, numClients, REGULAR) << endl;
            cout << "Premium: " << calculateClientsByLevel(clients, numClients, PREMIUM) << endl;
            cout << "VIP: " << calculateClientsByLevel(clients, numClients, VIP) << endl;
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid\n";
            break;
        }
    } while (choice != 0);
}

// ===================== EMPLOYEE MENU =====================
void handleEmployeeMenu() {
    int choice;

    do {
        displayEmployeeMenu();

        cout << "\n";
        cout << "----------------\n";
        getValidatedInput(choice, "Your choice: ");

        switch (choice) {
        case 1: { // ADD
            if (numBranches == 0) {
                cout << "No branches available. Please add a branch first.\n";
                break;
            }

            Employee e;
            e.id = numEmployees + 1;

            cout << "Available branches:\n";
            for (int i = 0; i < numBranches; ++i) {
                cout << "  " << branches[i].id << ". " << branches[i].name << " (" << branches[i].address << ")\n";
            }
            long branchId;

            bool validBranch = false;
            do {
                getValidatedInput(branchId, "Enter branch ID for this employee: ");
                
                // Check if branch ID exists
                validBranch = false;
                for (int i = 0; i < numBranches; ++i) {
                    if (branches[i].id == branchId) {
                        validBranch = true;
                        break;
                    }
                }
                
                if (!validBranch) {
                    cout << "Invalid branch ID. Please select from the available branches." << endl;
                }
            } while (!validBranch);
            
            e.branchId = branchId;

            cout << "Name: ";
            cin.getline(e.name, 50);

            cout << "Position: ";
            cin.getline(e.position, 50);

            cout << "Email: ";
            cin.getline(e.email, 50);

            cout << "Phone: ";
            cin.getline(e.phone, 15);

            int roleChoice;
            do {
                getValidatedInput(roleChoice, "Role (1. Teller, 2. Manager, 3. Admin): ");
                if (roleChoice < 1 || roleChoice > 3) {
                    cout << "Invalid choice. Please enter a number between 1 and 3.\n";
                }
            } while (roleChoice < 1 || roleChoice > 3);

            switch (roleChoice) {
            case 1: e.role = TELLER; break;
            case 2: e.role = MANAGER; break;
            case 3: e.role = ADMIN; break;
            }


            Employee* tmp = new Employee[numEmployees + 1];
            for (int i = 0; i < numEmployees; i++) {
                tmp[i] = employees[i];
            }

            tmp[numEmployees] = e;
            delete[] employees;
            employees = tmp;
            numEmployees++;

            cout << "Employee added.\n";
            break;
        }
        case 2: { // VIEW ALL
            if (numEmployees == 0) {
                cout << "No employees data available.\n";
                break;
            }
            for (int i = 0; i < numEmployees; i++) {
                viewEmployee(employees[i]);
            }
            break;
        }
        case 3: { // EDIT
            long id;

            getValidatedInput(id, "ID: ");

            Employee* e = searchEmployeeById(employees, numEmployees, id);

            if (e) {
                editEmployee(*e);
            }
            else {
                cout << "Not found\n";
            }
            break;
        }
        case 4: { // SEARCH
            int s;

            getValidatedInput(s, "Search: 1.ID 2.Name 3.Email: ");

            if (s == 1) {
                long id;
                getValidatedInput(id, "ID: ");

                Employee* e = searchEmployeeById(employees, numEmployees, id);

                if (e) {
                    viewEmployee(*e);
                }
                else {
                    cout << "Not found\n";
                }
            }
            else if (s == 2) {
                char name[50];
                cout << "Name: ";
                cin.getline(name, 50);

                Employee* e = searchEmployeeByName(employees, numEmployees, name);

                if (e) {
                    viewEmployee(*e);
                }
                else {
                    cout << "Not found\n";
                }
            }
            else if (s == 3) {
                char email[50];
                cout << "Email: ";
                cin.getline(email, 50);

                Employee* e = searchEmployeeByEmail(employees, numEmployees, email);

                if (e) {
                    viewEmployee(*e);
                }
                else {
                    cout << "Not found\n";
                }
            }
            break;
        }
        case 5: { // SORT
            if (numEmployees == 0) {
                cout << "No employee data to sort.\n";
                break;
            }
            int s;
            getValidatedInput(s, "Sort: 1.Name 2.Role: ");

            if (s == 1) {
                sortEmployeesByName(employees, numEmployees);
            }
            else if (s == 2) {
                sortEmployeesByRole(employees, numEmployees);
            }
            cout << "Sorted list:\n";

            for (int i = 0; i < numEmployees; i++) {
                viewEmployee(employees[i]);
            }
            break;
        }
        case 6: { // DELETE
            int d;
            getValidatedInput(d, "Delete: 1.ID 2.Name 3.Email: ");

            bool result = false;

            if (d == 1) {
                long id;
                getValidatedInput(id, "ID: ");
                result = deleteEmployeeById(employees, numEmployees, id);
            }
            else if (d == 2) {
                char name[50];
                cout << "Name: ";
                cin.getline(name, 50);
                result = deleteEmployeeByName(employees, numEmployees, name);
            }
            else if (d == 3) {
                char email[50];
                cout << "Email: ";
                cin.getline(email, 50);
                result = deleteEmployeeByEmail(employees, numEmployees, email);
            }
            cout << (result ? "Deleted.\n" : "Not found.\n");
            break;
        }
        case 7: { // CALCULATIONS
            cout << "Total employees: " << calculateTotalEmployees(employees, numEmployees) << endl;
            cout << "Managers: " << calculateEmployeesByRole(employees, numEmployees, MANAGER) << endl;
            cout << "Tellers: " << calculateEmployeesByRole(employees, numEmployees, TELLER) << endl;
            cout << "Admins: " << calculateEmployeesByRole(employees, numEmployees, ADMIN) << endl;
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid\n";
            break;
        }
    } while (choice != 0);
}

// ===================== ACCOUNT MENU =====================
void handleAccountMenu() {
    int choice;
    do {
        displayAccountMenu();

        cout << "\n";
        cout << "----------------\n";
        getValidatedInput(choice, "Your choice: ");

        switch (choice) {
        case 1: { // VIEW
            if (numAccounts == 0) {
                cout << "No Accounts data available.\n";
                break;
            }
            for (int i = 0; i < numAccounts; i++) {
                viewAccount(accounts[i]);
            }
            break;
        }
        case 2: { // EDIT
            long id;
            getValidatedInput(id, "ID: ");

            Account* a = searchAccountById(accounts, numAccounts, id);

            if (a) {
                editAccount(*a);
            }
            else {
                cout << "Not found\n";
            }
            break;
        }
        case 3: { // SEARCH
            int s;
            getValidatedInput(s, "Search: 1.ID 2.Number 3.ClientID: ");

            if (s == 1) {
                long id;
                getValidatedInput(id, "ID: ");

                Account* a = searchAccountById(accounts, numAccounts, id);

                if (a) {
                    viewAccount(*a);
                }
                else {
                    cout << "Not found\n";
                }
            }
            else if (s == 2) {
                int number;
                getValidatedInput(number, "Number: ");

                Account* a = searchAccountByNumber(accounts, numAccounts, number);

                if (a) {
                    viewAccount(*a);
                }
                else {
                    cout << "Not found\n";
                }
            }
            else if (s == 3) {
                long cid;
                getValidatedInput(cid, "Client ID: ");

                Account* a = searchAccountByClientId(accounts, numAccounts, cid);

                if (a) {
                    viewAccount(*a);
                }
                else {
                    cout << "Not found\n";
                }
            }
            break;
        }
        case 4: { // SORT
            if (numAccounts == 0) {
                cout << "No account data to sort.\n";
                break;
            }
            int s;
            getValidatedInput(s, "Sort: 1.Balance: ");

            if (s == 1) {
                sortAccountsByBalance(accounts, numAccounts);
            }
            cout << "Sorted list:\n";

            for (int i = 0; i < numAccounts; i++) {
                viewAccount(accounts[i]);
            }
            break;
        }
        case 5: { // DELETE
            int d;
            getValidatedInput(d, "Delete: 1.ID 2.Number: ");

            bool result = false;

            if (d == 1) {
                long id;
                getValidatedInput(id, "ID: ");
                result = deleteAccountById(accounts, numAccounts, id);
            }
            else if (d == 2) {
                int number;
                getValidatedInput(number, "Number: ");
                result = deleteAccountByNumber(accounts, numAccounts, number);
            }
            cout << (result ? "Deleted.\n" : "Not found.\n");
            break;
        }
        case 6: { // CALCULATIONS
            cout << "Total accounts: " << calculateTotalAccounts(accounts, numAccounts) << endl;
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid\n";
            break;
        }
    } while (choice != 0);
}

// ===================== BRANCH MENU =====================
void handleBranchMenu() {
    int choice;
    do {
        displayBranchMenu();

        cout << "\n";
        cout << "----------------\n";
        getValidatedInput(choice, "Your choice: ");

        switch (choice) {
        case 1: { // ADD
            Branch b;

            b.id = numBranches + 1;

            cout << "Name: ";
            cin.getline(b.name, 50);

            cout << "Address: ";
            cin.getline(b.address, 100);

            cout << "Phone: ";
            cin.getline(b.phone, 15);

            cout << "Email: ";
            cin.getline(b.email, 50);

            int sizeChoice;
            do {
                getValidatedInput(sizeChoice, "Branch size (1. Small, 2. Medium, 3. Large): ");
                if (sizeChoice < 1 || sizeChoice > 3) {
                    cout << "Invalid choice. Please enter a number between 1 and 3.\n";
                }
            } while (sizeChoice < 1 || sizeChoice > 3);

            switch (sizeChoice) {
            case 1: b.size = SMALL; break;
            case 2: b.size = MEDIUM; break;
            case 3: b.size = LARGE; break;
            }


            b.numClients = 0;
            b.numEmployees = 0;

            Branch* tmp = new Branch[numBranches + 1];
            for (int i = 0; i < numBranches; i++) {
                tmp[i] = branches[i];
            }
            tmp[numBranches] = b;
            delete[] branches;
            branches = tmp;
            numBranches++;

            cout << "Branch added.\n";
            break;
        }
        case 2: { // VIEW
            if (numBranches == 0) {
                cout << "No Branches data available.\n";
                break;
            }
            for (int i = 0; i < numBranches; i++) {
                viewBranch(branches[i]);
            }
            break;
        }
        case 3: { // EDIT
            long id;
            getValidatedInput(id, "ID: ");

            Branch* b = searchBranchById(branches, numBranches, id);
            
            if (b) {
                editBranch(*b);
            }
            else {
                cout << "Not found\n";
            }
            break;
        }
        case 4: { // SEARCH
            int s;
            getValidatedInput(s, "Search: 1.ID 2.Name: ");
            if (s == 1) {
                long id;
                getValidatedInput(id, "ID: ");
                Branch* b = searchBranchById(branches, numBranches, id);
                if (b) {
                    viewBranch(*b);
                }
                else {
                    cout << "Not found\n";
                }
            }
            else if (s == 2) {
                char name[50];
                cout << "Name: ";
                cin.getline(name, 50);
               
                Branch* b = searchBranchByName(branches, numBranches, name);
                
                if (b) {
                    viewBranch(*b);
                }
                else {
                    cout << "Not found\n";
                }
            }
            break;
        }
        case 5: { // SORT
            if (numBranches == 0) {
                cout << "No branch data to sort.\n";
                break;
            }

            int s;
            getValidatedInput(s, "Sort: 1.Name 2.Client count 3.Size: ");

            if (s == 1) {
                sortBranchesByName(branches, numBranches);
            }
            else if (s == 2) {
                sortBranchesByClientCount(branches, numBranches, clients, numClients);
            }
            else if (s == 3) {
                sortBranchesBySize(branches, numBranches);
            }
            cout << "\nSorted list:\n";
            for (int i = 0; i < numBranches; i++) {
                viewBranch(branches[i]);
            }
            break;
        }
        case 6: { // DELETE
            long id;
            getValidatedInput(id, "ID: ");

            bool result = deleteBranchById(branches, numBranches, id);

            cout << (result ? "Deleted.\n" : "Not found.\n");
            break;
        }
        case 7: { // CALC
            cout << "Total branches: " << calculateTotalBranches(branches, numBranches) << endl;
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid\n";
            break;
        }
    } while (choice != 0);
}

// ===================== MAIN =====================
int main() {
    loadClients("clients.dat", &clients, &numClients);
    loadEmployees("employees.dat", &employees, &numEmployees);
    loadAccounts("accounts.dat", &accounts, &numAccounts);
    loadBranches("branches.dat", &branches, &numBranches);

    int choice;
    do {
        displayMainMenu();
        cout << "----------------\n";
        getValidatedInput(choice, "Your choice: ");

        switch (choice) {
        case 1: handleClientMenu(); break;
        case 2: handleEmployeeMenu(); break;
        case 3: handleAccountMenu(); break;
        case 4: handleBranchMenu(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid\n"; break;
        }
    } while (choice != 0);

    saveClients("clients.dat", clients, numClients);
    saveEmployees("employees.dat", employees, numEmployees);
    saveAccounts("accounts.dat", accounts, numAccounts);
    saveBranches("branches.dat", branches, numBranches);

    delete[] clients;
    delete[] employees;
    delete[] accounts;
    delete[] branches;

    return 0;
}
