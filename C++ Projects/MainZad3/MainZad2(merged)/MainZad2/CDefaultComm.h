#pragma once
#include "pch.h"
#include <iostream>
#include "CCommand.h"
#define DEFAULT_STRING "Default command "
#define DEFAULT_GET "def"

using namespace std;

class CDefaultComm : public CCommand 
{
private:
	string sHelp;
public:
	void vRunCommand() { sHelp = DEFAULT_STRING; cout << DEFAULT_STRING << endl; };
	void vHelpCommand() { cout << DEFAULT_STRING << endl; }
};