#include "pch.h"
#include "CMenu.h"
#include <iostream>

using namespace std;

CMenu::CMenu(string sName, string sCommand) : CMenuItem(sName, sCommand)
{
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
		cout << s_name << ": " << s_command << endl;
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

			for (int i = 0; i < v_menu_items.size(); i++)
			{
				if (v_menu_items[i]->sGetCommand() == s_prompt)
				{
					v_menu_items[i]->iRun();
					cout << endl;
					b_exist = true;
				}// if (v_menuItems[i]->sGetCommand() == s_prompt)
			}// for (int i = 0; i < v_menuItems.size(); i++)
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

void CMenu::vAddItem(CMenuItem * cItem)
{
	bool bExist = false;
	for (int i = 0; i < v_menu_items.size(); i++)
		if (v_menu_items[i] == cItem || v_menu_items[i]->sGetCommand() == cItem->sGetCommand())
			bExist = true;
	if(!bExist) v_menu_items.push_back(cItem);
}// void CMenu::vAddItem(CMenuItem * item)

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
