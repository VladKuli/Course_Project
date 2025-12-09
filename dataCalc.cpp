#include "../Course_Project/dataCalc.h"

int calculateTotalClients(Client* clients, int numClients) {
    int count = 0;
    for (int i = 0; i < numClients; ++i) {
        if (clients[i].id != 0) count++;
    }
    return count;
}

int calculateTotalEmployees(Employee* employees, int numEmployees) {
    int count = 0;
    for (int i = 0; i < numEmployees; ++i) {
        if (employees[i].id != 0) count++;
    }
    return count;
}

int calculateTotalBranches(Branch* branches, int numBranches) {
    int count = 0;
    for (int i = 0; i < numBranches; ++i) {
        if (branches[i].id != 0) count++;
    }
    return count;
}
