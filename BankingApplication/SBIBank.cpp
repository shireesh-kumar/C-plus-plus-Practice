#include<iostream>
#include "SBIBank.h";
using namespace std;



SBIBank* SBIBank::accountValidation(unsigned int accountNumber, unsigned int passcodeValue)
{
	return (accountNo == accountNumber && passcode == passcodeValue) ? this : nullptr;
}

void SBIBank::depositMoney(unsigned int addMoney)
{
	accountBalance += addMoney;
	cout << "\n\tMoney Deposited Successfully !\n\t";
}
void SBIBank::withDrawMoney(unsigned int withDrawMoney)
{
	if (accountBalance >= withDrawMoney)
	{
		accountBalance -= withDrawMoney;
		cout << "\n\tWithdraw Successully !\n\t";
	}
	else
		cout << "\n\tInsufficient Balance! \n\t";
}

void SBIBank::accountBalanceReceipt()
{
	cout<<"\n\tYour Account Balance is : "<<accountBalance<<"\n\t";
}


SBIBank* SBIBankValidation::validateAccount(unsigned int accountNo, unsigned int passcode)
{
	for (unsigned short i = 0; i < SBICustomers.size(); i++)
	{
		SBIBank* value = SBICustomers[i].accountValidation(accountNo, passcode);
		if (value != nullptr)
		{
			customerIndexPositionInRecords = i;
			return value;
		}
	}
	customerIndexPositionInRecords = -1;
	return nullptr;
}


void SBIBankValidation::deleteSBIBankAccount(unsigned int accountNo, unsigned int passcode)
{
	SBIBank* ptr = SBIBankValidation::validateAccount(accountNo, passcode);
	if (ptr != nullptr && customerIndexPositionInRecords != -1)
	{
		SBICustomers.erase(SBICustomers.begin() + customerIndexPositionInRecords);
		customerIndexPositionInRecords = -1;
		cout << "\n\tYour account is deleted successfully !\n\t ";
	}
	cout << "\n\tInvalid AccountNo or Passcode \n\t";
}


void SBIBankValidation::createSBIBankAccount(string name, unsigned passcode)
{
	SBICustomers.push_back(SBIBank((++totalNumberOfAccountsCreated), name, passcode));
	cout << "\n\tAccount created successfully";
	cout << "\n\tYour Account No : " << totalNumberOfAccountsCreated << endl;
}



void SBIBankValidation::customerAccountOperations(unsigned short option , unsigned int accoutnNo,unsigned int passcode)
{
	switch (option)
	{
	case 1: {
		SBIBank* ptr = SBIBankValidation::validateAccount(accoutnNo, passcode);
		if (ptr != nullptr) {
			ptr->accountBalanceReceipt();
		}
		else
			cout << "\n\t Invalid Account No or Passcode \n\t";
		break;
	}

	case 3: {
		unsigned int amount;
		SBIBank* ptr = SBIBankValidation::validateAccount(accoutnNo, passcode);
		if (ptr != nullptr) {
			cout << "\n\tEnter the total money you wish to withdraw : \n\t";
			cin >> amount;
			ptr->withDrawMoney(amount);
		}
		else
			cout << "\n\t Invalid Account No or Passcode \n\t";
		break;
	}

	case 2: {

		unsigned int amount;
		SBIBank* ptr = SBIBankValidation::validateAccount(accoutnNo, passcode);
		if (ptr != nullptr) {
			cout << "\n\tEnter the total money you wish to deposit : \n\t";
			cin >> amount;
			ptr->depositMoney(amount);
		}
		else
			cout << "\n\t Invalid Account No or Passcode \n\t";
		break;
	}

	default:cout << "\n\tUnexpected Error Occured , Please try again ! ";

	};

}
