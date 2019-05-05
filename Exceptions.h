#pragma once
#include <exception>
#include <string>
class ValidateExceptions : public std::exception
{
private:
	std::string _message;
public:
	ValidateExceptions(const std::string& message) : _message(message) {}
	
	const char* what() const noexcept override
	{
		return _message.c_str();
	}
};

class RepositoryExceptions : public std::exception
{
private:
	std::string _message;
public:
	RepositoryExceptions(const std::string& message) : _message(message) {}

	const char* what() const noexcept override
	{
		return _message.c_str();
	}
};

