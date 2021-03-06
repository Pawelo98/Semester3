#pragma once
#include "pch.h"
#include "CTable.h"
#include "CMenu.h"
#include "CMainHeader.h"
#include "CMenuCommand.h"
#include "CCommFun.h"
#include "CMainHeader.h"
#include "CCommAla.h"
#include "CCommInternet.h"
#include "CDefaultComm.h"
#include "CMenuToString.h"
#include <iostream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{/*
	CMenuToString * parser = new CMenuToString();
	CMenu * main = parser->parseFromString(TEST_TEXT);
	string menuString = main->parseToString();
	cout << menuString << endl;
	main->iRun();*/

	CMenu * main = new CMenu("A", MENU_GET);
	main->vSetRoot();
	CMenu* menu1 = new CMenu(MENU1_COMMAND, MENU1_GET);
	CMenu* menu2 = new CMenu(MENU2_COMMAND, MENU2_GET);

	CCommAla* alaComm = new CCommAla();
	CMenuCommand* ala = new CMenuCommand(ALA_COMM, ALA_TEXT, ALA_HELP, alaComm);

	(*main).vAddItem(menu1);
	(*main).vAddItem(menu2);
	(*main).vAddItem(ala);

	CCommInternet* internetComm = new CCommInternet();
	CMenuCommand* przegladarka = new CMenuCommand(INTERNET_OPEN, INTERNET_TEXT, INTERNET_HELP, internetComm);
	CDefaultComm* defaultComm = new CDefaultComm();
	CMenuCommand* def = new CMenuCommand(DEFAULT_STRING, DEFAULT_GET, DEFAULT_STRING, defaultComm);
	CCommFun* create_obj_f = new CCommFun(vCreateInMenu, &v_ctable_objects, CREATE_STRING);
	CCommFun* change_obj_name_f = new CCommFun(vChangeObjectName, &v_ctable_objects, CHANGE_STRING);
	CCommFun* delete_obj_f = new CCommFun(vDeleteObject, &v_ctable_objects, DELETE_STRING);
	CCommFun* clone_obj_f = new CCommFun(vCloneObject, &v_ctable_objects, CLONE_STRING);
	CCommFun* print_obj_f = new CCommFun(vPrintObject, &v_ctable_objects, PRINT_STRING);
	CCommFun* enter_val_f = new CCommFun(vEnterValue, &v_ctable_objects, ENTER_STRING);
	CCommFun* change_tab_size_f = new CCommFun(vChangeTableSize, &v_ctable_objects, RESIZE_STRING);
	CCommFun* clear_vector_f = new CCommFun(vClearVector, &v_ctable_objects, CLEAR_STRING);

	CMenuCommand* create_obj = new CMenuCommand(CREATE_NAME, CREATE_COMM, CREATE_STRING, create_obj_f);
	CMenuCommand* change_obj_name = new CMenuCommand(CHANGE_NAME, CHANGE_COMM, CHANGE_STRING, change_obj_name_f);
	CMenuCommand* delete_obj = new CMenuCommand(DELETE_NAME, DELETE_COMM, DELETE_STRING, delete_obj_f);
	CMenuCommand* clone_obj = new CMenuCommand(CLONE_NAME, CLONE_COMM, CLONE_STRING, clone_obj_f);
	CMenuCommand* print_obj = new CMenuCommand(PRINT_NAME, PRINT_COMM, PRINT_STRING, print_obj_f);
	CMenuCommand* enter_val = new CMenuCommand(ENTER_NAME, ENTER_COMM, ENTER_STRING, enter_val_f);
	CMenuCommand* change_tab_size = new CMenuCommand(RESIZE_NAME, RESIZE_COMM, RESIZE_STRING, change_tab_size_f);
	CMenuCommand* clear_vector = new CMenuCommand(CLEAR_NAME, CLEAR_COMM, CLEAR_STRING, clear_vector_f);

	(*menu1).vAddItem(create_obj);
	(*menu1).vAddItem(change_obj_name);
	(*menu1).vAddItem(delete_obj);
	(*menu1).vAddItem(clone_obj);
	(*menu1).vAddItem(print_obj);
	(*menu1).vAddItem(enter_val);
	(*menu1).vAddItem(change_tab_size);
	(*menu1).vAddItem(clear_vector);

	(*menu2).vAddItem(przegladarka);
	(*menu2).vAddItem(def);
	/*
	CMenu* main = new CMenu("A", MENU_GET);
	main->vSetRoot();
	CMenu* menu1 = new CMenu("B", MENU1_GET);
	CMenu* menu2 = new CMenu("C", MENU2_GET);
	(*main).vAddItem(menu1);
	(*main).vAddItem(menu2);

	CCommAla* alaComm = new CCommAla();
	CMenuCommand* ala1 = new CMenuCommand("D", ALA_TEXT, ALA_HELP, alaComm);
	menu1->vAddItem(ala1);
	CMenuCommand* ala2 = new CMenuCommand("E", ALA_TEXT, ALA_HELP, alaComm);
	menu2->vAddItem(ala2);
	CMenuCommand* ala3 = new CMenuCommand("F", ALA_TEXT, ALA_HELP, alaComm);
	menu2->vAddItem(ala3);

	(*main).vShowLevels(0);
	cout << endl; */

	(*main).iRun();
	delete main;

	return(0);
}