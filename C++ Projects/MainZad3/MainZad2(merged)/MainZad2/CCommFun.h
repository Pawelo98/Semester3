#pragma once
#include <string>
#include <vector>
#include "CCommand.h"
#include "CTable.h"

using namespace std;

class CCommFun : public CCommand
{
private:
	void(*f)(vector<CTable*>&);
	vector<CTable*>* table;
	string sHelp;

public:
	CCommFun(void(*g)(vector<CTable*>&), vector<CTable*>* tab, string help);
	CCommFun(const CCommFun &A);
	~CCommFun();

	void vHelpCommand();
	virtual void RunCommand();
};

