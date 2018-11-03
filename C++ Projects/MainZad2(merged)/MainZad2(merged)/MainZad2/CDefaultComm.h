#pragma once
#include "pch.h"
#include <iostream>
#include "CCommand.h"

using namespace std;

class CDefaultComm : public CCommand {
public:
	void vRunCommand();
};