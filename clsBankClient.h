#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"

using namespace std;



class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Separator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Separator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}

	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Client.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				vClients.push_back(Client);
			}

			MyFile.close();
		}
		return vClients;
	}

	static void _SaveCleintsDataToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("CLients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsBankClient C : vClients)
			{
				DataLine = _ConverClientObjectToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveCleintsDataToFile(_vClients);
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCode, float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}
	_declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccounBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccounBalance()
	{
		return _AccountBalance;
	}
	_declspec(property(get = GetAccounBalance, put = SetAccounBalance)) float AccountBalance;

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n____________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFullName    : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n____________________\n";
	}

	static clsBankClient Find(string AccountNumber)
	{
		vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);

				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}

				vClients.push_back(Client);
			}

			MyFile.close();
		}

	}


	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);

				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}

				vClients.push_back(Client);
			}

			MyFile.close();
		}

	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}

		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}
		}
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

};