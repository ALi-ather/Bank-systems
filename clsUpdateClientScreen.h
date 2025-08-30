#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"

using namespace std;
class clsUpdateClientScreen :protected clsScreen
{
private:
	static void ReadClientInfo(clsBankClient& client)
	{
		cout << "\nEnter Client First Name: ";
		client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Client Last Name: ";
		client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Client Email: ";
		client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Client Phone Number: ";
		client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Client Pincode: ";
		client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter Account Balance: ";
		client.AccountBalance = clsInputValidate::ReadNumber<float>(); // Change ReadString to ReadFloat
	}
	static void  _PrintClient(clsBankClient Client) {
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}


public:
	static void ShowUpdateClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
		{
			return;
		}
		_DrawScreenHeader("\tUpdate Client Screen");

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

			cout << "\n\nUpdate Client Information\n";
			cout << "\n___________________\n";
			ReadClientInfo(Client);

			clsBankClient::enSaveResults SaveResult;

			SaveResult = Client.Save();

			switch (SaveResult)
			{
			case clsBankClient::enSaveResults::svSucceeded:
			{
				cout << "\nAccount Updated Successfully.\n";
				_PrintClient(Client);
				break;
			}
			case clsBankClient::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nFailed to update account. Object is empty.\n";
				break;
			}
			}

		}


};

