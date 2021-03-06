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
#include <iostream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
CMenu* main = new CMenu("MainMenu", "main");
CMenu* menu1 = new CMenu("Podmenu1", "menu1");
CMenu* menu2 = new CMenu("Podmenu2", "menu2");

CCommAla* alaComm = new CCommAla();
CMenuCommand* ala = new CMenuCommand("Ala ma kota", "ala", alaComm);

(*main).vAddItem(menu1);
(*main).vAddItem(menu2);
(*main).vAddItem(ala);

CCommInternet* internetComm = new CCommInternet();
CMenuCommand* przegladarka = new CMenuCommand("Uruchom przegladarke", "internet", internetComm);
CDefaultComm* defaultComm = new CDefaultComm();
CMenuCommand* def = new CMenuCommand("Default command", "def", defaultComm);
CCommFun* create_obj_f = new CCommFun(vCreateInMenu, &v_ctable_objects);
CCommFun* change_obj_name_f = new CCommFun(vChangeObjectName, &v_ctable_objects);
CCommFun* delete_obj_f = new CCommFun(vDeleteObject, &v_ctable_objects);
CCommFun* clone_obj_f = new CCommFun(vCloneObject, &v_ctable_objects);
CCommFun* print_obj_f = new CCommFun(vPrintObject, &v_ctable_objects);
CCommFun* enter_val_f = new CCommFun(vEnterValue, &v_ctable_objects);
CCommFun* change_tab_size_f = new CCommFun(vChangeTableSize, &v_ctable_objects);
CCommFun* clear_vector_f = new CCommFun(vClearVector, &v_ctable_objects);

CMenuCommand* create_obj = new CMenuCommand("Create objects", "create", create_obj_f);
CMenuCommand* change_obj_name = new CMenuCommand("Change object's name", "change", change_obj_name_f);
CMenuCommand* delete_obj = new CMenuCommand("Delete object", "delete", delete_obj_f);
CMenuCommand* clone_obj = new CMenuCommand("Clone object", "clone", clone_obj_f);
CMenuCommand* print_obj = new CMenuCommand("Print object", "print", print_obj_f);
CMenuCommand* enter_val = new CMenuCommand("Enter value", "enter", enter_val_f);
CMenuCommand* change_tab_size = new CMenuCommand("Change table size", "resize", change_tab_size_f);
CMenuCommand* clear_vector = new CMenuCommand("Clear vector", "clear", clear_vector_f);

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

(*main).iRun();
clear_vector->iRun();
delete main;

return(0);
}