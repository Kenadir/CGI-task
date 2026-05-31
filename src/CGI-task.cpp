#include <iostream>
#include "Classes.h"
#include "BankUI.h"

int main()
{
    Bank bank; 
    BankUI ui(bank);

    ui.run();

}
