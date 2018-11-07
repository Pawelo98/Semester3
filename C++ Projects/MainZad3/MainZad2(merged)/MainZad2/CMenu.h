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
#define NO_ITEM_TO_SEARCH "No item to search"
#define HELP_COMMAND "help "
#define SEARCH_COMMAND "search "

using namespace std;

class CMenu : public CMenuItem
{
private:
	bool root = false;
	CMenu *parent;
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
	CMenu* getParent();
	void setParent(CMenu *par);
	CMenu* findMain();
	void vSearch(string sCommand, string sPath);
	void vSearch(CMenu*);
	void vSetRoot() { root = true; }
	void vAddItem(CMenuItem* cItem);
	CMenuItem* GetItem(int iIndex);
	void vDeleteItem(int iIndex);
};

