#pragma once
#include "Service.h"
#include "Validators.h"

class UI
{
private:
	ServiceModeA service_modeA;
	Validators validate;
public:
	UI() {};
	void StartMenu();
	
};
