#ifndef CLASSES_H 
#define CLASSES_H
//#pragma once 
#include<string> 
#include<vector>
#include<memory>

class Account {

	private: 
		int id;
		std::string owner; 
		int saldo = 0; 
	
	public:
		Account(); 
		Account(int id, std::string& owner);
		Account(int id, std::string& owner, int saldo);

		int deposit(int how_much);
		int withdraw(int how_much);
		void display_Info() const;

};

class Bank {

	private:
		std::vector<std::shared_ptr<Account>> accounts;

	public:
		Bank();
		std::shared_ptr<Account> get_Account(int id) const;
		std::shared_ptr<Account> get_Account(std::string& owner) const;

};

#endif 