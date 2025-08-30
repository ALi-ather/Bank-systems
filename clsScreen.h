#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsDate.h"
#include "Global.h"

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t" << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t" << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
       //print user name and date
        cout << "\t\t\t\t\tUser: " << CurrentUser.FullName() << endl;
        cout << "\t\t\t\t\tDate: "<<clsDate::DateToString(clsDate())<<"\n\n";
    }

    static bool CheckAccessRights(clsUser::enPermissions Permissions)
    {
        if (!CurrentUser.CheckAccessPermission(Permissions))
        {
            cout << "\t\t\t\t\t___________________________________________";
			cout << "\n\n\t\t\t\t\tAccess Denied! Contact your Access .";
            cout << "\n\t\t\t\t\t___________________________________________";
            return false;
        }
        else
        {
            return true;
        }
    }

};

