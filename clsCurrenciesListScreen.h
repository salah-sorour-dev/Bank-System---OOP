#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsCurrency.h"


class clsCurrenciesListScreen : protected clsScreen
{
private:

    static void _PrintCurrenciesRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(10) << left << Currency.CurrencyCode();
        cout << "| " << setw(50) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();

    }

public:

	static void ShowCurrenciesList()
	{
        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") currencies.";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(10) << "Code";
        cout << "| " << left << setw(50) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsCurrency Currency : vCurrencies)
            {
                _PrintCurrenciesRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________________________\n" << endl;

	}
};