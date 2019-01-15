#pragma once
#include "CMenuItem.h"
#include "CCommand.h"
#include <string>
#include <vector>
#define DELETE_COMM "deleted command"
#define EMPTY_STRING "Empty command"
#define EMPTY_QUOTE "No command"
#define CREATE_NAME "Create objects"
#define CREATE_COMM "create"
#define CHANGE_NAME "Change object's name"
#define CHANGE_COMM "change"
#define DELETE_NAME "Delete object"
#define DELETE_COMM "delete"
#define CLONE_NAME "Clone object"
#define CLONE_COMM "clone"
#define PRINT_NAME "Print object"
#define PRINT_COMM "print"
#define ENTER_NAME "Enter value"
#define ENTER_COMM "enter"
#define RESIZE_NAME "Change table size"
#define RESIZE_COMM "resize"
#define CLEAR_NAME "Clear vector"
#define CLEAR_COMM "clear"
#define EMPTY_STRING ""
#define OPEN_BRACKET "['"
#define COMMA "','"
#define CLOSE_BRACKET "']"

using namespace std;

class CMenuCommand : public CMenuItem
{
private:
	string s_help;
	CCommand* c_command;
public:
	CMenuCommand(string sName, string sCommand, string sHelp, CCommand* cc);
	~CMenuCommand();

	void vSearch(string sCommand, string sPath);
	int iRun();
	int iHelp();
	string parseToString();
};