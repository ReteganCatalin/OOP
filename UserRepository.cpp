#include "UserRepository.h"



UserRepository::UserRepository()
{
	this->file_name = "";
}

void UserRepository::KeepFile(string file)
{
	this->file_name = file;
}
UserRepository::~UserRepository()
{
}

void UserRepository::SaveList(TElem element)
{
	for (auto user_list_iterator = User_list.begin(); user_list_iterator != User_list.end(); ++user_list_iterator)
	{
		if (*user_list_iterator == element)
			throw RepositoryExceptions("Already saved");
	}
	this->User_list.push_back(element);
	return;
}

void UserRepository::ListMyList()
{
	this->StoreToFile();
	ShellExecute(nullptr, "open", file_name.c_str() , nullptr, nullptr, SW_SHOWNORMAL);
}

int UserRepository::MyListSize()
{
	return this->User_list.size();
}
