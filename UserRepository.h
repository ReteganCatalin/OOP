#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Recordings.h"
#include "Exceptions.h"
#include <Windows.h>

typedef Recordings TElem;
class UserRepository
{
protected:
	std::string file_name = "";
	std::vector<TElem> User_list;
public:
	
	UserRepository();
	void KeepFile(string file);
	virtual void SaveList(TElem element);
	void ListMyList();
	int MyListSize();
	virtual void StoreToFile()=0;
	virtual ~UserRepository()=0;
};

