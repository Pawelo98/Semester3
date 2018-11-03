#pragma once
#include "CTable.h"
#include <iostream>
#include <vector>
#include <string>

extern vector <CTable*> v_ctable_objects;
extern CTable *c_temp_table, *c_table;
extern int i_given_index, i_given_value, i_given_index_cell, i_object_quantity;;
extern string s_given_name;
extern CTable cTable;

void vCreateInMenu(vector <CTable*> &v_ctable_objects);
void vCreateObjects(vector <CTable*> &v_ctable_objects);
void vChangeObjectName(vector <CTable*> &v_ctable_objects);
void vDeleteObject(vector<CTable*> &v_ctable_objects);
void vCloneObject(vector<CTable*> &v_ctable_objects);
void vPrintObject(vector<CTable*> &v_ctable_objects);
void vEnterValue(vector<CTable*> &v_ctable_objects);
void vChangeTableSize(vector<CTable*> &v_ctable_objects);
void vClearVector(vector<CTable*> &v_ctable_objects);
bool bCheckVectorIndex(vector<CTable*> &v_ctable_objects, int iIndex);
bool bCheckTableIndex(int iIndex, CTable cTable);
void vReadTableSize(vector <CTable*> v_ctable_objects, int iGivenIndex);
void v_test(CTable cArg);