#include "Validators.h"


Recordings Validators::CreateCommandandValidate(string input_string)
{
	string title, location, creation_date, footage_preview, times;
	int times_accesed;
	{
		std::size_t difference;
		std::size_t found = input_string.find_first_of(" "), old_found;
		old_found = found;
		found = input_string.find_first_of(",", found + 1);
		if (found == std::string::npos)
			throw ValidateExceptions("Invalid input");
		difference = found - old_found - 1;
		title = input_string.substr(old_found + 1, difference);
		old_found = found;
		found = input_string.find_first_of(",", found + 1);
		if (found == std::string::npos || title.size() == 0)
			throw ValidateExceptions("Invalid input");
		difference = found - old_found - 1;
		location = input_string.substr(old_found + 1, difference);
		old_found = found;
		found = input_string.find_first_of(",", found + 1);
		if (found == std::string::npos || location.size() == 0)
			throw ValidateExceptions("Invalid input");
		difference = found - old_found - 1;
		creation_date = input_string.substr(old_found + 1, difference);
		old_found = found;
		found = input_string.find_first_of(",", found + 1);
		if (found == std::string::npos || creation_date.size() == 0)
			throw ValidateExceptions("Invalid input");
		difference = found - old_found - 1;
		times = input_string.substr(old_found + 1, difference);
		times_accesed = stoi(times);
		old_found = found;
		found = input_string.find_first_of(",", found + 1);
		if (found != std::string::npos)
			throw ValidateExceptions("Too many parameters");
		difference = found - old_found - 1;
		footage_preview = input_string.substr(old_found + 1, difference);
		if (footage_preview.size() == 0)
			throw ValidateExceptions("Invalid input");
		Recordings command = Recordings(title, location, creation_date, times_accesed, footage_preview);
		return command;
	}

}

bool Validators::validate_input(Recordings command)
{
	if (strcmp(typeid(command.getTitle()).name(), "int") == 0 || strcmp(typeid(command.getLocation()).name(), "int") == 0 || strcmp(typeid(command.getCreationDate()).name(), "int") == 0 || strcmp(typeid(command.getFootagePreview()).name(), "int") == 0 || strcmp(typeid(command.getTimesAccessed()).name(), "int") != 0)
		return false;
	return true;
}


const string Validators::ValidateString(string validate_string)
{
	found = validate_string.find_first_of(" ");
	old_found = found;
	found = validate_string.find_first_of(",", found + 1);
	difference = found - old_found - 1;
	return validate_string.substr(old_found + 1, difference);
}

const string Validators::ValidateStringNext(string validate_string)
{
	old_found = found;
	found = validate_string.find_first_of(",", found + 1);
	difference = found - old_found - 1;
	return validate_string.substr(old_found + 1, difference);
}

bool Validators::ValidateEnd()
{
	if (found != std::string::npos)
		return false;
	return true;
}

bool Validators::ValidateEndNothing(string validate_string)
{
	std::size_t found = validate_string.find_first_of(" ,");
	if (found != std::string::npos)
		return false;
	return true;
}


bool FakeValidator::validate_input(Recordings command)
{
	if (command.getTitle()=="charizard" || strcmp(typeid(command.getLocation()).name(), "int") == 0 || strcmp(typeid(command.getCreationDate()).name(), "int") == 0 || strcmp(typeid(command.getFootagePreview()).name(), "int") == 0 || strcmp(typeid(command.getTimesAccessed()).name(), "int") != 0)
		throw ValidateExceptions("LOL");
	return true;
}