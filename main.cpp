#include "menu.h"
#include "dataView.h"
#include "dataEdit.h"
#include "dataSearch.h"
#include "dataSort.h"
#include "dataCalc.h"
#include "deleteData.h"
#include "fileIO.h"

#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

// Place this at the top of your file (after includes)
template<typename T>
void getValidatedInput(T& value, const char* prompt = "Enter a number: ") {
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


// ---------------- DYNAMIC ARRAYS ----------------
Client* clients = nullptr; int numClients = 0;
Employee* employees = nullptr; int numEmployees = 0;
Account* accounts = nullptr; int numAccounts = 0;
Branch* branches = nullptr; int numBranches = 0;

// ============ CLIENT MENU ============
void handleClientMenu() {
    int choice;
    do {
        displayClientMenu();
        cout << "Choice: "; cin >> choice; cin.ignore();

        switch (choice) {

            // ADD
        case 1: {
            if (numBranches == 0) {
                cout << "No branches available. Please add a branch first.\n";
                break;
            }

            Client c;
            c.id = numClients + 1;

            // Select branch
            cout << "Available branches:\n";
            for (int i = 0; i < numBranches; ++i) {
                cout << "  " << branches[i].id << ". " << branches[i].name << " (" << branches[i].address << ")\n";
            }
            cout << "Enter branch ID for this client: ";
            long branchId;
            cin >> branchId; cin.ignore();
            c.branchId = branchId;

            cout << "Name: ";
            cin.getline(c.name, 50);

            cout << "Address: ";
            cin.getline(c.address, 100);

            cout << "Phone: ";
            cin.getline(c.phone, 15);

            cout << "Email: ";
            cin.getline(c.email, 50);

            cout << "Type of the client (1. Individual, 2. Company): ";
            int typeChoice;
            cin >> typeChoice; cin.ignore();
            if (typeChoice == 1)
                c.type = INDIVIDUAL;
            else
                c.type = COMPANY;

            cout << "Client level (1. Regular, 2. Premium, 3. VIP): ";
            int levelChoice;
            cin >> levelChoice; cin.ignore();
            if (levelChoice == 1)
                c.level = REGULAR;
            else if (levelChoice == 2)
                c.level = PREMIUM;
            else
                c.level = VIP;

            Client* tmp = new Client[numClients + 1];
            for (int i = 0; i < numClients; i++) tmp[i] = clients[i];
            tmp[numClients] = c;
            delete[] clients;
            clients = tmp;
            numClients++;

            cout << "Client added.\n";

            Account a;
            a.id = numAccounts + 1;
            a.clientId = c.id;
            cout << "Create an account for this client.\n";
            cout << "Account number: ";
            cin >> a.number; cin.ignore();
            cout << "Initial balance: ";
            cin >> a.balance; cin.ignore();

            Account* atmp = new Account[numAccounts + 1];
            for (int i = 0; i < numAccounts; i++) atmp[i] = accounts[i];
            atmp[numAccounts] = a;
            delete[] accounts;
            accounts = atmp;
            numAccounts++;
            cout << "Account created and linked to client.\n";

            break;
        }

              // VIEW ALL
        case 2:
            if (numClients == 0) {
                cout << "No client data available.\n";
                return;
            }
            for (int i = 0; i < numClients; i++)
                viewClient(clients[i]);
            break;

            // EDIT
        case 3: {
            long id;
            cout << "ID: "; cin >> id;
            Client* c = searchClientById(clients, numClients, id);
            if (c) editClient(*c);
            else cout << "Not found\n";
            break;
        }

              // SEARCH
        case 4: {
            int s; cout << "Search: 1.ID 2.Name 3.Email: ";
            cin >> s; cin.ignore();

            if (s == 1) {
                long id;
                cout << "ID: ";
                while (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number: ";
                }
                cin.ignore();
                Client* c = searchClientById(clients, numClients, id);
                if (c) viewClient(*c); else cout << "Not found\n";
            }
            else if (s == 2) {
                char name[50];
                cout << "Name: "; cin.getline(name, 50);
                Client* c = searchClientByName(clients, numClients, name);
                if (c) viewClient(*c); else cout << "Not found\n";
            }
            else if (s == 3) {
                char email[50];
                cout << "Email: "; cin.getline(email, 50);
                Client* c = searchClientByEmail(clients, numClients, email);
                if (c) viewClient(*c); else cout << "Not found\n";
            }
            break;
        }

              // SORT
        case 5: {
            int sortChoice;
            cout << "Sort: 1.Name 2.Phone 3.Email: ";
            cin >> sortChoice;

            if (sortChoice == 1) sortClientsByName(clients, numClients);
            else if (sortChoice == 2) sortClientByPhone(clients, numClients);
            else if (sortChoice == 3) sortClientByEmail(clients, numClients);

            cout << "\nSorted list:\n";
            for (int i = 0; i < numClients; i++)
                viewClient(clients[i]);

            break;
        }


              // DELETE
        case 6: {
            int d; cout << "Delete: 1.ID 2.Name 3.Email: "; cin >> d; cin.ignore();
            bool result = false;

            if (d == 1) {
                long id; cout << "ID: "; cin >> id;
                result = deleteClientById(clients, numClients, id);
            }
            else if (d == 2) {
                char name[50]; cout << "Name: "; cin.getline(name, 50);
                result = deleteClientByName(clients, numClients, name);
            }
            else if (d == 3) {
                char email[50]; cout << "Email: "; cin.getline(email, 50);
                result = deleteClientByEmail(clients, numClients, email);
            }

            cout << (result 
                ? "Deleted.\n" 
                : "Not found.\n");
            break;
        }

              // CALCULATIONS
        case 7:
            cout << "Total: " << calculateTotalClients(clients, numClients) << endl;
            cout << "Regular: " << calculateClientsByLevel(clients, numClients, REGULAR) << endl;
            cout << "Premium: " << calculateClientsByLevel(clients, numClients, PREMIUM) << endl;
            cout << "VIP: " << calculateClientsByLevel(clients, numClients, VIP) << endl;
            break;

        case 0: break;
        default: cout << "Invalid\n";
        }
    } while (choice != 0);
}


// =========================================================
// EMPLOYEE MENU
// =========================================================
void handleEmployeeMenu() {
    int choice;
    do {
        displayEmployeeMenu();
        cout << "Choice: "; cin >> choice; cin.ignore();

        switch (choice) {

            // ADD
        case 1: {
            if (numBranches == 0) {
                cout << "No branches available. Please add a branch first.\n";
                break;
            }

            Employee e;
            e.id = numEmployees + 1;

            // Select branch
            cout << "Available branches:\n";
            for (int i = 0; i < numBranches; ++i) {
                cout << "  " << branches[i].id << ". " << branches[i].name << " (" << branches[i].address << ")\n";
            }
            long branchId;
            getValidatedInput(branchId, "Enter branch ID for this employee: ");
            e.branchId = branchId;

            cout << "Name: "; cin.getline(e.name, 50);
            cout << "Position: "; cin.getline(e.position, 50);
            cout << "Email: "; cin.getline(e.email, 50);
            cout << "Phone: "; cin.getline(e.phone, 15);

            int roleChoice;
            getValidatedInput(roleChoice, "Role (1. Teller, 2. Manager, 3. Admin): ");
            switch (roleChoice) {
            case 1: e.role = TELLER; break;
            case 2: e.role = MANAGER; break;
            case 3: e.role = ADMIN; break;
            default: e.role = TELLER; break;
            }

            Employee* tmp = new Employee[numEmployees + 1];
            for (int i = 0; i < numEmployees; i++) tmp[i] = employees[i];
            tmp[numEmployees] = e;
            delete[] employees;
            employees = tmp;
            numEmployees++;

            cout << "Employee added.\n";
            break;
        }


              // VIEW ALL
        case 2:
            if (numEmployees == 0) {
                cout << "No employees data available.\n";
                return;
            }

            for (int i = 0; i < numEmployees; i++) viewEmployee(employees[i]);
            break;

            // EDIT
        case 3: {
            long id; cout << "ID: "; cin >> id;
            Employee* e = searchEmployeeById(employees, numEmployees, id);
            if (e) editEmployee(*e);
            else cout << "Not found\n";
            break;
        }

              // SEARCH
        case 4: {
            int s; cout << "Search: 1.ID 2.Name 3.Email: "; cin >> s; cin.ignore();
            if (s == 1) {
                long id; cout << "ID: "; cin >> id;
                Employee* e = searchEmployeeById(employees, numEmployees, id);
                if (e) viewEmployee(*e); else cout << "Not found\n";
            }
            else if (s == 2) {
                char name[50]; cout << "Name: "; cin.getline(name, 50);
                Employee* e = searchEmployeeByName(employees, numEmployees, name);
                if (e) viewEmployee(*e); else cout << "Not found\n";
            }
            else if (s == 3) {
                char email[50]; cout << "Email: "; cin.getline(email, 50);
                Employee* e = searchEmployeeByEmail(employees, numEmployees, email);
                if (e) viewEmployee(*e); else cout << "Not found\n";
            }
            break;
        }

              // SORT
        case 5: {
            int s;
            getValidatedInput(s, "Sort: 1.Name 2.Role: ");
            if (s == 1) sortEmployeesByName(employees, numEmployees);
            else if (s == 2) sortEmployeesByRole(employees, numEmployees);

            cout << "Sorted list:\n";
            for (int i = 0; i < numEmployees; i++)
                viewEmployee(employees[i]);
            break;
        }


              // DELETE
        case 6: {
            int d; cout << "Delete: 1.ID 2.Name 3.Email: "; cin >> d; cin.ignore();
            bool result = false;

            if (d == 1) {
                long id; cout << "ID: "; cin >> id;
                result = deleteEmployeeById(employees, numEmployees, id);
            }
            else if (d == 2) {
                char name[50]; cout << "Name: "; cin.getline(name, 50);
                result = deleteEmployeeByName(employees, numEmployees, name);
            }
            else if (d == 3) {
                char email[50]; cout << "Email: "; cin.getline(email, 50);
                result = deleteEmployeeByEmail(employees, numEmployees, email);
            }

            cout << (result ? "Deleted.\n" : "Not found.\n");
            break;
        }

        // CALCULATIONS
        case 7:
            cout << "Total employees: " << calculateTotalEmployees(employees, numEmployees) << endl;
            cout << "Managers: " << calculateEmployeesByRole(employees, numEmployees, MANAGER) << endl;
            cout << "Tellers: " << calculateEmployeesByRole(employees, numEmployees, TELLER) << endl;
            cout << "Admins: " << calculateEmployeesByRole(employees, numEmployees, ADMIN) << endl;
            break;


        case 0: break;
        default: cout << "Invalid\n";
        }
    } while (choice != 0);
}

// =========================================================
// ACCOUNT MENU
// =========================================================
void handleAccountMenu() {
    int choice;
    do {
        displayAccountMenu();
        cout << "Choice: "; cin >> choice; cin.ignore();

        switch (choice) {

              // VIEW
        case 1:

            if (numAccounts == 0) {
                cout << "No Accounts data available.\n";
                return;
            }
            for (int i = 0; i < numAccounts; i++) viewAccount(accounts[i]);
            break;

            // EDIT
        case 2: {
            long id;
            cout << "ID: "; cin >> id;
            Account* a = searchAccountById(accounts, numAccounts, id);
            if (a) editAccount(*a); else cout << "Not found\n";
            break;
        }

              // SEARCH
        case 3: {
            int s; cout << "Search: 1.ID 2.Number 3.ClientID: "; cin >> s; cin.ignore();
            if (s == 1) {
                long id; cout << "ID: "; cin >> id;
                Account* a = searchAccountById(accounts, numAccounts, id);
                if (a) viewAccount(*a);
                else cout << "Not found\n";
            }
            else if (s == 2) {
                int number; cout << "Number: "; cin >> number;
                Account* a = searchAccountByNumber(accounts, numAccounts, number);
                if (a) viewAccount(*a);
                else cout << "Not found\n";
            }
            else if (s == 3) {
                long cid; cout << "Client ID: "; cin >> cid;
                Account* a = searchAccountByClientId(accounts, numAccounts, cid);
                if (a) viewAccount(*a);
                else cout << "Not found\n";
            }
            break;
        }

              // SORT
        case 4: {
            int s;
            getValidatedInput(s, "Sort: 1.Balance: ");
            if (s == 1) sortAccountsByBalance(accounts, numAccounts);

            cout << "Sorted list:\n";
            for (int i = 0; i < numAccounts; i++)
                viewAccount(accounts[i]);
            break;
        }


              // DELETE
        case 5: {
            int d; cout << "Delete: 1.ID 2.Number: "; cin >> d; cin.ignore();
            bool result = false;

            if (d == 1) {
                long id; cout << "ID: "; cin >> id;
                result = deleteAccountById(accounts, numAccounts, id);
            }
            else if (d == 2) {
                int number; cout << "Number: "; cin >> number;
                result = deleteAccountByNumber(accounts, numAccounts, number);
            }

            cout << (result ? "Deleted.\n" : "Not found.\n");
            break;
        }
              // CALCULATIONS
        case 6:
            cout << "Total accounts: " << calculateTotalAccounts(accounts, numAccounts) << endl;
            break;

        case 0: break;
        default: cout << "Invalid\n";
        }
    } while (choice != 0);
}

//todo Add to statistic how many large branches etc
// =========================================================
// BRANCH MENU
// =========================================================
void handleBranchMenu() {
    int choice;
    do {
        displayBranchMenu();
        cout << "Choice: "; cin >> choice; cin.ignore();

        switch (choice) {

            // ADD
        case 1: {

            Branch b;
            b.id = numBranches + 1;
            cout << "Name: "; cin.getline(b.name, 50);
            cout << "Address: "; cin.getline(b.address, 100);
            cout << "Phone: "; cin.getline(b.phone, 15);
            cout << "Email: "; cin.getline(b.email, 50);

            int sizeChoice;
            getValidatedInput(sizeChoice, "Branch size (1. Small, 2. Medium, 3. Large): ");
            switch (sizeChoice) {
            case 1: b.size = SMALL; break;
            case 2: b.size = MEDIUM; break;
            case 3: b.size = LARGE; break;
            default: b.size = SMALL; break;
            }

            b.numClients = 0;
            b.numEmployees = 0;


            Branch* tmp = new Branch[numBranches + 1];
            for (int i = 0; i < numBranches; i++) tmp[i] = branches[i];
            tmp[numBranches] = b;
            delete[] branches;
            branches = tmp;
            numBranches++;

            cout << "Branch added.\n";
            break;
        }

              // VIEW
        case 2:

            if (numBranches == 0) {
                cout << "No Branches data available.\n";
                return;
            }

            for (int i = 0; i < numBranches; i++) viewBranch(branches[i]);
            break;

            // EDIT
        case 3: {
            long id; cout << "ID: "; cin >> id;
            Branch* b = searchBranchById(branches, numBranches, id);
            if (b) editBranch(*b); else cout << "Not found\n";
            break;
        }

              // SEARCH
        case 4: {
            int s; cout << "Search: 1.ID 2.Name"; cin >> s; cin.ignore();
            if (s == 1) {
                long id; cout << "ID: "; cin >> id;
                Branch* b = searchBranchById(branches, numBranches, id);
                if (b) viewBranch(*b); else cout << "Not found\n";
            }
            else if (s == 2) {
                char name[50]; cout << "Name: "; cin.getline(name, 50);
                Branch* b = searchBranchByName(branches, numBranches, name);
                if (b) viewBranch(*b); else cout << "Not found\n";
            }
            else if (s == 3) {
               //Need to add 3 option 
            }
            break;
        }

              // SORT
        case 5: {
            int s; cout << "Sort: 1.Name 2.Client count 3.Size: "; cin >> s;
            if (s == 1) sortBranchesByName(branches, numBranches);
            else if (s == 2) sortBranchesByClientCount(branches, numBranches,clients, numClients);
            else if (s == 3) sortBranchesBySize(branches, numBranches);

            cout << "\nSorted list:\n";
            for (int i = 0; i < numBranches; i++)
                viewBranch(branches[i]);
            break;
        }


              // DELETE
        case 6: {
            long id; cout << "ID: "; cin >> id;
            bool result = deleteBranchById(branches, numBranches, id);
            cout << (result ? "Deleted.\n" : "Not found.\n");
            break;
        }

              // CALC
        case 7:
            cout << "Total branches: " << calculateTotalBranches(branches, numBranches) << endl;
            break;

        case 0: break;
        default: cout << "Invalid\n";
        }
    } while (choice != 0);
}


// =========================================================
// MAIN
// =========================================================
int main() {
    loadClients("clients.dat", &clients, &numClients);
    loadEmployees("employees.dat", &employees, &numEmployees);
    loadAccounts("accounts.dat", &accounts, &numAccounts);
    loadBranches("branches.dat", &branches, &numBranches);

    int choice;
    do {
        displayMainMenu();
        cout << "----------------\n";
        cout << "Your choice: \n";

        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter a number: ";
        }

        switch (choice) {
        case 1: handleClientMenu(); break;
        case 2: handleEmployeeMenu(); break;
        case 3: handleAccountMenu(); break;
        case 4: handleBranchMenu(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid\n";
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
