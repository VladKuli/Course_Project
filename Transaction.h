
#pragma once
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Client.h"
#include <ctime>

struct Transaction {
    long id;
    time_t date;
    long senderAccountId;
    long recipientAccountId;
    char purpose[100];
    double amount;
};

#endif
