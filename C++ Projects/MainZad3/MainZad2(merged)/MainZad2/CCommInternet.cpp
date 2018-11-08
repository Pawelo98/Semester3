#include "pch.h"
#include <iostream>
#include "CCommInternet.h"
#include <Windows.h>

using namespace std;

void CCommInternet::RunCommand()
{
	cout << OPEN_BROWSER << endl;
	ShellExecuteA(0, ACTION, WHAT_BROWSER, GOOGLE_ADRESS, 0, SW_MAXIMIZE);
	cout << CONTINUE_PROMPT << endl;
	getchar();
}// void CCommInternet::RunCommand()