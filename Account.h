#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Client.h"

struct Account {
    long id;
    int number;
    long clientId;
    double balance;
};

#endif 
