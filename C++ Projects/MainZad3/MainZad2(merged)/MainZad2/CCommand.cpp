#include "pch.h"
#include "CCommand.h"
#include <iostream>

using namespace std;

CCommand::CCommand()
{
}// CCommand::CCommand()


CCommand::~CCommand()
{
}// CCommand::~CCommand()

void CCommand::RunCommand()
{
	cout << DEFAULT_STRING << endl;
}// void CCommand::RunCommand()

void CCommand::vHelpCommand()
{
	cout << EMPTY_QUOTE << endl;
}