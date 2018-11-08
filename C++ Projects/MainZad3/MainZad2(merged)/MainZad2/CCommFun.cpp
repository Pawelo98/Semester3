#include "pch.h"
#include <string>
#include <iostream>
#include "CCommFun.h"

CCommFun::CCommFun(void(*gFunction)(vector<CTable*>&), vector<CTable*>* tab, string sHelpConstructor) : f(gFunction), table(tab)
{
	sHelp = sHelpConstructor;
}// CCommFun::CCommFun(void(*g)(vector<CTable*>&), vector<CTable*>* tab) : f(g), table(tab)

CCommFun::CCommFun(const CCommFun & AFunction)
{
	f = AFunction.f;
	table = AFunction.table;
} //CCommFun::CCommFun(const CCommFun & AFunction)

CCommFun::~CCommFun()
{
}// CCommFun::~CCommFun()

void CCommFun::RunCommand()
{
	f(*table);
}// void CCommFun::RunCommand()

void CCommFun::vHelpCommand()
{
	cout << sHelp << endl;
}// void CCommFun::vHelpCommand()
