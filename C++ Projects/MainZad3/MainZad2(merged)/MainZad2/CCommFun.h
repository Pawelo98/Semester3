#pragma once
#include "CCommand.h"
#include <vector>
#include "CTable.h"

using namespace std;

class CCommFun : public CCommand
{
private:
	void(*f)(vector<CTable*>&);
	vector<CTable*>* table;

public:
	CCommFun(void(*g)(vector<CTable*>&), vector<CTable*>* tab);
	CCommFun(const CCommFun &A);
	~CCommFun();

	virtual void RunCommand();
};

