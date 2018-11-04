#pragma once
#define DEFAULT_STRING "Default command "
#define EMPTY_QUOTE "No command"

class CCommand
{
public:
	CCommand();
	~CCommand();

	virtual void RunCommand();
	virtual void vHelpCommand();
};

