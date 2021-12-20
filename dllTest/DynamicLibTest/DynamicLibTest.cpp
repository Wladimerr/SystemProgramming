// Владимир Труков ПР-315
#include <iostream>
#include "windows.h"

using namespace std;

typedef char* (*Inserting)(char* str1, char* str2, int start);
typedef char* (*ReplacingAllSubstr)(char* str3, char* str4, char* str5);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char str1[1024];
	char str2[1024];
	char str3[1024];

	int startIndex;

	HINSTANCE hLib;
	ReplacingAllSubstr replacingAllSubstr;
	Inserting inserting;
	hLib = LoadLibrary(TEXT("FunctionsForText.dll"));

	if (hLib != NULL) {
		cout << "YES\n";
	}


	cout << "Проверка динамического подключения библиотеки DLL\n\n";

	inserting = (Inserting)GetProcAddress(hLib, "Inserting");
	replacingAllSubstr = (ReplacingAllSubstr)GetProcAddress(hLib, "ReplacingAllSubstr");

	cout << "Вставка строки\n";
	cout << "Введите первую строку\n";
	cin >> str1;
	cout << "Введите строку для вставки в первую\n";
	cin >> str2;

	cout << "\nУкажите номер начала вставки: ";
	cin >> startIndex;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "\nОшибка ввода!\n";
		cout << "\nУкажите номер начала вставки: ";
		cin >> startIndex;
	}

	inserting(str1, str2, startIndex);
	cout << "Результат:\n" << str1 << "\n\n";

	cout << "Замена всех\n";
	cout << "Введите первую строку\n";
	cin >> str1;
	cout << "Введите вторую строку\n";
	cin >> str2;
	cout << "Введите третью строку\n";
	cin >> str3;

	replacingAllSubstr(str1, str2, str3);
	cout << "Замена всех " << str2 << " на " << str3 << " в первой строке:\n" << str1 << "\n\n";

	FreeLibrary(hLib);

	system("pause");
}
