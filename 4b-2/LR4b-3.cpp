// LR4b-3.cpp: ���������� ����� ����� ��� ����������� ����������.
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
		cout << "������ �������� ������� - �������, ���������� � ������ ����������";
		_getch();
		return 0;
	}
	cout << "������� ����� ������� ��� ������� �������" << endl;
	_getch();
	SetEvent(hEvent);
	cout << "��� ���������� ������� � ������ ���������� ������� ����� �������" << endl;
	_getch();
	ResetEvent(hEvent);
	_getch();
	return 0;
}

