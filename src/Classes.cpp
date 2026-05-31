#include "Classes.h"

int Account::deposit(int how_much) {

	saldo += how_much;

}

int Account::withdraw(int how_much) {

	if (how_much > saldo) {

		std::cerr << "Nie mozna wyplacic wiecej niz kwota posiadana na koncie" << std::endl;
	}
	else {

		saldo -= how_much;

	}

}

void Account::display_Info() const{

	std::cout << "ID: " << id << std::endl;
	std::cout << "Owner: " << owner << std::endl;
	std::cout << "Saldo: " << saldo << std::endl;

}

std::shared_ptr<Account> Bank::get_Account(int id) const{

	for (int i{}; i < accounts.size(); ++i) {

		if (accounts[i]->get_ID() == id) {

			return accounts[i];

		}

	}

	return nullptr;
}

std::shared_ptr<Account> Bank::get_Account(std::string& owner) const {

	for (int i{}; i < accounts.size(); ++i) {

		if (accounts[i]->get_owner() == owner) {

			return accounts[i];

		}

	}

	return nullptr;
}