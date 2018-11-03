#pragma once
#include "pch.h"
#include "CTable.h"
#include <vector>
#include <iostream>
#include <string>

vector <CTable*> v_ctable_objects;
CTable *c_temp_table, *c_table;
int i_given_index, i_given_value, i_given_index_cell, i_object_quantity;
string s_given_name;
CTable cTable;

void vCreateObjects(vector <CTable*> &v_ctable_objects)
{
	for (int i = 0; i < i_object_quantity; i++)
	{
		CTable *cTable = new CTable;
		v_ctable_objects.push_back(cTable);
	}//for (int i = 0; i < i_object_quantity; i++)
}//void vCreateObjects()

void vCreateInMenu(vector <CTable*> &v_ctable_objects)
{
	cout << NUMBER_TO_CREATE;
	cin >> i_object_quantity;
	if (!cin)
	{
		cin.clear(); // czyœcimy flagi b³êdu strumienia
		cin.sync(); // czyœcimy bufor strumienia
	}//if (!cin)
	else // wpisano liczbê
	{
		vCreateObjects(v_ctable_objects);
	}//if (cin)
}// void vCreateInMenu(vector <CTable*> &v_ctable_objects)

bool bCheckVectorIndex(vector <CTable*> &v_ctable_objects, int iIndex)
{
	if ((iIndex < v_ctable_objects.size()) && (0 <= iIndex)) return true;
	else return false;
}//bool bCheckVectorIndex(int iIndex)

void vChangeObjectName(vector <CTable*> &v_ctable_objects)
{
	cout << INDEX_NAME << endl;
	cin >> i_given_index;
	if (!cin)
	{
		cin.clear(); // czyœcimy flagi b³êdu strumienia
		cin.sync(); // czyœcimy bufor strumienia
	}//if (!cin)
	else // wpisano liczbê
	{
		if (bCheckVectorIndex(v_ctable_objects, i_given_index))
		{
			cout << OBJECT_NAME << endl;
			cin >> s_given_name;
			if (!cin)
			{
				cin.clear(); // czyœcimy flagi b³êdu strumienia
				cin.sync(); // czyœcimy bufor strumienia
			}//if (!cin)
			else // wpisano liczbê
			{
				c_temp_table = v_ctable_objects.at(i_given_index);
				(*c_temp_table).vSetName(s_given_name);
			}//if(cin)
		}//if (bCheckVectorIndex(i_given_index))
		else cout << WRONG_INDEX << endl;
	}//if(cin)
}// void vChangeObjectName(vector <CTable*> &v_ctable_objects)

void vDeleteObject(vector <CTable*> &v_ctable_objects)
{
	cout << INDEX_REMOVE << endl;
	cin >> i_given_index;
	if (!cin)
	{
		cin.clear(); // czyœcimy flagi b³êdu strumienia
		cin.sync(); // czyœcimy bufor strumienia
	}//if (!cin)
	else // wpisano liczbê
	{
		if (bCheckVectorIndex(v_ctable_objects, i_given_index))
		{
			delete v_ctable_objects.at(i_given_index);
			v_ctable_objects.erase(v_ctable_objects.begin() + i_given_index);
		}//if (bCheckVectorIndex(i_given_index))
		else cout << WRONG_INDEX;
	}//if(cin)
}// void vDeleteObject(vector <CTable*> &v_ctable_objects)

void vCloneObject(vector <CTable*> &v_ctable_objects)
{
	cout << INDEX_COPY << endl;
	cin >> i_given_index;
	if (!cin)
	{
		cin.clear(); // czyœcimy flagi b³êdu strumienia
		cin.sync(); // czyœcimy bufor strumienia
	}//if (!cin)
	else // wpisano liczbê
	{
		if (bCheckVectorIndex(v_ctable_objects, i_given_index))
		{
			c_temp_table = v_ctable_objects.at(i_given_index);
			c_table = new CTable(*c_temp_table);
			v_ctable_objects.push_back(c_table);
		}//if (bCheckVectorIndex(i_given_index))
		else cout << WRONG_INDEX << endl;
	}//if(cin)
}// void vCloneObject(vector <CTable*> &v_ctable_objects)

void vReadTableSize(vector <CTable*> v_ctable_objects, int iGivenIndex)
{
	c_temp_table = v_ctable_objects.at(iGivenIndex);
	cout << (*c_temp_table).sObjectToString() << endl;
}//void vReadTableSize(int iGivenIndex)

void vPrintObject(vector <CTable*> &v_ctable_objects)
{
	cout << INDEX_SHOW << endl;
	cin >> i_given_index;
	if (!cin)
	{
		cin.clear(); // czyœcimy flagi b³êdu strumienia
		cin.sync(); // czyœcimy bufor strumienia
	}//if (!cin)
	else // wpisano liczbê
	{
		if (bCheckVectorIndex(v_ctable_objects, i_given_index))
		{
			vReadTableSize(v_ctable_objects, i_given_index);
		}//if (bCheckVectorIndex(i_given_index))
		else cout << WRONG_INDEX << endl;
	}//if(cin)
}// void vPrintObject(vector <CTable*> &v_ctable_objects)

void vEnterValue(vector <CTable*> &v_ctable_objects)
{
	cout << INDEX_CHANGE << endl;
	cin >> i_given_index;
	if (!cin)
	{
		cin.clear(); // czyœcimy flagi b³êdu strumienia
		cin.sync(); // czyœcimy bufor strumienia
	}//if (!cin)
	else // wpisano liczbê
	{
		if (bCheckVectorIndex(v_ctable_objects, i_given_index))
		{
			cout << INDEX_COMM << endl;
			cin >> i_given_index_cell;
			c_temp_table = v_ctable_objects.at(i_given_index);
			if ((*c_temp_table).bCheckIndex(i_given_index_cell))
			{
				cout << GET_VALUE << endl;
				cin >> i_given_value;
				(*c_temp_table).bChangeValue(i_given_index_cell, i_given_value);
			}//if ((*c_temp_table).bCheckIndex(i_given_index_cell))
		}//if (bCheckVectorIndex(i_given_index))
		else cout << WRONG_INDEX << endl;
	}//if(cin)
}// void vEnterValue(vector <CTable*> &v_ctable_objects)

void vChangeTableSize(vector <CTable*> &v_ctable_objects)
{
	cout << INDEX_LENGTH << endl;
	cin >> i_given_index;
	if (!cin)
	{
		cin.clear(); // czyœcimy flagi b³êdu strumienia
		cin.sync(); // czyœcimy bufor strumienia
	}//if (!cin)
	else // wpisano liczbê
	{
		if (bCheckVectorIndex(v_ctable_objects, i_given_index) == true)
		{
			cout << GET_LENGTH;
			c_temp_table = v_ctable_objects.at(i_given_index);
			cout << (*c_temp_table).iGetSize() << endl;
		}//if (bCheckVectorIndex(i_given_index)==true)
		else cout << WRONG_INDEX;
	}//if(cin)
}// void vChangeTableSize(vector <CTable*> &v_ctable_objects)

void vClearVector(vector<CTable*> &v_ctable_objects)
{
	for (int i = 0; i < v_ctable_objects.size(); i++)
	{
		delete v_ctable_objects.at(i);
	}//for (int i = 0; i < v_ctable_objects.size(); i++)
	v_ctable_objects.clear();
}//void vClearVector(vector<CTable*> &v_ctable_objects)

bool bCheckTableIndex(int iIndex, CTable cTable)
{
	if ((iIndex < cTable.iGetSize()) && (0 <= iIndex)) return true;
	else return false;
}//bool bCheckTableIndex(int iIndex, CTable cTable)

void v_test(CTable cArg)
{
	cArg.vResize(1);
} //v_test(CTable cArg) 
