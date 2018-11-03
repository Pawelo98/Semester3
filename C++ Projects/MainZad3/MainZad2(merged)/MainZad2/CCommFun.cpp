#include "pch.h"
#include "CCommFun.h"

CCommFun::CCommFun(void(*gFunction)(vector<CTable*>&), vector<CTable*>* tab) : f(gFunction), table(tab)
{
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
