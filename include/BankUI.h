#ifndef BANK_UI_H
#define BANK_UI_H
#include "Classes.h"

class BankUI {

	private:
		Bank& bank;
		bool running = true;

	public:

		BankUI(Bank& bank) : bank(bank) {}

		void run();
		void menu();
		void choices(int choice);

		void choices_Creating(int choice);
		void choices_Logging(int choice, Account* account);
		bool is_Number(const std::string& s);
		int get_Int();
};

#endif