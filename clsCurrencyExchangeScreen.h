#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "Global.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"


class clsCurrencyExchangeScreen : protected clsScreen
{
private:
	enum enCurrencyExchangeOption {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
		eCurrencyCalculator = 4, eMainMenue = 5
	};

	static short ReadCurrencyExchangeMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static void _GoBackToCurrencyExchangeMenue()
	{
		cout << "\n\nPress any key to go back to Currency Exchange Menue...";
		system("pause>0");
		ShowCurrencyExchangeMenue();
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "\nList Currencies Screen Will be Here.\n";
		clsCurrenciesListScreen::ShowCurrenciesList();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Screen Will be Here.\n";
		clsFindCurrencyScreen::ShowFindCurrencScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		cout << "\nUpdate Rate Screen Will be Here.\n";
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		cout << "\nCurrency Calculator Screen Will be Here.\n";
	}

	static void _PerformCurrencyExchangeMenueOption(enCurrencyExchangeOption CurrencyExchangeOption)
	{
		switch (CurrencyExchangeOption)
		{
		case enCurrencyExchangeOption::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeOption::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeOption::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeOption::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeOption::eMainMenue:
		{
			//do nothing here the main screen will handle it.
		}
		}
	}


public:

	static void ShowCurrencyExchangeMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
		{
			return; // this will exit the function and it will not continue.
		}

		system("cls");
		_DrawScreenHeader("\t Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t\t\t  Currency Exchange Menue\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "=============================================\n";

		_PerformCurrencyExchangeMenueOption((enCurrencyExchangeOption)ReadCurrencyExchangeMenueOption());
	}
};