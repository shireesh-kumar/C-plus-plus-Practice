#include <iostream>
#include "SBIBank.h"
using namespace std;

unsigned int passcode;
unsigned int accountNo;
SBIBankValidation obj;

void createSBIBankAccount()
{
	string name;
	cout << "\n\tEnter your first name and 4 digit non negative numeric passcode : \n\t";
	cin >> name >> passcode;
	obj.createSBIBankAccount(name, passcode);
}

void getAccountDetails()
{
	cout << "Enter you account number and passcode:\n\t";
	cin >> accountNo >> passcode;
}
int main()
{
	bool applicationRunning = true;
	short actionToPerformOnATM;
	while (applicationRunning)
	{
		cout << "\n\n\tWelcome to SBI Bank ATM " << endl;
		cout << "\tEnter the value assigned to the action you want to perform  " << endl;
		cout << "\t1 -> Open Account, 2->View Balance , 3-> Deposit Money , 4 ->Withdraw Money , 5-> Delete Account , 6 ->Stop Application : \n\t";
		cin >> actionToPerformOnATM;
		switch (actionToPerformOnATM)
		{
		case 1: {createSBIBankAccount();break;}
		case 2: {getAccountDetails();obj.customerAccountOperations(1, accountNo, passcode); break;}
		case 3: {getAccountDetails();obj.customerAccountOperations(2, accountNo, passcode); break;}
		case 4: {getAccountDetails();obj.customerAccountOperations(3, accountNo, passcode);	break;}
		case 5: {getAccountDetails();obj.deleteSBIBankAccount(accountNo, passcode);break;}
		case 6: {applicationRunning = false; break;}
		default: cout << "Please Enter Correct Option ! \n\t ";
		}
	}
	return 0;
}