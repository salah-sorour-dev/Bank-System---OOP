#pragma once
#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"
#include <windows.h>

class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFaild = false;

		short FaildLoginCount = 0;

		string Username, Password;
		do
		{
			if (LoginFaild)
			{
				FaildLoginCount++;
				cout << "\nInvalid Username/Password!\n\n";
				cout << "You have " << (3 - FaildLoginCount) << " Trial(s) to login.\n\n";

			}

			if (FaildLoginCount == 3)
			{
				cout << "\nYour are Locked after 3 fails trails\n\n";
				return false;
			}

			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t   Login Screen");
		return _Login();
	}
};