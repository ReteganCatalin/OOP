#pragma once
#include "UserRepository.h"
class HTMLRepository :
	public UserRepository
{
public:
	//HTMLRepository();
	void StoreToFile();
	~HTMLRepository();
};

