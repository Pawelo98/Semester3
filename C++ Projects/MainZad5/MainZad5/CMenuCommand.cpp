#include "pch.h"
#include "CMenuCommand.h"
#include <iostream>
#include <sstream>

using namespace std;

CMenuCommand::CMenuCommand(string sName, string sCommand, string sHelp, CCommand * cc) : CMenuItem(sName, sCommand), c_command(cc)
{
	s_help = sHelp;
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
	else c_command->vHelpCommand();
	return 0;
}

void CMenuCommand::vSearch(string sCommand, string sPath)
{
	if (sCommand == s_command)
	{
		cout << sPath + s_command << endl;
	}// if (command == s_command)
}// void CMenuCommand::vSearch(string sCommand, string sPath)

string CMenuCommand::parseToString()
{
	string sParsed = EMPTY_STRING;
	sParsed += OPEN_BRACKET;
	sParsed += s_name;
	sParsed += COMMA;
	sParsed += s_command;
	sParsed += COMMA;
	sParsed += s_help;
	sParsed += CLOSE_BRACKET;
	return sParsed;
}// string CMenuCommand::parseToString()
