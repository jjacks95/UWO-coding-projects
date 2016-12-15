using namespace std;

#include "account.h"
//Constructors and function definitions for User Customer Manager and Maintenance Class
class User{
	protected:
		char* UserName;
		char* Password;
		
	public:
		User(char* user_name, char* password);
		char* getUser();
		char* getPassword();
		
};

class Customer: public User{
	protected:
		Checking *check;
		Savings *save;

	public:
		Customer(char* user_name, char* password, Checking *check_a, Savings *save_a);
		Checking* getChecking();
		Savings* getSavings();
		void close_account(bool flag);
		void transfer(double amount);
		void deposit(double amount, char account_type);
		void withdraw(double amount, char account_type);
		void print_recent_transactions();
};

class Manager: public User{

	public:
		Manager(char* user_name, char* password);
		void account_details(char* user_name);
};

class Maintenance: public User{

	public:
		Maintenance(char* user_name, char* password);
		void display_log();
};

