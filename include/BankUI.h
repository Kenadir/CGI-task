#ifndef BANK_UI_H
#define BANK_UI_H
#include "Classes.h"

class BankUI {

	private:
		Bank& bank;

	public:
		void run(Bank& bank);
		void menu();
		void choices(int choice);

		void choices_Creating(int choice);
		void choices_Logging(int choice);
};



#endif