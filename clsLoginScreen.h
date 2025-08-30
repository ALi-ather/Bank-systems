#pragma once  
#include "clsUser.h"  
#include <iostream>  
#include <iomanip>  
#include "clsMainScreen.h"  
#include "clsScreen.h"  
#include "Global.h"

using namespace std;  

class clsLoginScreen : protected clsScreen  
{
private:
	//if login 3 times faild cout << "You have been locked out of the system" and return to main screen

	static bool _Login() {
		bool LoginFaild = false;
		short FaildLoginCount = 0;	

		string Username, Password;

		do
		{
			if (LoginFaild ) {
				FaildLoginCount++;
				cout << "\nInvlaid Username/Password";
				cout << "\nYou have " << 3 - FaildLoginCount << " attempts left\n";
			}
			if(FaildLoginCount == 3) {
				cout << "\nYou have been locked out of the system\n";
				return false;
			}
			cout << "\nEnter Username : ";
			cin >> Username;

			cout << "\nEnter Password :";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);
			
			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
	}
public:
	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _Login();
	}

};
