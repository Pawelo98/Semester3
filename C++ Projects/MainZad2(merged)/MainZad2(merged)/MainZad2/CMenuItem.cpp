#include "pch.h"
#include "CMenuItem.h"
#include <iostream>

using namespace std;

CMenuItem::CMenuItem()
{
}//CMenuItem::CMenuItem()

CMenuItem::CMenuItem(string sName, string sCommand) : s_name(sName), s_command(sCommand)
{
}// CMenuItem::CMenuItem(string sName, string sCommand) : s_name(sName), s_command(sCommand)

CMenuItem::~CMenuItem()
{
	cout << DELETE_ITEM << endl;
}// CMenuItem::~CMenuItem()

string CMenuItem::sGetName()
{
	return s_name;
}// string CMenuItem::sGetName()

string CMenuItem::sGetCommand()
{
	return s_command;
}// string CMenuItem::sGetCommand()
