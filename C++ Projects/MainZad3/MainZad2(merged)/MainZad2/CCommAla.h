#pragma once
#include "pch.h"
#include <iostream>
#include "CCommand.h"
#define ALA_COMM "Ala ma kota"
#define ALA_HELP "Wypisuje na ekran stringa: 'Ala ma kota'"

using namespace std;

class CCommAla : public CCommand {
public:
	void vHelpCommand()
	{
		cout << ALA_HELP << endl;
	}
	void RunCommand() 
	{
		cout << ALA_COMM << endl;
	}// void RunCommand()
};