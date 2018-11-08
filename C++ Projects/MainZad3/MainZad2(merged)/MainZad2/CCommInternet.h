#pragma once
#include "pch.h"
#include <iostream>
#include "CCommand.h"
#define OPEN_BROWSER "Otwieram przegladarke"
#define GOOGLE_ADRESS "https://google.com/"
#define WHAT_BROWSER "chrome.exe"
#define ACTION "open"
#define CONTINUE_PROMPT "Nacisnij dowolny przycisk zeby program kontynuowal dzialanie"
#define INTERNET_HELP "Otwiera przegladarke internetowa chrome"
#define INTERNET_OPEN "Uruchom przegladarke"
#define INTERNET_TEXT "internet"

using namespace std;

class CCommInternet : public CCommand {
public:
	void RunCommand();
	void vHelpCommand()	{ cout << INTERNET_HELP << endl; }
};