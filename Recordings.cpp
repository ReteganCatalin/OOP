#include "Recordings.h"
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

Recordings::Recordings(string title, string location, string creation_date, int times_accesed, string footage_preview)
{
	this->title = title;
	this->location = location;
	this->creation_date = creation_date;
	this->footage_preview = footage_preview;
	this->times_accesed = times_accesed;
}

bool Recordings::operator==(const Recordings& other)
{
	return this->title==other.title;
}

Recordings& Recordings::operator=(const Recordings& other)
{
	if (this == &other) return *this;
	this->setCreationDate(other.creation_date);
	this->setFootagePreview(other.footage_preview);
	this->setLocation(other.location);
	this->setTitle(other.title);
	this->times_accesed = other.times_accesed;
	return *this;
}

string Recordings::getTitle() const
{
	return this->title;
}

string Recordings::getLocation() const
{
	return this->location;
}

int Recordings::getTimesAccessed() const
{
	return this->times_accesed;
}
string Recordings::getCreationDate() const
{
	return this->creation_date;
}

string Recordings::getFootagePreview() const
{
	return this->footage_preview;
}

void Recordings::setTitle(string title)
{
	this->title = title;
}

void Recordings::setLocation(string location)
{
	this->location = location;
}

void Recordings::setCreationDate(string creation_date)
{
	this->creation_date = creation_date;
}

void Recordings::setTimesAccessed(int times_accessed)
{
	this->times_accesed = times_accessed;
}

void Recordings::setFootagePreview(string footage_preview)
{
	this->footage_preview = footage_preview;
}
vector<string> tokenize(string input)
{
	vector <string> tokenized_result;
	stringstream split_input(input);
	string token;
	while (getline(split_input, token, ','))
		tokenized_result.push_back(token);

	return tokenized_result;
}
std::istream & operator>>(istream& input,Recordings& recording)
{
	string line;
	getline(input, line);

	vector<string> input_tokens = tokenize(line);
	if (input_tokens.size() != 5)
	{
		recording.title = "fail078";
		return input;
	}
		
	if (input_tokens[0].size() == 0 || input_tokens[1].size() == 0 || input_tokens[2].size() == 0 || input_tokens[4].size() == 0)
	{
		recording.title = "fail078";
		return input;
	}
	recording.title = input_tokens[0];
	recording.location = input_tokens[1];
	recording.creation_date = input_tokens[2];
	recording.times_accesed = stoi(input_tokens[3]);
	recording.footage_preview = input_tokens[4];
	return input;
}

std::ostream & operator<<(ostream& output,const Recordings& recording)
{
	output << recording.title << "," << recording.location << "," << recording.creation_date << "," << recording.times_accesed << "," << recording.footage_preview << "\n";
	return output;
}