#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"


using namespace std;
class clsAddNewClientScreen : protected clsScreen
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
	static void ShowAddNewClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}
		_DrawScreenHeader("\t Add New Client Screen");
		string AccountNumber = "";
		cout << "\nEnter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number already exists. Please enter a new Account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Created Successfully.\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nFailed to create account. Object is empty.\n";
			break;
		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nFailed to create account. Account number already exists.\n";
			break;
		}
		}
	}
};

