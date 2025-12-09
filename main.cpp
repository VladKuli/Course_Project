#include "../Course_Project/menu.h"
#include "../Course_Project/dataView.h"
#include "../Course_Project/dataEdit.h"
#include "../Course_Project/dataSearch.h"
#include "../Course_Project/dataSort.h"
#include "../Course_Project/dataCalc.h"
#include "../Course_Project/fileIO.h"
#include <iostream>

using namespace std;

// ---------------- DYNAMIC ARRAYS ----------------
Client* clients = nullptr; int numClients = 0;
Employee* employees = nullptr; int numEmployees = 0;
Account* accounts = nullptr; int numAccounts = 0;
Transaction* transactions = nullptr; int numTransactions = 0;
Branch* branches = nullptr; int numBranches = 0;

// ---------------- CLIENT FUNCTIONS ----------------
void addClient() {
    Client c;
    c.id = numClients + 1;
    cin.ignore();
    cout << "Enter client name: "; cin.getline(c.name, 50);
    cout << "Enter address: "; cin.getline(c.address, 100);
    cout << "Enter phone: "; cin.getline(c.phone, 15);
    cout << "Enter email: "; cin.getline(c.email, 50);
    c.accountId = 0; c.type = INDIVIDUAL; c.level = REGULAR;

    Client* tmp = new Client[numClients + 1];
    for(int i=0;i<numClients;i++) tmp[i] = clients[i];
    tmp[numClients] = c;
    delete[] clients; clients = tmp; numClients++;
    cout << "Client added.\n";
}

void viewAllClients() { for(int i=0;i<numClients;i++) viewClient(clients[i]); }

void handleClientMenu() {
    int choice;
    do {
        displayClientMenu();
        cout << "Enter choice: "; cin >> choice;
        switch(choice){
            case 1: addClient(); break;
            case 2: viewAllClients(); break;
            case 3: {
                long id; cout<<"Enter ID to edit: "; cin>>id;
                Client* c = searchClientById(clients,numClients,id);
                if(c) editClient(*c); else cout<<"Not found\n";
                break;
            }
            case 4: {
                char name[50]; cin.ignore();
                cout<<"Enter name to search: "; cin.getline(name,50);
                Client* c = searchClientByName(clients,numClients,name);
                if(c) viewClient(*c); else cout<<"Not found\n";
                break;
            }
            case 5: sortClientsByName(clients,numClients); cout<<"Sorted by name\n"; break;
            case 0: break;
            default: cout<<"Invalid option\n";
        }
    } while(choice!=0);
}

// ---------------- EMPLOYEE FUNCTIONS ----------------
void addEmployee() {
    Employee e; e.id = numEmployees+1;
    cin.ignore();
    cout<<"Enter name: "; cin.getline(e.name,50);
    cout<<"Enter position: "; cin.getline(e.position,50);
    cout<<"Enter department: "; cin.getline(e.department,50);
    cout<<"Enter email: "; cin.getline(e.email,50);
    cout<<"Enter phone: "; cin.getline(e.phone,15);
    e.role=TELLER; e.level=JUNIOR;

    Employee* tmp = new Employee[numEmployees+1];
    for(int i=0;i<numEmployees;i++) tmp[i]=employees[i];
    tmp[numEmployees]=e; delete[] employees; employees=tmp; numEmployees++;
    cout<<"Employee added.\n";
}

void viewAllEmployees() { for(int i=0;i<numEmployees;i++) viewEmployee(employees[i]); }

void handleEmployeeMenu() {
    int choice;
    do {
        displayEmployeeMenu();
        cout<<"Enter choice: "; cin>>choice;
        switch(choice){
            case 1: addEmployee(); break;
            case 2: viewAllEmployees(); break;
            case 0: break;
            default: cout<<"Invalid option\n";
        }
    } while(choice!=0);
}

// ---------------- ACCOUNT FUNCTIONS ----------------
void addAccount() {
    Account a; a.id=numAccounts+1;
    cin.ignore();
    cout<<"Enter account number: "; cin>>a.number;
    cout<<"Enter client ID: "; cin>>a.clientId; cin.ignore();
    cout<<"Enter currency: "; cin.getline(a.currency,4);
    cout<<"Enter balance: "; cin>>a.balance; a.type=SAVINGS; cin.ignore();

    Account* tmp = new Account[numAccounts+1];
    for(int i=0;i<numAccounts;i++) tmp[i]=accounts[i];
    tmp[numAccounts]=a; delete[] accounts; accounts=tmp; numAccounts++;
    cout<<"Account added.\n";
}

void viewAllAccounts() { for(int i=0;i<numAccounts;i++) viewAccount(accounts[i]); }

void handleAccountMenu() {
    int choice;
    do {
        displayAccountMenu();
        cout<<"Enter choice: "; cin>>choice;
        switch(choice){
            case 1: addAccount(); break;
            case 2: viewAllAccounts(); break;
            case 0: break;
            default: cout<<"Invalid option\n";
        }
    } while(choice!=0);
}

// ---------------- TRANSACTION FUNCTIONS ----------------
void addTransaction() {
    Transaction t; t.id=numTransactions+1;
    cin.ignore();
    cout<<"Enter sender account ID: "; cin>>t.senderAccountId;
    cout<<"Enter recipient account ID: "; cin>>t.recipientAccountId; cin.ignore();
    cout<<"Enter purpose: "; cin.getline(t.purpose,100);
    cout<<"Enter amount: "; cin>>t.amount; t.type=DEPOSIT; cin.ignore();
    t.date=time(nullptr);

    Transaction* tmp=new Transaction[numTransactions+1];
    for(int i=0;i<numTransactions;i++) tmp[i]=transactions[i];
    tmp[numTransactions]=t; delete[] transactions; transactions=tmp; numTransactions++;
    cout<<"Transaction added.\n";
}

void viewAllTransactions() { for(int i=0;i<numTransactions;i++) viewTransaction(transactions[i]); }

void handleTransactionMenu() {
    int choice;
    do {
        displayTransactionMenu();
        cout<<"Enter choice: "; cin>>choice;
        switch(choice){
            case 1: addTransaction(); break;
            case 2: viewAllTransactions(); break;
            case 0: break;
            default: cout<<"Invalid option\n";
        }
    } while(choice!=0);
}

// ---------------- BRANCH FUNCTIONS ----------------
void addBranch() {
    Branch b; b.id=numBranches+1; cin.ignore();
    cout<<"Enter branch name: "; cin.getline(b.name,50);
    cout<<"Enter address: "; cin.getline(b.address,100);
    cout<<"Enter phone: "; cin.getline(b.phone,15);
    cout<<"Enter email: "; cin.getline(b.email,50);
    b.type=RETAIL; b.size=SMALL; b.region=NORTH; b.status=ACTIVE;
    b.managerId=0; b.numEmployees=0; b.numClients=0;

    Branch* tmp=new Branch[numBranches+1];
    for(int i=0;i<numBranches;i++) tmp[i]=branches[i];
    tmp[numBranches]=b; delete[] branches; branches=tmp; numBranches++;
    cout<<"Branch added.\n";
}

void viewAllBranches() { for(int i=0;i<numBranches;i++) viewBranch(branches[i]); }

void handleBranchMenu() {
    int choice;
    do {
        displayBranchMenu();
        cout<<"Enter choice: "; cin>>choice;
        switch(choice){
            case 1: addBranch(); break;
            case 2: viewAllBranches(); break;
            case 0: break;
            default: cout<<"Invalid option\n";
        }
    } while(choice!=0);
}

// ---------------- MAIN ----------------
int main() {
    // Load data
    loadClients("clients.dat",&clients,&numClients);
    loadEmployees("employees.dat",&employees,&numEmployees);
    loadAccounts("accounts.dat",&accounts,&numAccounts);
    loadTransactions("transactions.dat",&transactions,&numTransactions);
    loadBranches("branches.dat",&branches,&numBranches);

    int choice;
    do {
        displayMainMenu();
        cout<<"Enter choice: "; cin>>choice;
        switch(choice){
            case 1: handleClientMenu(); break;
            case 2: handleEmployeeMenu(); break;
            case 3: handleAccountMenu(); break;
            case 4: handleTransactionMenu(); break;
            case 5: handleBranchMenu(); break;
            case 0: cout<<"Exiting...\n"; break;
            default: cout<<"Invalid choice\n";
        }
    } while(choice!=0);

    // Save data
    saveClients("clients.dat",clients,numClients);
    saveEmployees("employees.dat",employees,numEmployees);
    saveAccounts("accounts.dat",accounts,numAccounts);
    saveTransactions("transactions.dat",transactions,numTransactions);
    saveBranches("branches.dat",branches,numBranches);

    // Free memory
    delete[] clients; 
    delete[] employees; 
    delete[] accounts; 
    delete[] transactions; 
    delete[] branches;

    return 0;
}
