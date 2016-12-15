#include <cctype>
#include <iomanip>
#include <stdio.h>
#include <memory>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//constructor and function definition for Account Checking and Saving Classes
class Account{
	protected:
		double balance;
		
	public:
		Account(double bal);
		void account_details(char* user_name);
		double getAccountBalance();
		
};

class Checking: public Account{

	public:
		Checking(double bal);
		~Checking();
		double Deposit_Checking(double amount);
		double Withdraw_Checking(double amount);
};

class Savings: public Account{
	
	public:
		Savings(double bal);
		~Savings();
		double Deposit_Savings(double amount);
		double Withdraw_Savings(double amount);
};