#pragma once
#include <string>
#define DELETE_ITEM "deleted item"

using namespace std;

class CMenuItem
{
protected:
	int i_id;
	string s_command;
	string s_name;
public:
	CMenuItem();
	CMenuItem(string sName, string sCommand);
	virtual  ~CMenuItem();

	virtual void vSearch(string sCommand, string sPath) {};
	virtual void vShowLevels(int iNeed) {};
	virtual int iRun() = 0;
	virtual int iHelp() = 0;
	virtual string parseToString() { return string(); };
	int iGetId();
	string sGetName();
	string sGetCommand();
};
