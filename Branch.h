#pragma once
#ifndef BRANCH_H
#define BRANCH_H

#include "Employee.h"
#include "Client.h"

enum BranchSize { SMALL, MEDIUM, LARGE };

struct Branch {

    long id;
    char name[50];
    char address[100];
    char phone[15];
    char email[50];
    BranchSize size;
    int numEmployees;
    int numClients;
};

#endif
