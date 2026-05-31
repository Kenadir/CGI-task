#include "Classes.h"
#include <iostream>

int main()
{
    Bank bank;
    std::string user = "User";
    Account* account = bank.make_Account(user);
    account->deposit(20);
    account->display_Info();
    account->deposit(50);
}
