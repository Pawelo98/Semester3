#pragma once
#include <string>
#include <vector>
#include "CCommand.h"
#include "CTable.h"
#define CREATE_STRING "Pozwala na utworzenie obiektow klasy CTable"
#define CHANGE_STRING "Pozwala na zmiane nazwy obiektu klasy CTable"
#define DELETE_STRING "Pozwala na usuniecie obiektu klasy CTable"
#define CLONE_STRING "Pozwala na klonowanie obiektu klasy CTable"
#define PRINT_STRING "Pozwala na wypisanie obiektow klasy CTable"
#define ENTER_STRING "Pozwala na wprowadzenie dowolnej wartosci w dana komorke tablicy obiektu klasy CTable"
#define RESIZE_STRING "Pozwala na zmiane rozmiaru tablicy obiektu klasy CTable"
#define CLEAR_STRING "Pozwala na usuniecie wszystkich obiektow klasy CTable"

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

