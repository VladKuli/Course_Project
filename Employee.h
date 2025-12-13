#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

enum EmployeeRole { TELLER, MANAGER, ADMIN };
enum EmployeeLevel { JUNIOR, MID, SENIOR };

struct Employee {
    long id;
    char name[50];
    char position[50];
    long branchId;
    char email[50];
    char phone[15];
    EmployeeRole role;
    EmployeeLevel level;
};

#endif
