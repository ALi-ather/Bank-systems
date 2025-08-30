#pragma once
#include<iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;


class clsWithdrawScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:\n";
		cout << "____________________________\n";
		cout << "\nFirst Name  : " << Client.FirstName;
		cout << "\nLast Name   : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAccount No. : " << Client.AccountNumber();
		cout << "\nPIN         : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n____________________________\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter account number? ";
		cin >> AccountNumber;
		return AccountNumber;

	}
	public:
		static void ShowWithdrawScreen()
		{
			_DrawScreenHeader("\t Withdraw Screen");
			string AccountNumber = _ReadAccountNumber();
			while (!clsBankClient::IsClientExist(AccountNumber))
			{
				cout << "\nAccount number is not found, choose another one.\n";
				AccountNumber = _ReadAccountNumber();
			}
			clsBankClient Client = clsBankClient::Find(AccountNumber);
			_PrintClient(Client);
			double Amount = 0;
			cout << "\nPlease enter amount to withdraw? ";
			Amount = clsInputValidate::ReadNumber<double>();

			cout << "\nAre you sure you want to withdraw " << Amount << " from " << Client.FullName() << " account? (y/n)? ";
			char Answer = 'n';
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
			{
				if ( Client.Withdraw(Amount))
				{
					cout << "\nDone successfully, new balance is: " << Client.AccountBalance << "\n";
				}
				else
				{
					cout << "\nFailed withdraw, you don't have enough balance.\n";
				}
			}
			else
			{
				cout << "\nWithdraw operation canceled.\n";
			}
		}
};

