#include "pch.h"
#include "CMenuCommand.h"
#include <iostream>

using namespace std;

CMenuCommand::CMenuCommand(string sName, string sCommand, CCommand * cc) : CMenuItem(sName, sCommand), c_command(cc)
{
}// CMenuCommand::CMenuCommand(string name, string command, CCommand * cc) : CMenuItem(name, command), c_command(cc)

CMenuCommand::~CMenuCommand()
{
	cout << DELETE_COMM << endl;
	delete c_command;
}// CMenuCommand::~CMenuCommand()

int CMenuCommand::iRun()
{
	if (c_command == NULL)
	{
		cout << EMPTY_STRING << endl;
		return 0;
	}// if (c_command == NULL)
	else
		c_command->RunCommand();
	return 0;
}// int CMenuCommand::iRun()

int CMenuCommand::iHelp()
{
	if (c_command == NULL)
	{
		cout << EMPTY_QUOTE << endl;
		return 0;
	}// if (c_command == NULL)
	else
		c_command->vHelpCommand();
	return 0;
}
