#pragma once
#include "pch.h"
#include <iostream>
#include "CCommand.h"
#define ALA_COMM "Ala ma kota"

using namespace std;

class CCommAla : public CCommand {
public:
	void RunCommand() 
	{
		cout << ALA_COMM << endl;
	}// void RunCommand()
};