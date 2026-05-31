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

std::shared_ptr<Account> Bank::make_Account(std::string& owner) {

	std::shared_ptr<Account> account = std::make_shared<Account>(get_ID(), owner);
	add_Account(account);
	return account;
}

std::shared_ptr<Account> Bank::make_Account(std::string& owner, int saldo) {

	std::shared_ptr<Account> account = std::make_shared<Account>(get_ID(), owner,saldo);
	add_Account(account);
	return account;

}

void Bank::add_Account(std::shared_ptr<Account> account) {

	//sprawdzenie czy jest już w accounts takie konto
	bool exists = std::any_of(accounts.begin(), accounts.end(), [&](const std::shared_ptr<Account>& a) {return a->get_ID() == account->get_ID();});
	
	if (exists) accounts.push_back(account);
	else std::cerr << "Nie mozna dodac takiego konta bo juz istnieje" << std::endl;

}

int Bank::get_ID() {

	int id = nextid; 
	nextid++;
	
	return id;

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

