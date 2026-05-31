#include "BankUI.h"
#include <cstdlib>
#include <climits>
#include <thread>
#include <chrono>

void BankUI::run() {

	while (running) {

		menu();

	}

}

void BankUI::menu() {

	int choice{};

	system("cls");//wyczyszcza ekran konsoli 

	std::cout << "======Menu======" << std::endl << std::endl;
	std::cout << "Wybierz jedna z opcji wpisujac na wejscie przyporzadkowana liczbe:" << std::endl;
	std::cout << "1: Stworz konto" << std::endl; 
	std::cout << "2: Wejdz na dane konto" << std::endl;
	std::cout << "3: Wyjscie" << std::endl;
	std::cout << "> ";

	std::cin >> choice; 

	choices(choice);

}

void BankUI::choices(int choice) {
	
	std::string input;
	
	switch(choice){

		case 1:
			system("cls");
			choices_Creating(choice);
			break;

		case 2:
			system("cls");

			std::cout << "Prosze wpisac nazwe lub id konta" << std::endl;
			std::cout << "> ";

			std::cin >> input;
			
			Account* account; 

			if (is_Number(input)) {

				account = bank.get_Account(std::stoi(input));

			}
			else {

				account = bank.get_Account(input);

			}

			if (account == nullptr) {

				std::cout << "Nie znaleziono konta" << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));
				return;

			}

			std::cout << "Wybierz jedna z opcji wpisujac na wejscie przyporzadkowana liczbe:" << std::endl;
			std::cout << "1:Wplata" << std::endl;
			std::cout << "2:Wyplata" << std::endl;
			std::cout << "3:Pokaz konto" << std::endl;
			std::cout << "> ";

			std::cin >> choice;

			system("cls");
			choices_Logging(choice, account);
			break;

		case 3:
			running = false;
			break;

		default:
			std::cerr << "Prosze wprowadzic poprawna liczbe" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
 			break;

	}

}

void BankUI::choices_Creating(int choice) {

	std::string name;
	int saldo{};

	std::cout << "Prosze wprowadzic nazwe uzytkownika:" << std::endl;
	std::cout << "> ";
			
	std::cin >> name;
	std::cout << std::endl;

	while (is_Number(name)) {

		std::cout << "Nazwa nie moze byc liczba" << std::endl; //to dlatego zeby ID z nazwa sie nie mieszalo 
		std::cout << "> ";
		std::cin >> name;
		std::cout << std::endl;
	}

	std::cout << "Prosze wprowadzic saldo uzytkownika(opcjonalnie, mozna wpisac 0):" << std::endl;
	std::cout << "> ";
	saldo =  get_Int();

	while (saldo < 0) {

		std::cout << "Saldo nie moze byc ujemne" << std::endl;
		std::cout << "> ";
		saldo = get_Int();
		std::cout << std::endl;

	}

	Account* account = bank.make_Account(name, saldo);

	account->display_Info();
	std::cout << "Konto zostalo utworzone.";
	std::cout << "\nNacisnij enter...";
	std::cin.ignore();
	std::cin.get();

}

void BankUI::choices_Logging(int choice, Account* account ) {

	switch (choice) {

		case 1: {
			int amount{};
			std::cout << "Prosze wpisac kwote do wplaty" << std::endl;
			std::cout << "> ";

			amount = get_Int();

			while (!account->deposit(amount)) {

				std::cout << "Kwota musi byc wieksza od 0 i mniejsza niz 2147483647" << std::endl;
				std::cout << "> ";
				amount = get_Int();

			}

			std::cout << "Wplata w wysokosci " << amount << " udana!";

			break;
		}
		case 2: {
			int amount{};
			std::cout << "Prosze wpisac kwote do wyplaty" << std::endl;
			std::cout << "> ";

			amount = get_Int();

			while (!account->withdraw(amount)) {
				
				std::cout << "> ";
				amount = get_Int();

			}
			std::cout << "Wyplata w wysokosci " << amount << " udana!";
			break;
		}
		case 3:
			account->display_Info();
			std::cout << "\nNacisnij enter...";
			std::cin.ignore();
			std::cin.get();
			break;

	}

}

//sprawdza czy input jest numerem przydatne do walidacji 
bool BankUI::is_Number(const std::string& s) {

	return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);

}

//jezeli zostanie podane bledne wejscie to naprawia i daje mozliwosc wpisania inputu do skutku 
int BankUI::get_Int() {
	int x;

	while (true) {
		std::cin >> x;
		std::cout << std::endl;
		if (!std::cin.fail())
			return x;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << "To nie jest liczba" << std::endl;
		std::cout << "> ";
	}
}