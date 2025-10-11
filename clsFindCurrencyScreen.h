#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
        cout << "\nCurrency Card:";
        cout << "\n___________________";
        cout << "\nCountry   : " << Currency.Country();
        cout << "\nCode      : " << Currency.CurrencyCode();
        cout << "\nName      : " << Currency.CurrencyName();
        cout << "\nRate(1$)  : " << Currency.Rate();
        cout << "\n___________________\n";
	}

    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:

	static void ShowFindCurrencScreen()
	{
        vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

        _DrawScreenHeader("\t Find User Screen");

        short FindBy = 0;

        cout << "\nFind By: [1] Code or [2] Country ? ";
        FindBy = clsInputValidate::ReadShortNumberBetween(1, 2, "Please Enter 1 or 2: ");


        if (FindBy == 1)
        {
            string CurrencyCode = "";
            cout << "\nPlease Enter Currency Code: ";
            CurrencyCode = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
        }
        else
        {
            string Country = "";
            cout << "\nPlease Enter Country Name: ";
            Country = clsInputValidate::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency);
        }



	}
};