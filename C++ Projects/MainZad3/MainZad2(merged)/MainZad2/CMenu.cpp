#include "pch.h"
#include "CMenu.h"
#include <iostream>

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

			if (SEARCH_COMMAND == s_prompt.substr(0, 7))
			{
		/*		if (root)
				{ */
					vSearch(s_prompt.substr(7, s_prompt.size() - 6), EMPTY_STRING);
					b_exist = true;
		/*		}// if (root)
				else return 0;*/
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
	bool bExist = false;
	for (int i = 0; i < v_menu_items.size(); i++)
		if (v_menu_items[i] == cItem || v_menu_items[i]->sGetCommand() == cItem->sGetCommand())
			bExist = true;
	if(!bExist) v_menu_items.push_back(cItem);
}// void CMenu::vAddItem(CMenuItem * item)
/*
void CMenu::vSearch(CMenu* elem)
{
	cout << elem->sGetName() + " -> " << endl;
	for (int i = 0; i < (*elem).v_menu_items.size(); i++)
	{
		cout << (*elem).v_menu_items[i]->sGetName() << endl;
		if ((*elem).v_menu_items[i]->iGetId() == 1)
		{
			vSearch((CMenu*)(*elem).v_menu_items[i]);
		}// if ((*elem).v_menu_items[i]->getId() == 1)
	}// for (int i = 0; i < (*elem).v_menu_items.size(); i++)
}// void CMenu::vSearch(CMenu* elem) */

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
	sPath.append(s_command + "->");

	for (int i = 0; i < v_menu_items.size(); i++)
	{
		v_menu_items.at(i)->vSearch(sCommand, sPath);

	}// for (int i = 0; i < v_menu_items.size(); i++)
}// void CMenu::vSearch(string sCommand, string sPath)
