#pragma once
#include "CMenuItem.h"
#include <vector>
#include <string>
#define UNKNOWN_COMMAND "Nieznana komenda"
#define GO_BACK "back"
#define DELETE_MENU "deleted menu"
#define BRACKET_OPEN " ("
#define BRACKET_CLOSE ") "
#define EMPTY_STRING ""

using namespace std;

class CMenu : public CMenuItem
{
private:
	vector<CMenuItem*> v_menu_items;
public:
	CMenu(string sName, string sCommand);
	~CMenu();

	int iRun();
	void vAddItem(CMenuItem* cItem);
	CMenuItem* GetItem(int iIndex);
	void vDeleteItem(int iIndex);
};

