#pragma once
#include "UserRepository.h"

class DummyRepository :
	public UserRepository
{
public:
	//DummyRepository();
	void SaveList(TElem elem) override;
	void StoreToFile();
	~DummyRepository();
};

