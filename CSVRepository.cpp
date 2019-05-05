#include "CSVRepository.h"

void CSVRepository::StoreToFile()
{
	ofstream output_file(file_name);
	if (!output_file.is_open())
		return;
	for (auto const& recording : User_list)
	{
		output_file << recording;
	}

	output_file.close();
}


CSVRepository::~CSVRepository()
{

}


