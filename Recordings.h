#pragma once
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
class Recordings 
{
private:
	string title;
	string location;
	string creation_date;
	string footage_preview;
	int times_accesed;
public:
	Recordings() {};
	Recordings(string title, string location, string creation_date, int times_accessed, string footage_preview);
	string getTitle() const;
	string getLocation() const;
	string getCreationDate() const;
	string getFootagePreview() const;
	int getTimesAccessed() const;
	void setTitle(string title);
	void setLocation(string location);
	void setCreationDate(string creation_date);
	void setTimesAccessed(int times_accessed);
	void setFootagePreview(string footage_preview);
	bool operator==(const Recordings& other);
	Recordings& operator=(const Recordings& other);
	friend std::istream& operator>>(istream& input,Recordings& recording);
	friend std::ostream& operator<<(ostream& output,const Recordings& recording);

};