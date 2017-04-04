// LR4b-3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<clocale>
#include<Windows.h>
using namespace std;
int main()
{
	HANDLE hEvent;
	setlocale(LC_ALL, "rus");
	hEvent = OpenEvent(EVENT_ALL_ACCESS, TRUE, L"MeEvent1");
	if (hEvent == 0)
	{
		cout << "Ошибка открытия объекта - события, созданного в другом приложении";
		_getch();
		return 0;
	}
	cout << "Нажмите любую клавишу для запуска потоков" << endl;
	_getch();
	SetEvent(hEvent);
	cout << "Для завершения потоков в другом приложении нажмите любую клавишу" << endl;
	_getch();
	ResetEvent(hEvent);
	_getch();
	return 0;
}

