#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsTransactionsScreen : protected clsScreen
{
private:
	enum enTransactionsMainMenueOptions {
		eDeposit = 1, eWithdraw = 2, 
		eShowTotalBalance = 3, eTransfer = 4,
		eTransferLog = 5, eShowMainMenue = 6
	};

	static short ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
		return Choice;
	}

	static void _ShowDepositScreen()
	{
		//cout << "\n Deposit Screen will be here.\n";
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		//cout << "\n Withdraw Screen will be here.\n";
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		//cout << "\n Total Balances Screen will be here.\n";
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		//cout << "\n Total Balances Screen will be here.\n";
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		//cout << "\n Total Balances Screen will be here.\n";
		clsTransferLogScreen::ShowTransferLogScreen();

	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any key to go back to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenue();
	}

	static void _PerformTransactionsMenueOption(enTransactionsMainMenueOptions TransactionsMenueOption)
	{
		switch (TransactionsMenueOption)
		{
		case enTransactionsMainMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMainMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMainMenueOptions::eShowTotalBalance:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMainMenueOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMainMenueOptions::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenue();
			break;
		}

		case enTransactionsMainMenueOptions::eShowMainMenue :
		{
			//do nothing here the main screen :-)
		}
		}
	}

public:

	static void ShowTransactionsMenue()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return; // this will exit the function and it will not continue.
		}

		system("cls");
		_DrawScreenHeader("\t  Transactions Screen");

		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t\t\tTransactions Menue\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "=============================================\n";

		_PerformTransactionsMenueOption((enTransactionsMainMenueOptions)ReadTransactionsMenueOption());
	}
};
