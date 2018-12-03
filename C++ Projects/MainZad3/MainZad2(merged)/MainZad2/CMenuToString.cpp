#include "pch.h"
#include "CMenuToString.h"
#include "CDefaultComm.h"
using namespace std;

CMenuToString::CMenuToString()
{
}

CMenuToString::~CMenuToString()
{
}

string CMenuToString::parseToString(CMenu* menu)
{
	return string();
}// string CMenuToString::parseToString(CMenu * menu)

int CMenuToString::checkCharacter(string sText, char cCharacter, int & iCurrent)
{
	if (sText[iCurrent] != cCharacter)
	{
		cout << ERROR_STRING << SPACE << iCurrent << endl << EXPECTED << cCharacter << FOUND << sText[iCurrent] << endl;
		exit(0);
	}// if (sText[iCurrent] != cCharacter)
	iCurrent++;
	return iCurrent;
}// int CMenuToString::checkCharacter(string sText, char cCharacter, int & iCurrent)

int CMenuToString::findNext(string sText, int iStart)
{
	for (int i = iStart + 1; i < sText.size(); i++)
	{
		if (sText[i] == BSLASH)
			return i;
	}// for (int i = start + 1; i < text.size(); i++)
	return -1;
}// int CMenuToString::findNext(string sText, int iStart)

CMenuCommand * CMenuToString::createCommand(string sText, int &iCurrent)
{
	checkCharacter(sText, BSLASH, iCurrent);
	int iLast = findNext(sText, iCurrent);

	string sName = sText.substr(iCurrent, iLast - iCurrent);
	iCurrent += iLast - iCurrent;
	iCurrent++;
	checkCharacter(sText, BCOMMA, iCurrent);
	checkCharacter(sText, BSLASH, iCurrent);
	iLast = findNext(sText, iCurrent);

	string sCommand = sText.substr(iCurrent, iLast - iCurrent);
	iCurrent += iLast - iCurrent;
	iCurrent++;
	checkCharacter(sText, BCOMMA, iCurrent);
	checkCharacter(sText, BSLASH, iCurrent);
	iLast = findNext(sText, iCurrent);

	string sDesc = sText.substr(iCurrent, iLast - iCurrent);
	iCurrent += iLast - iCurrent;
	iCurrent++;

	CDefaultComm* cNewCommand= new CDefaultComm();
	CMenuCommand* menuCommand = new CMenuCommand(sName, sCommand, sDesc, cNewCommand);
	checkCharacter(sText, BBRACKET_OTHER2, iCurrent);
	return menuCommand;
}// CMenuCommand * CMenuToString::createCommand(string sText, int &iCurrent)

CMenu * CMenuToString::createMenu(string sText, int& iCurrent)
{
	checkCharacter(sText, BSLASH, iCurrent);
	int iLast = findNext(sText, iCurrent);

	string sName = sText.substr(iCurrent, iLast - iCurrent);
	iCurrent += iLast - iCurrent;
	iCurrent++;
	checkCharacter(sText, BCOMMA, iCurrent);
	checkCharacter(sText, BSLASH, iCurrent);
	iLast = findNext(sText, iCurrent);

	string sCommand = sText.substr(iCurrent, iLast - iCurrent);
	iCurrent += iLast - iCurrent;
	iCurrent++;

	CMenu* menu = new CMenu(sName, sCommand);
	checkCharacter(sText, BSREDNIK, iCurrent);

	while (sText[iCurrent] != BBRACKET_CLOSE)
	{
		menu->vAddItem(chooseMenu(sText, iCurrent));
		if (sText[iCurrent] != BBRACKET_CLOSE) iCurrent++;
	}
	iCurrent++;
	return menu;
}// CMenu * CMenuToString::createMenu(string sText, int& iCurrent)

CMenuItem * CMenuToString::chooseMenu(string sText, int &iCurrent)
{
	if (sText[iCurrent] == BBRACKET_OPEN)
	{
		iCurrent++;
		return createMenu(sText, iCurrent);
	}// if (sText[iCurrent] == '(')
	else if (sText[iCurrent] == BBRACKET_OTHER)
	{
		iCurrent++;
		return createCommand(sText, iCurrent);
	}// else if (sText[iCurrent] == '[')
	else
	{
		cout << iCurrent << FOUND << sText[iCurrent] << endl;
		exit(0);
		return NULL;
	}// else
}// CMenuItem * CMenuToString::chooseMenu(string sText, int &iCurrent)

CMenu* CMenuToString::parseFromString(string sText)
{
	int num = 0;
	checkCharacter(sText, BBRACKET_OPEN, num);
	return createMenu(sText, num);
}// CMenu* CMenuToString::parseFromString(string text)
