#pragma once
#include "CMenuItem.h"
#include "CCommand.h"
#include <string>
#include <vector>
#define DELETE_COMM "deleted command"
#define EMPTY_STRING "Empty command"

using namespace std;

class CMenuCommand : public CMenuItem
{
private:
	CCommand* c_command;
public:
	CMenuCommand(string sName, string sCommand, CCommand* cc);
	~CMenuCommand();
	int iRun();
};