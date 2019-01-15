#include "pch.h"
#include "CMenu.h"
#include <iostream>
#include <sstream>

using namespace std;

CMenu::CMenu(string sName, string sCommand) : CMenuItem(sName, sCommand)
{
	i_id = 1;
	system("cls");
}// CMenu::CMenu(string name, string command) : CMenuItem(name, command)

CMenu::~CMenu()
{
	cout << DELETE_MENU << endl;

	for (int i = 0; i < v_menu_items.size(); i++)
	{
		delete v_menu_items[i];
	}// for (int i = 0; i < v_menu_items.size(); i++)
	v_menu_items.clear();
}// CMenu::~CMenu()

int CMenu::iRun()
{
	string s_prompt;
	while (true) {
		cout << s_name << TWO_DOTS << s_command << endl;
		for (int i = 0; i < v_menu_items.size(); i++)
			cout << v_menu_items[i]->sGetName() << BRACKET_OPEN << v_menu_items[i]->sGetCommand() << BRACKET_CLOSE << endl;
		s_prompt.clear();
		while (s_prompt.size() < 1)
		{
			getline(cin, s_prompt);
		}//if (s_prompt.size() < 1)

		if (s_prompt != EMPTY_STRING)
		{
			bool b_exist = false;

			if (SEARCH_COMMAND == s_prompt.substr(0, 7))
			{
				CMenu *main = findMain();
				main->vSearch(s_prompt.substr(7, s_prompt.size() - 6), EMPTY_STRING);
				b_exist = true;
			}// if ("search " + v_menuItems[i]->sGetCommand() == s_prompt)

			for (int i = 0; i < v_menu_items.size(); i++)
			{
				if (v_menu_items[i]->sGetCommand() == s_prompt)
				{
					v_menu_items[i]->iRun();
					b_exist = true;
				}// if (v_menuItems[i]->sGetCommand() == s_prompt)
				if (HELP_COMMAND + v_menu_items[i]->sGetCommand() == s_prompt)
				{
					v_menu_items[i]->iHelp();
					b_exist = true;
				}// if ("help " + v_menuItems[i]->sGetCommand() == s_prompt)
			}// for (int i = 0; i < v_menuItems.size(); i++)
			cout << endl;
			if (s_prompt == GO_BACK)
			{
				return 0;
			}// if (s_prompt == "back")
			if (!b_exist)
			{
				cout << UNKNOWN_COMMAND << endl;
			}// if (!b_exist)
		}//if (s_prompt != "")
	}// while (!b_end)
}// int CMenu::iRun()

void CMenu::vAddItem(CMenuItem* cItem)
{
	CMenu *cNewMenu;
	cNewMenu = dynamic_cast<CMenu*>(cItem);
	if (cNewMenu)
	{
		cNewMenu->setParent(this);
	}// if (cNewMenu)
	bool bExist = false;
	for (int i = 0; i < v_menu_items.size(); i++)
		if (v_menu_items[i] == cItem || v_menu_items[i]->sGetCommand() == cItem->sGetCommand())
			bExist = true;
	if (!bExist) v_menu_items.push_back(cItem);
}// void CMenu::vAddItem(CMenuItem * item)

CMenu* CMenu::getParent()
{
	return cParent;
}// CMenu* CMenu::getParent() 

void CMenu::setParent(CMenu *cPar)
{
	this->cParent = cPar;
}// void CMenu::setParent(CMenu *par)

CMenu* CMenu::findMain()
{
	CMenu *main = cParent;
	if (!(main == NULL))
	{
		while ((*main).getParent())
		{
			main = (*main).getParent();
		}// while ((*main).getParent())
	}// if (main)
	else { main = this; }
	return main;
}// CMenu* CMenu::findMain()

CMenuItem* CMenu::GetItem(int iIndex)
{
	if (iIndex < 0 || iIndex >= v_menu_items.size())
		return NULL;
	return v_menu_items[iIndex];
}// CMenuItem* CMenu::GetItem(int nr)

void CMenu::vDeleteItem(int iIndex)
{
	bool bInside = true;
	if (iIndex < 0 || iIndex >= v_menu_items.size()) bInside = false;

	if (bInside)
	{
		//delete v_menu_items[iIndex];
		for (int i = iIndex; i < v_menu_items.size() - 1; i++)
			v_menu_items[i] = v_menu_items[i + 1];
		v_menu_items.pop_back();
	}// if (bInside)
}// void CMenu::vDeleteItem(int nr)

void CMenu::vSearch(string sCommand, string sPath)
{
	if (sCommand == s_command)
	{
		cout << sPath + s_command << endl;
	}// if (sCommand == s_command)
	sPath.append(s_command + POINTER);

	for (int i = 0; i < v_menu_items.size(); i++)
	{
		v_menu_items.at(i)->vSearch(sCommand, sPath);
	}// for (int i = 0; i < v_menu_items.size(); i++)
}// void CMenu::vSearch(string sCommand, string sPath)

string CMenu::parseToString()
{
	string sParsed = EMPTY_STRING;
	sParsed += BRACKET_OPEN;
	sParsed += CHAR_TO_PARSE;
	sParsed += s_name;
	sParsed += COMMA_TO_PARSE;
	sParsed += s_command;
	sParsed += END_TO_PARSE;
	for (int i = 0; i < v_menu_items.size(); i++)
	{
		sParsed += v_menu_items.at(i)->parseToString();
		if (v_menu_items.size() - 1 != i)
		{
			sParsed += COMMA2_TO_PARSE;
		}// if (v_menu_items.size() - 1 != i)
	}// for (int i = 0; i < v_menu_items.size(); i++)
	sParsed += BRACKET_CLOSE;
	return sParsed;
}// string CMenu::parseToString()

void CMenu::vShowLevels(int iNeed)
{
	if (root) cout << s_name << endl;
	for (int i = 0; i < v_menu_items.size(); i++)
	{
		cout << v_menu_items.at(i)->sGetName() + "  ";
	}// for (int i = 0; i < v_menu_items.size(); i++)
	if (iNeed == 0) cout << endl;
	for (int j = 0; j < v_menu_items.size(); j++)
	{
		if (j == 0) iNeed = v_menu_items.size();
		v_menu_items.at(j)->vShowLevels(iNeed--);
	}
}// void CMenu::vShowLevels()