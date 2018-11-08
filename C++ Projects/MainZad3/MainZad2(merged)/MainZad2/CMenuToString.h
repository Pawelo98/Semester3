#pragma once
#include "CMenu.h"
#include "CMenuCommand.h"
#include <string>
#include <iostream>
const string TEST_TEXT = "('menu glowne','main';('Podmenu1','menu1';['Uruchom przegladarke','internet','otwiera przegladarke'],('Podmenu1','menu1';)),('Podmenu2','menu2';['Test','test','pomoc dla test'],['Default command','defcom','pomoc dla test'],['Uruchom przegladarke','internet','otwiera przegladarke']),['Napisz, ze Ala ma kota','ala','napis o Ali'])";
const string ERROR_STRING = "ERROR AT POSITION";
const char BBRACKET_OPEN = '(';
const char BSLASH = '\'';
const char BBRACKET_OTHER = '[';
const char BBRACKET_CLOSE = ')';
const char BBRACKET_OTHER2 = ']';
const char BCOMMA = ',';
const char BSREDNIK = ';';
#define SPACE " "
using namespace std;

class CMenuToString
{
public:
	CMenuToString();
	string parseToString(CMenu* menu);
	CMenu* parseFromString(string text);
	~CMenuToString();
private:
	CMenuItem* chooseMenu(string text, int &current);
	CMenuCommand* createCommand(string text, int &current);
	CMenu* createMenu(string text, int &current);
	int findNext(string text, int start);
	int checkCharacter(string text, char character, int &current);
};