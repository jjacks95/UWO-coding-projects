#include "user.h"

int main(int argc, char** argv){
	/*
	Preset Login for Manager, Customer, and Maintenance 
		Manager 	Login: manager 	Password: manager
		Customer 	Login: cust 	Password: cust
		Maintenance Login: admin 	Password: admin
	*/
	
	//Declaring variables and vector for users
	char login[50];
	char password[50];
	
	Account *a;
	std::vector<Customer> cus_list;

	double bal = 1000;
	double amount;
	char type_account;
	
	//manager credentials
	char m_user[] = "manager";
	char m_pass[] = "manager";
	char* m_user1 = m_user;
	char* m_pass1 = m_pass;
	
	//maintenance credentials
	char a_user[] = "admin";
	char a_pass[] = "admin";
	char* a_user1 = a_user;
	char* a_pass1 = a_pass;
	
	//preset user credentials
	char user1[50] = "cust";
	char pass1[50] = "cust";
	char* user11 = user1;
	char* pass11 = pass1;
	
	Checking *cheqc = new Checking(bal);
	Savings *save = new Savings(bal);
	
	Checking *cheqc1;
	Savings *save1;
	
	//Maintenance Manager and Customer objects
	Manager *manage = new Manager(m_user1, m_pass1);
	Maintenance *admin = new Maintenance(a_user1, a_pass1);
	Customer *cus = new Customer(user11, pass11, cheqc, save);
	
	cus_list.push_back(*cus);
	
	//Login
	cout << "\nLogin: ";
	cin >> login;
	cout << "\nPassword: ";
	cin >> password;

	int option;
	int i = 0;
	user11 = login;
	pass11 = password;
	bool flag = 0;
	while(flag == 0){
		if (strcmp(login, m_user1) == 0){
			//Manager Options Include:
			//Create Account//Close Account//See User Details//Create Users
			//if login matches manger login then prompt with options
			cout << "\nSelect Option Using Number (1, 2, 3...): ";
			cout << "\n\t1. Create Account.";
			cout << "\n\t2. Close Account. ";
			cout << "\n\t3. Adding Complimentary Account.";
			cout << "\n\t4. User Details";
			cout << "\n\t5. Exit\n";
			cout << "\nEnter Option: \n";
			cin >> option;
			//switch cases for each option
			switch(option){
				case 1:
					bal = 0;
					cout << "\nEnter The Name of The account Holder : ";
					cin >> user1;
					cout << "\nEnter Password: ";
					cin >> pass1;
					cout << "\n\nEnter Type of The account (C/S) : ";
					cin >> type_account;
					
					user11 = user1;
					pass11 = pass1;
					
					if(type_account == 'C')
					{
						cout << "\nEnter The Initial amount: ";
						cin >> bal;
						cheqc1 = new Checking(bal);
						cout << "Created New Checking Account\n";
						Customer *cus1 = new Customer(user11, pass11, cheqc1, NULL);
						cus_list.push_back(*cus1);
					}else
					{
						cout << "\nEnter The Initial amount: ";
						cin >> bal;
						save1 = new Savings(bal);
						cout << "Created New Savings Account\n";
						Customer *cus1 = new Customer(user11, pass11, NULL, save1);
						cus_list.push_back(*cus1);
					}
					break;
		
				case 2:	
					cout << "\nEnter Name of Account Holder: ";
					cin >> user1;
					cout << "\nEnter Account Type (C/S)";
					cin >> type_account;
					user11 = user1;
					if(type_account == 'C'){
						
						for(int i=0; i < cus_list.size(); ++i){
							if(strcmp(user11, cus_list[i].getUser())){
								cus_list[i].close_account(0);
								
							}			
						}
					}else{
						for(int i=0; i < cus_list.size(); ++i){
							if(strcmp(user11, cus_list[i].getUser())){
								cus_list[i].close_account(1);
								
							}
						}
					}
					cout << "\nAccount Closed";
					break;
				
				case 3:
					cout << "\nAdding Complimentary Account";
					cout << "\nEnter Name of Account Holder\n";
					cin >> user1;
					cout << "\nEnter Starting Balance\n";
					cin >> bal;
					user11 = user1;
					for(int i=0; i < cus_list.size(); ++i){
						if(strcmp(user11, cus_list[i].getUser()) == 0){
							if(cus_list[i].getChecking() == NULL){
								cheqc1 = new Checking(bal);		
							}else if(cus_list[i].getSavings() == NULL){					
								save1 = new Savings(bal);
							}
							cout << "Account Information:\n";
							cout << "Account Type: Savings\n";
							cout << "Account Balance: $"<<save1->getAccountBalance();
							cout << "\nAccount Information:\n";
							cout << "Account Type: Checking\n";
							cout << "Account Balance: $"<<cheqc1->getAccountBalance();
						}
					}
					break;
				case 4:
					char option;
					cout << "For Sepcific User Enter S for All Enter Any Character\n";
					cin >> option;
					if(option == 'S'){
						cout << "Enter Username: ";
						cin >> user1;
						user11 = user1;
						for(int i=0; i < cus_list.size(); ++i){
							if(strcmp(user11, cus_list[i].getUser()) == 0){
								cout << "\nAccount Details\n";
								cout << "User: " << cus_list[i].getUser();
								cout << "\nAccount Type: Savings\n";
								cout << "Account Balance: $" <<cus_list[i].getSavings()->getAccountBalance()<<"\n";
								cout << "\nAccount Type: Checking\n";
								cout << "Account Balance: $" <<cus_list[i].getChecking()->getAccountBalance()<<"\n";
								cout << "\n";
								break;
							}else{
								cout << "\nNo User Found\n";
							}
						}
						
					}else{
					for(int j=0; j < cus_list.size(); ++j){
						cout << "\nAccount Details\n";
						cout << "User: " << cus_list[j].getUser();
						cout << "\nAccount Type: Savings\n";
						cout << "Account Balance: $" <<cus_list[j].getSavings()->getAccountBalance()<<"\n";
						cout << "\nAccount Type: Checking\n";
						cout << "Account Balance: $" <<cus_list[j].getChecking()->getAccountBalance()<<"\n";
						cout << "\n";
						}
					}
					break;
				case 5:
					exit(0);
					break;
			}
		
			//Maintenance Options:
			//Execution Trace ON or OFF
		
		}else if(strcmp(login, a_user) == 0){
			cout << "\nSelect Option Using Number (1, 2, 3...): ";
			cout << "\n\t1. Execution Trace ON.";
			cout << "\n\t2. Execution Trace OFF. ";
			cout << "\n\t3. Exit\n";
			cin >> option;
			
			switch(option){
				case 1:
					cout << "Execution Trace ON\n";
					break;
				case 2:
					cout << "Execution Trace OFF\n";
					break;
				case 3:
					exit(0);
					break;
			}
		}else{
			//Customer Options
			//Deposit
			//Withdraw
			//Transfer
			//get Balance
			
			//For loop to look through list of created users for matching username
			user11 = login;
			for(int i=0; i < cus_list.size(); ++i){
				user11 = cus_list[i].getUser();
				pass11 = password;
				//if username matches prompt user with options
				if( strcmp(login, user11) == 0){
					cout << "\nSelect Option Using Number (1, 2, 3...): ";
					cout << "\n\t1. Deposit.";
					cout << "\n\t2. Withdraw. ";
					cout << "\n\t3. Transfer.";
					cout << "\n\t4. Balance.";
					cout << "\n\t5. Exit\n";
					cin >> option;
					
					//switch cases for each option
					switch(option){
						case 1:
							cout << "Deposit Selected\n";
							cout << "Enter Amount to Deposit: $";
							cin >> amount;
							cout << "\nWhich Account to Deposit into: (C/S)\n";
							cin >> type_account;
							cus_list[i].deposit(amount, type_account);
							break;
							
						case 2:
							cout << "Withdraw Selected\n";
							cout << "Enter Amount to Withdraw: $";
							cin >> amount;
							cout << "\nWhich Account to Withdraw from: (C/S)\n";
							cin >> type_account;
							cus_list[i].withdraw(amount, type_account);
							break;
							
						case 3:
							cout << "Transfer Selected\n";
							cout << "Enter Amount to Transfer: $";
							cin >> amount;
							cus_list[i].transfer(amount);
							break;
						case 4:
							cout << "Balance Selected\n";
							cout << "Selected Account (C/S):";
							cin >> type_account;
							if(type_account == 'C'){
								cout << "\nAccount Balance: $"<<cus_list[i].getChecking()->getAccountBalance()<<"\n";
							}else{
								cout << "\nAccount Balance: $"<<cus_list[i].getSavings()->getAccountBalance()<< "\n";
							}
						break;
					case 5:
						exit(0);
						break;
						
					}
				}else{
					cout << "Access Denied.\n";
					flag = 1;
				}
			}	
		}
	}
		
	return 0;
}