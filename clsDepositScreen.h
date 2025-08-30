#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsDepositScreen : protected clsScreen
{
	private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:\n";
		cout << "____________________________\n";
		cout << "First Name  : " << Client.FirstName << endl;
		cout << "Last Name   : " << Client.LastName << endl;
		cout << "Full Name   : " << Client.FullName() << endl;
		cout << "Email       : " << Client.Email << endl;
		cout << "Phone       : " << Client.Phone << endl;
		cout << "Account No. : " << Client.AccountNumber() << endl;
		cout << "PIN         : " << Client.PinCode << endl;
		cout << "Balance     : " << Client.AccountBalance << endl;
		cout << "____________________________\n";
	}
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter account number? ";
		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}
public:
	static void ShowDepositScreen() {
		_DrawScreenHeader("\t Deposit Screen");
		string AccountNumber = _ReadAccountNumber();

		while(!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with account number (" << AccountNumber << ") is not found, please try again.\n";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		double Amount = 0;
		cout << "\nPlease enter amount to deposit? ";
		Amount = clsInputValidate::ReadNumber<double>();
		
		cout << "\nAre you sure you want to deposit " << Amount << " to " << Client.FullName() << " ? [Y/N] ";
		char Answer = 'N';
		cin >> Answer;

		if(Answer == 'Y' || Answer == 'y')
		{
			Client.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "New Balance IS : " << Client.AccountBalance << endl;
		}
		else
		{
			cout << "\nOperation canceled!\n";
		}
	}
};

