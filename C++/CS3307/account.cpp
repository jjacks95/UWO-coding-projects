#include "account.h"

Account::Account(double bal){
	balance = bal;
}

double Account::getAccountBalance(){
	return balance;
}

Checking::Checking(double bal):
Account(bal)
{

}

Checking::~Checking(void){
	cout << "Deleting Checking Object\n";
}

double Checking::Deposit_Checking(double amount){
	balance += amount;
	return balance;
}

double Checking::Withdraw_Checking(double amount){
	char option;
	if((balance -= amount) < 0){
		cout << "\nInsufficient Funds";
		return balance;
	}else if((balance -= amount) < 1000){
		cout << "\n Checking Account Balance is Below $1,000";
		cout << "\nWould you like to continue? (Y/N)";
		cin >> option;
		if(option == 'Y'){
			cout << "\nA charge of $2.00 was applied.";
			cout << "\nChecking Account Balance: $" << (balance -= amount - 2);
			
		}else{
			cout << "\nOperation Cancelled";
			return balance;
		}
	}
	balance -= amount;
	return balance;
}

Savings::Savings(double bal):
Account(bal)
{

}
Savings::~Savings(void){
	cout << "Deleting Saving Object\n";
}

double Savings::Deposit_Savings(double amount){
	balance += amount;
	return balance;
}
double Savings::Withdraw_Savings(double amount){
	if((balance -= amount) < 0){
		cout << "\nInsufficient Funds";
		return balance;
	}else{
		balance -= amount;
	}
	return balance;
}