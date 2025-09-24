#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsFindClientScreen : protected clsScreen
{
private:
    static void _PrinClient(clsBankClient Client)
    {
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

    static void ShowFindClientScreen()
    {
        _DrawScreenHeader("\tFind CLient Screen");

        string AccountNumber = "";
        
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found, choode another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        
        if (!Client1.IsEmpty())

            cout << "\nClient Found :-)\n";

        else

            cout << "\nClient Was not Found :-(\n";

        _PrinClient(Client1);
        
    }
};