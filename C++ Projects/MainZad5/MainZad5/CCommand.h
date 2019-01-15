#pragma once
#define DEFAULT_STRING "Default command"
#define EMPTY_QUOTE "No command"
#include <string>

class CCommand
{
public:
	CCommand();
	~CCommand();

	virtual void RunCommand();
	virtual void vHelpCommand() {};
};

