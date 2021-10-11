#include "stdafx.h"

#include "Resources.h"
#include "Utils.h"


int getChoice(const char* prompt, int variantsCount, ...)
{
	char buff[8];

	cout << endl << prompt << ':' << endl;

	va_list variants;
	va_start(variants, variantsCount);
	for (int i = 0; i < variantsCount; i++)
	{
		cout << "  " << _itoa(i + 1, buff, 10) << " - " << va_arg(variants, char *) << endl;
	}
	cout << endl;
	va_end(variants);

	while (true)
	{
		cout << "> ";

		int result;
		if (cin >> result)
		{
			if (result >= 1 && result <= variantsCount)
				return result;
		}
		else
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		cout << Message::EnterNumberFrom_N_To_ << _itoa(variantsCount, buff, 10) << '!' << endl;
	};
}

int getChoice(Message prompt, int variantsCount, ...)
{
	char buff[8];

	while (true)
	{
		cout << endl << prompt << ':' << endl;

		va_list variants;
		va_start(variants, variantsCount);
		for (int i = 0; i < variantsCount; i++)
		{
			cout << "  " << _itoa(i + 1, buff, 10) << " - " << va_arg(variants, Message) << endl;
		}
		va_end(variants);

		cout << endl;
		cout << "  " << _itoa(variantsCount + 1, buff, 10) << " - " << Message::ChangeLanguagePrompt << endl;
		cout << endl;

		while (true)
		{
			cout << "> ";

			int result;
			if (cin >> result)
			{
				if (result >= 1 && result <= variantsCount)
				{
					return result;
				}
				else if (result == variantsCount + 1)
				{

					resources.SetLanguage(Language::Russian == resources.GetLanguage() ? Language::English : Language::Russian);
					cout << endl;
					break;
				}
			}
			else
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}

			cout << Message::EnterNumberFrom_N_To_ << _itoa(variantsCount + 1, buff, 10) << '!' << endl;
		};
	}
}

bool confirm(const char* prompt)
{
	while (true)
	{
		cout << prompt << " (Yes|No) > ";

		char answer = _getch();
		cout << endl;

		if ('y' == answer || 'Y' == answer || '1' == answer)
			return true;
		if ('n' == answer || 'N' == answer || '0' == answer)
			return false;

		cout << Message::Enter_Y_Or_N << endl;
	}
}

bool getValue(const char* prompt, int& value)
{
	cin.ignore(INT_MAX, '\n');

	cout << prompt << " > ";
	if (cin >> value) 
		return true;
	else
	{
		cout << Message::BadValue << endl;
		return false;
	}
}

bool getValue(const char* prompt, unsigned int& value)
{
	cin.ignore(INT_MAX, '\n');

	cout << prompt << " > ";
	if (cin >> value)
	{
		return true;
	}
	else
	{
		cout << Message::BadValue << endl;
		return false;
	}
}

bool getValue(const char* prompt, float& value)
{
	cin.ignore(INT_MAX, '\n');

	cout << prompt << " > ";
	if (cin >> value)
	{
		return true;
	}
	else
	{
		cout << Message::BadValue << endl;
		return false;
	}
}

bool getValue(const char* prompt, char* value)
{
	cin.ignore(INT_MAX, '\n');

	cout << prompt << " > ";

	if (cin >> value && 0 != value[0])
	{
		return true;
	}
	else
	{
		cout << Message::EmptyValue << endl;
		return false;
	}
}

bool checkAccess(const char* password, int tryCount)
{
	cin.ignore(INT_MAX, '\n');

	for (int iTry = 0; iTry < tryCount; iTry++)
	{
		cout << Message::EnterPassword << " > ";

		char enteredPassword[64];
		cin.getline(enteredPassword, sizeof(enteredPassword) / sizeof(enteredPassword[0]));

		if (0 == strcmp(password, enteredPassword))
			return true;
		else
			cout << Message::InvalidPassword << endl;
	}

	cout << Message::RetriesCountExceeded << endl;
	return false;
}
