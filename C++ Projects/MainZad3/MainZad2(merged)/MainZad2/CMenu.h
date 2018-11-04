#pragma once
#include "CMenuItem.h"
#include <vector>
#include <string>
#include <iostream>
#define UNKNOWN_COMMAND "Nieznana komenda"
#define GO_BACK "back"
#define DELETE_MENU "deleted menu"
#define BRACKET_OPEN " ("
#define BRACKET_CLOSE ") "
#define EMPTY_STRING ""
#define NO_COMMAND "No command"

using namespace std;

class CMenu : public CMenuItem
{
private:
	vector<CMenuItem*> v_menu_items;
public:
	CMenu(string sName, string sCommand);
	~CMenu();

	int iRun();
	int iHelp() 
	{ 
		cout << NO_COMMAND << endl;
		return 0;
	}
	void vAddItem(CMenuItem* cItem);
	CMenuItem* GetItem(int iIndex);
	void vDeleteItem(int iIndex);
};

