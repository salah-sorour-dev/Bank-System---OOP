#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsTransferLogScreen : protected clsScreen
{
private:

	static void PrintTransferLogRecordLine(clsBankClient::stTransferRecord TransferRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(23) << left << TransferRecord.DateTime;
		cout << "| " << setw(8) << left << TransferRecord.sAcct;
		cout << "| " << setw(8) << left << TransferRecord.dAcct;
		cout << "| " << setw(8) << left << TransferRecord.Amount;
		cout << "| " << setw(10) << left << TransferRecord.sBalance;
		cout << "| " << setw(10) << left << TransferRecord.dBalance;
		cout << "| " << setw(8) << left << TransferRecord.UserName;
	}

public:

	static void ShowTransferLogScreen()
	{

		vector <clsBankClient::stTransferRecord> vTransferlogRecord = clsBankClient::GetTransferLogList();
		string Title = "\tTransfer Log List Screen";
		string SubTitle = "\t\t(" + to_string(vTransferlogRecord.size()) + ") Record(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << "| " << left << setw(8) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vTransferlogRecord.size() == 0)
			cout << "\t\t\t\tNo Transfers Available In the System!";

		else

			for (clsBankClient::stTransferRecord Record : vTransferlogRecord)
			{
				PrintTransferLogRecordLine(Record);
				cout << endl;
			}


		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}
};