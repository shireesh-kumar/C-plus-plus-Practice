#include <map>
#include <string>
#include<vector>
#include<string>
using namespace std;

class SBIBank
{

private:
	unsigned int accountNo;
	string customerName;
	unsigned int passcode;
	unsigned int accountBalance;


public:
	SBIBank(unsigned int accountNo, string name, unsigned passcode) :accountNo{ accountNo }, customerName{ name }, passcode{ passcode }, accountBalance{ 0 }
	{}

	SBIBank* accountValidation(unsigned int, unsigned int);

	void depositMoney(unsigned int);

	void withDrawMoney(unsigned int);

	void accountBalanceReceipt();

};


class SBIBankValidation
{
public:

	//SBIBankValidation() = delete;

	 SBIBank* validateAccount(unsigned int, unsigned int);
	
	 void createSBIBankAccount(string, unsigned);
	
	 void deleteSBIBankAccount(unsigned int, unsigned int);

	 void customerAccountOperations(unsigned short,unsigned int,unsigned int );

private:
	  vector<SBIBank> SBICustomers;
	  unsigned int totalNumberOfAccountsCreated  ;
	  short customerIndexPositionInRecords;
};