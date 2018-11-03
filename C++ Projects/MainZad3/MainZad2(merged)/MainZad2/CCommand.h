#pragma once
#define DEFAULT_STRING "Default command "
class CCommand
{
public:
	CCommand();
	~CCommand();

	virtual void RunCommand();
};

