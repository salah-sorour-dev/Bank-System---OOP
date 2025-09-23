
#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>


using namespace std;


void ReadClientInfo(clsBankClient& Client)
{
    cout << "\nEnter FirstName: ";
    Client.FirstName = clsInputValidate::ReadString();

    cout << "\nEnter LastName: ";
    Client.LastName = clsInputValidate::ReadString();

    cout << "\nEnter Email: ";
    Client.Email = clsInputValidate::ReadString();

    cout << "\nEnter Phone: ";
    Client.Phone = clsInputValidate::ReadString();

    cout << "\nEnter PinCode: ";
    Client.PinCode = clsInputValidate::ReadString();

    cout << "\nEnter Balance: ";
    Client.AccountBalance = clsInputValidate::ReadFloatNumber();
}

void AddNewClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number Is Already Used, Choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Updates Successfully :-)\n";
        NewClient.Print();
        break;
    }

    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;
    }
    case clsBankClient::enSaveResults::svFaildAccountNumberExists:
    {

    }
    }
}

void UpdateClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();

    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\nUpdate Client Info:";
    cout << "\n__________________";

    ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = Client1.Save();

    switch (SaveResult)
    {
    case clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Updates Successfully :-)\n";
        Client1.Print();
        break;
    }

    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;
    }
    }

}

void DeleteClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number is not found, choode another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout << "\nAre you sure you want to delete this client y/n? ";

    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        if (Client1.Delete())
        {
            cout << "\nClient Deleted Successfully :-)\n";
            Client1.Print();
        }
        else
        {
            cout << "\nError Client was not Deleted\n";
        }
    }
}

void PrintClientRecordLine(clsBankClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(20) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(20) << left << Client.Email;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(12) << left << Client.AccountBalance;

}

void ShowClientsList()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s)";
    cout << "\n_____________________________________________________________";
    cout << "___________________________________________\n";

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";

    cout << "\n_____________________________________________________________";
    cout << "___________________________________________\n";

    if (vClients.size() == 0)

        cout << "\t\t\t\tNo Clients Available In the System!";

    else

        for (clsBankClient Client : vClients)
        {
            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_____________________________________________________________";
    cout << "___________________________________________\n";
}

int main()
{
    
    //UpdateClient();

    //AddNewClient();

    //DeleteClient();

    ShowClientsList();


    system("pause>0");
    return 0;
}

