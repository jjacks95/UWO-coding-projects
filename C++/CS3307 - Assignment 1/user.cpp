#include "user.h"
//Base User Class Constructor
User::User(char* user_name, char* password)
{
	UserName = user_name;
	Password = password;

}

char* User::getUser(){
	return UserName;
}
char* User::getPassword(){
	return Password;
}	
//Customer Class Functions
Customer::Customer(char* user_name, char* password, Checking *check_a, Savings *save_a):
User(user_name, password)
{	
	
	check = check_a;
	save = save_a;
	
}
Checking* Customer::getChecking(){
	return check;
}

Savings* Customer::getSavings(){
	return save;
}
void Customer::close_account(bool flag){
	if (flag == 0){
		if(check->getAccountBalance() == 0){
			delete check;
			check = NULL;
		}else{
			cout << "\nBalance is not zero account cannot be closed.";
		}
	}else{
		if(save->getAccountBalance() == 0){
			delete save;
			save = NULL;
		}else{
			cout << "\nBalance is not zero account cannot be closed.";
		}
		
	}
}
void Customer::transfer(double amount){
	char account;
	double value = amount;
	
	cout << "\nEnter Account to Transfer From (C/S): ";
	cin >> account;
	
	if(account == 'S' || account == 's'){
		save->Withdraw_Savings(value);
		check->Deposit_Checking(value);
		cout << "\nTransfer " << value << "from Savings to Checking";
		cout << "\nNew Balance for Savings Account: "<< save->getAccountBalance();
		cout << "\nNew Balance for Checking Account: "<< check->getAccountBalance();
		
	}else{
		check->Withdraw_Checking(value);
		save->Deposit_Savings(value);
		cout << "\nTransfer $" << value << " from Checking to Savings";
		cout << "\nNew Balance for Savings Account: $"<< save->getAccountBalance();
		cout << "\nNew Balance for Checking Account: $"<< check->getAccountBalance();
	}
}

void Customer::deposit(double amount, char account_type){
	char account = account_type;
	double value = amount;
	
	if(account == 'S'){
		save->Deposit_Savings(amount);
		cout << "\nDepositing into Savings Account: $" << amount;
		cout << "\nNew Balance for Savings Account: $" << save->getAccountBalance();
	}else{
		check->Deposit_Checking(amount);
		cout << "\nDepositing into Checking Account: $"  << amount;
		cout << "\nNew Balance for Checking Account: $" << check->getAccountBalance();
	}
}

void Customer::withdraw(double amount, char account_type){
	char account = account_type;
	double value = amount;
	
	if(account == 'S'){
		save->Withdraw_Savings(amount);
		cout << "\nWithdrawing from Savings Account: $" << amount;
		cout << "\nNew Balance for Savings Account: $" << save->getAccountBalance();
	}else{
		check->Withdraw_Checking(amount);
		cout << "\nWithdrawing from Checking Account: $"  << amount;
		cout << "\nNew Balance for Checking Account: $" << check->getAccountBalance();
	}
	
}

void Customer::print_recent_transactions(){

}

//Manager Class Functions
Manager::Manager(char* user_name, char* password):
User(user_name, password)
{		
	
}

//Maintenance Class Functions
Maintenance::Maintenance(char* user_name, char* password):
User(user_name, password)
{
}
void Manager::account_details(char* user_name){
	Customer *customer;
	//cout << "Checking Account Balance: " << check->getAccountBalance();
	//cout << "Savings Account Balance: " << save->getAccountBalance();
	//customer->print_recent_transactions();

}

void Maintenance::display_log(){
	
}
