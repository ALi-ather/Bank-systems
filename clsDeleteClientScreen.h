#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsString.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client) {
		cout << "\nClient Card:\n";
		cout << "____________________________\n";
		cout << "\nFirst Name      : " << Client.FirstName;
		cout << "\nLast Name       : " << Client.LastName;
		cout << "\nFull Name       : " << Client.FullName();
		cout << "\nAccount Number  : " << Client.AccountNumber();
		cout << "\nEmail           : " << Client.Email;
		cout << "\nPhone           : " << Client.Phone;
		cout << "\nBalance         : " << Client.AccountBalance;
		cout << "\n____________________________\n";
	}
public:
	static void ShowDeleteClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}
		_DrawScreenHeader("\tDelete Client Screen");
		string AccountNumber = "";
		cout << "\nEnter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number does not exist. Please enter a valid Account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		cout << "\n\nAre you sure you want to delete this account? (Y/N): ";
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
			if (Client.Delete())
			{
				cout << "\nAccount deleted successfully.\n";
				_PrintClient(Client);
			}
			else
			{
				cout << "\nFailed to delete account.\n";
			}
	}
};

