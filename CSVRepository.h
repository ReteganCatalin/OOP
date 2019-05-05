#pragma once
#include "Recordings.h"
#include <vector>
#include "UserRepository.h"

class CSVRepository :
	public UserRepository
{
public:
	//CSVRepository();
	void StoreToFile();
	~CSVRepository();
};

