#pragma once
#include "Recordings.h"
#include "Exceptions.h"
class Validators
{
	std::size_t difference;
	std::size_t found , old_found;
public:
	Recordings CreateCommandandValidate(string command_string);
	virtual bool validate_input(Recordings command);
	const string ValidateString(string validate_string);
	const string ValidateStringNext(string validate_string);
	bool ValidateEnd();
	bool ValidateEndNothing(string validate_string);
};


class FakeValidator :public Validators
{
public:
	bool validate_input(Recordings element) override;
	
};