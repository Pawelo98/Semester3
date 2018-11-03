#include "pch.h"
#include "CTable.h"
#include <iostream>
#include <string>

CTable::CTable()
{
	s_name = CASUAL_TABLE_NAME;
	pi_table = new int[CASUAL_TABLE_SIZE];
	i_size = CASUAL_TABLE_SIZE;
	for (int i = 0; i < i_size; i++)
	{
		pi_table[i] = 0;
	}//for (int i = 0; i < iSize; i++)
	cout << OPEN_BEZP << s_name << CLOSE_CONSTRUCTOR << endl;
};//CTable::CTable()
CTable::CTable(string sTableName, int iTableSize)
{
	s_name = sTableName;
	pi_table = new int[iTableSize];
	i_size = iTableSize;
	for (int i = 0; i < i_size; i++)
	{
		pi_table[i] = 0;
	}//for (int i = 0; i < iSize; i++)
	cout << OPEN_PAR << s_name << CLOSE_CONSTRUCTOR << endl;
};//CTable::CTable(string sTableName, int iTableSize)
CTable::CTable(CTable &pcOther)
{
	s_name = pcOther.s_name + COPY_ADDITION;
	i_size = pcOther.i_size;
	pi_table = new int[i_size];
	for (int j = 0; j < i_size; j++)
	{
		pi_table[j] = pcOther.pi_table[j];
	}// for (int j = 0; j < i_size; j++)
	cout << OPEN_COPY << pcOther.s_name << CLOSE_CONSTRUCTOR << endl;
};//CTable::CTable(const CTable &pcOther)
CTable::~CTable()
{
	delete [] pi_table;
	cout << DESTR_REMOVE << s_name << CLOSE_CONSTRUCTOR << endl;
};//~CTable()
string CTable::sGetName() { return s_name; }
void CTable::vSetName(string sNewName) { s_name = sNewName; }
int CTable::iGetSize() { return i_size; }
int* CTable::piGetPitable() { return pi_table; }
void CTable::vSetSize(int iNewSize){ i_size = iNewSize; }
bool CTable::bCheckIndex(int iIndex)
{
	if (iIndex < iGetSize() && iIndex >= 0) return true;
	else return false;
}//bool CTable::bCheckIndex(int iIndex)
string CTable::sGetValues()
{
	string s_values = EMPTY_STRING;
	for (int j = 0; j <= i_size - 1; j++)
	{
		s_values += to_string(pi_table[j]);
		if (j < i_size - 1)
		{
			s_values += PRZECINEK;
		}//if (j < iSize - 1)
	}//for (int j = 0; j <= iSize - 1; j++)
	return s_values;
};//sGetValues()
void CTable::vResize(int newSize) {
	if (newSize != i_size) {
		int* newArr;
		newArr = new int[newSize];
		int lastIndex = (newSize > i_size) ? i_size : newSize;
		for (int i = 0; i < lastIndex; i++) 
		{
			*(newArr + i) = *(pi_table + i);
		}// for (int i = 0; i < lastIndex; i++)

		if (lastIndex < newSize)
		{
			for (int i = lastIndex; i < newSize; i++) 
			{
				*(newArr + i) = -1;
			}// for (int i = lastIndex; i < newSize; i++)
		}// if (lastIndex < newSize)
		delete[] pi_table;
		pi_table = newArr;
		i_size = newSize;
	}// if (newSize != i_size)
}// void CTable::vResize(int newSize)
void CTable::vTransferTable(CTable &pcFrom, CTable &pcTo)
{
	pcTo.i_size = pcFrom.i_size;
	pcTo.pi_table = new int(pcFrom.iGetSize());
	pcTo.pi_table = pcFrom.pi_table;
}//void CTable::vTransferTable(const CTable &pcFrom, CTable &pcTo)
bool CTable::bChangeValue(int iTablePosition, int iNewValue)
{
	if (bCheckIndex(iTablePosition))
	{
		pi_table[iTablePosition] = iNewValue;
		return true;
	}// if (bCheckIndex(iTablePosition))
	else WRONG_INDEX;
	return false;
};//void CTable::vChangeValue(int iTablePosition, int iNewValue)
bool CTable::bReadValue(int iTablePosition)
{
	if (bCheckIndex(iTablePosition))
	{
		cout << pi_table[iTablePosition] << endl;
		return true;
	}// if (bCheckIndex(iTablePosition))
	else WRONG_INDEX;
	return false;
};//void CTable::vReadValue(int iTablePosition)
void CTable::vSetTableName(string sNewName)
{
	vSetName(sNewName);
};//void CTable::vSetTableName(string sNewName)
string CTable::sObjectToString()
{
	return OPEN_TO_STRING + s_name + LENGTH_TO_STRING + to_string(i_size) + VALUES_TO_STRING + sGetValues() + CLOSE_CONSTRUCTOR;
};//string CTable::sObjectToString()

