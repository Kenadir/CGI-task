#include "Classes.h"

bool Account::deposit(int how_much) {

	if (how_much <= 0 ) return false;
	saldo += how_much;
	return true;
}

bool Account::withdraw(int how_much) {

	if (how_much > saldo) {

		std::cerr << "Nie mozna wyplacic wiecej niz kwota posiadana na koncie" << std::endl;
		return false;
	
	}else if (how_much < 1) {

		std::cerr << "Kwota nie moze byc mniejsza od 1" << std::endl;
		return false;

	}else {

		saldo -= how_much;
		return true;
	}
	
}

void Account::display_Info() const{

	std::cout << "Owner: " << owner << std::endl;
	std::cout << "Saldo: " << saldo << std::endl;
	std::cout << "ID:    " << id << std::endl;

}

Account* Bank::make_Account(std::string& owner) {

	std::unique_ptr<Account> account = std::make_unique<Account>(get_ID(), owner);
	Account* raw = account.get();
	add_Account(std::move(account));
	return raw;
}

Account* Bank::make_Account(std::string& owner, int saldo) {

	std::unique_ptr<Account> account = std::make_unique<Account>(get_ID(), owner,saldo);
	Account* raw = account.get();
	add_Account(std::move(account));
	return raw;

}

void Bank::add_Account(std::unique_ptr<Account> account) {

	//sprawdzenie czy jest już w accounts takie konto
	bool exists = std::any_of(accounts.begin(), accounts.end(), [&](const std::unique_ptr<Account>& a) {return a->get_ID() == account->get_ID();});
	
	if (!exists) accounts.push_back(std::move(account));
	else std::cerr << "Nie mozna dodac takiego konta bo juz istnieje" << std::endl;

}

int Bank::get_ID() {

	int id = nextid; 
	nextid++;
	
	return id;

}


Account* Bank::get_Account(int id) const{

	for (int i{}; i < accounts.size(); ++i) {

		if (accounts[i]->get_ID() == id) {

			return accounts[i].get();

		}

	}

	return nullptr;
}

Account* Bank::get_Account(std::string& owner) const {

	for (int i{}; i < accounts.size(); ++i) {

		if (accounts[i]->get_owner() == owner) {

			return accounts[i].get();

		}

	}

	return nullptr;
}

