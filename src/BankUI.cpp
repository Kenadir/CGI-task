#include "BankUI.h"
#include <cstdlib>

void BankUI::run(Bank& bank) {

	bank = bank;

	while (1) {

		menu();

	}

}

void BankUI::menu() {

	int choice{};

	system("cls");

	std::cout << "======Menu======" << std::endl << std::endl;
	std::cout << "Wybierz jedna z opcji wpisujac na wejscie przyporzadkowana liczbe:" << std::endl;
	std::cout << "1: Stworz konto" << std::endl; 
	std::cout << "2: Wejdz na dane konto" << std::endl;
	std::cout << "3: Wyjscie" << std::endl;
	std::cout << ">";

	std::cin >> choice; 

	choices(choice);

}

void BankUI::choices(int choice) {

	switch(choice){

		case 1:
			choices_Creating(choice);
			break;
		case 2:
			system("cls");

			std::cout << "Wybierz jedna z opcji wpisujac na wejscie przyporzadkowana liczbe." << std::endl;
			std::cout << "1:Wplata" << std::endl;
			std::cout << "2:Wyplata" << std::endl;
			std::cout << "3:Pokaz konto" << std::endl;
			std::cout << ">";

			std::cin >> choice;

			choices_Logging(choice);
			break;
		case 3:
			exit(0);
			break;
		default:
			std::cerr << "Prosze wprowadzic poprawna liczbe." << std::endl;
			break;

	}

}

void BankUI::choices_Creating(int choice) {

	std::string name;
	int saldo{};

	std::cout << "Prosze wprowadzic nazwe uzytkownika" << std::endl;
	std::cout << "> ";
			
	std::cin >> name;
	std::cout << std::endl;

	std::cout << "Prosze wprowadzic saldo uzytkownika(opcjonalnie)" << std::endl;
	std::cout << "> ";

	std::cin >> saldo;
	std::cout << std::endl;

	bank.make_Account(name, saldo);

	std::cout << "Konto zostalo utworzone.";

}

void BankUI::choices_Logging(int choice) {

	switch (choice) {

	case 1:
		
		break;
	case 2:
		break;
	case 3:
		break;

	}

}
