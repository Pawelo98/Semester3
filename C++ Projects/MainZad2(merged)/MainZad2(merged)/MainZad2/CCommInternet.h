#pragma once
#include "pch.h"
#include <iostream>
#include "CCommand.h"
#define OPEN_BROWSER "Otwieram przegladarke"
#define GOOGLE_ADRESS "https://google.com/"
#define WHAT_BROWSER "chrome.exe"
#define ACTION "open"
#define CONTINUE_PROMPT "Nacisnij dowolny przycisk zeby program kontynuowal dzialanie"

using namespace std;

class CCommInternet : public CCommand {
public:
	void RunCommand();
};