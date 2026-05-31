#ifndef CLASSES_H 
#define CLASSES_H
//#pragma once 
#include<string> 
#include<vector>
#include<memory>
#include<algorithm>
#include<iostream>

class Account {

	private: 
		int id;
		std::string owner; 
		int saldo = 0; 
	
	public:
		Account(int id, std::string& owner) :id(id), owner(owner){}
		Account(int id, std::string& owner, int saldo): id(id), owner(owner),saldo(saldo) {}

		int get_ID() { return id; }
		std::string get_owner() { return owner; }

		int deposit(int how_much);
		int withdraw(int how_much);
		void display_Info() const;

};

class Bank {

	private:
		int nextid = 0;
		std::vector<std::shared_ptr<Account>> accounts;

	public:
		Bank();

		std::shared_ptr<Account> make_Account(std::string& owner);
		std::shared_ptr<Account> make_Account(std::string& owner, int saldo);
		void add_Account(std::shared_ptr<Account> account);
		int get_ID();

		std::shared_ptr<Account> get_Account(int id) const;
		std::shared_ptr<Account> get_Account(std::string& owner) const;
		
};

#endif 