#include "DummyRepository.h"
#include "Exceptions.h"


void DummyRepository::StoreToFile()
{
	return;
}

void DummyRepository::SaveList(TElem element)
{
	if (this->User_list.size() == 0)
	{
		User_list.push_back(element);
	}
	else if (element.getTitle() == "alakazam")
	{
		throw RepositoryExceptions("No way to add");
	}
	else if (element.getTitle() == "charmander")
	{
		throw RepositoryExceptions("Weak pokemon");
	}
	else
	{
		User_list.push_back(element);
	}
}
DummyRepository::~DummyRepository()
{
}
