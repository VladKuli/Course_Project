#pragma once
#ifndef BRANCH_H
#define BRANCH_H

#include "Employee.h"
#include "Client.h"

enum BranchType { RETAIL, CORPORATE, PRIVATE };
enum BranchSize { SMALL, MEDIUM, LARGE };
enum BranchRegion { NORTH, SOUTH, EAST, WEST, CENTRAL };
enum BranchStatus { ACTIVE, INACTIVE, UNDER_CONSTRUCTION };

struct Branch {
    long id;
    char name[50];
    char address[100];
    char phone[15];
    char email[50];
    BranchType type;
    BranchSize size;
    BranchRegion region;
    BranchStatus status;
    long managerId;
    int numEmployees;
    int numClients;
};

#endif
