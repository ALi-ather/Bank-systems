#include <iostream>  
#include "clsBankClient.h"  
#include "clsInputValidate.h"
#include "clsDate.h"  
#include <iomanip> // Add this header for setw
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsLoginScreen.h"


int main()
{
	while (true) {
		if (!clsLoginScreen::ShowLoginScreen()) {
			break; // Exit the program if login fails or user chooses to exit
		}
	}
	return 0;
}