#pragma once
#include <string>
#define DELETE_ITEM "deleted item"

using namespace std;

class CMenuItem
{
protected:
	string s_command;
	string s_name;
public:
	CMenuItem();
	CMenuItem(string sName, string sCommand);
	virtual  ~CMenuItem();

	virtual int iRun() = 0;
	virtual int iHelp() = 0;
	string sGetName();
	string sGetCommand();
};
