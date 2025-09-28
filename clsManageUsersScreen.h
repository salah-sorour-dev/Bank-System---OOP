#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{
private:
	enum enManageUsersMenueOption {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, 
		eUpdateUsers = 4, eFindUser = 5, eMainMenue = 6
	};

	static short ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowListUsersScreen()
	{
		//cout << "\nList Users Screen Will be Here.\n";
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "\nAdd New User Screen Will be Here.\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "\nDelete User Screen Will be Here.\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUsersScreen()
	{
		//cout << "\nUpdate User Screen Will be Here.\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		//cout << "\nFind User Screen Will be Here.\n";
		clsFindUserScreen::ShowFindUserScreen();
	}


	static void _PerformManageUsersMenueOption(enManageUsersMenueOption ManageUsersMenueOption)
	{
		switch (ManageUsersMenueOption)
		{
		case enManageUsersMenueOption::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enManageUsersMenueOption::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enManageUsersMenueOption::eDeleteUser :
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enManageUsersMenueOption::eUpdateUsers:
		{
			system("cls");
			_ShowUpdateUsersScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enManageUsersMenueOption::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enManageUsersMenueOption::eMainMenue:
		{
			//do nothing here the main screen will handle it.
		}
		}
	}


public:
	static void ShowManageUsersMenue()
	{
		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "=============================================\n";

		_PerformManageUsersMenueOption((enManageUsersMenueOption)ReadManageUsersMenueOption());
	}
};