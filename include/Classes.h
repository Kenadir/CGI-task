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

		bool deposit(int how_much);
		bool withdraw(int how_much);
		void display_Info() const;

};

class Bank {

	private:
		int nextid = 0;
		std::vector<std::unique_ptr<Account>> accounts;

	public:
		Bank() {}

		Account* make_Account(std::string& owner);
		Account* make_Account(std::string& owner, int saldo);
		void add_Account(std::unique_ptr<Account> account);
		int get_ID();

		Account* get_Account(int id) const;
		Account* get_Account(std::string& owner) const;
		
};

#endif 