#pragma once
#include "CMenuItem.h"
#include "CCommand.h"
#include <string>
#include <vector>
#define DELETE_COMM "deleted command"
#define EMPTY_STRING "Empty command"
#define EMPTY_QUOTE "No command"

using namespace std;

class CMenuCommand : public CMenuItem
{
private:
	CCommand* c_command;
public:
	CMenuCommand(string sName, string sCommand, CCommand* cc);
	~CMenuCommand();

	void vSearch(string sCommand, string sPath);
	int iRun();
	int iHelp();
};