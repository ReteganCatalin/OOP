#include "repository.h"
#include "Exceptions.h"
#include <cstring>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <fstream>

void RecordingsRepository::AddNewRecording(TElem new_recording) 
{
	for (std::vector<TElem>::iterator recordings_iterator = Recordings_repository.begin(); recordings_iterator != Recordings_repository.end(); ++recordings_iterator)
		if (*recordings_iterator == new_recording)
		{
			throw RepositoryExceptions("Already in the repository");
		}
	this->Recordings_repository.push_back(new_recording);
}

void RecordingsRepository::UpdateExistingRecording(TElem updated_recordings) 
{
	for(std::vector<TElem>::iterator recordings_iterator=Recordings_repository.begin();recordings_iterator!=Recordings_repository.end();++recordings_iterator)
		if (*recordings_iterator == updated_recordings)
		{
			*recordings_iterator = updated_recordings;
			return;
		}
	throw RepositoryExceptions("Not in the repository");}

void RecordingsRepository::DeleteRecording(TElem delete_recording) 
{
	for (std::vector<TElem>::iterator recordings_iterator = Recordings_repository.begin(); recordings_iterator != Recordings_repository.end(); ++recordings_iterator)
		if (*recordings_iterator == delete_recording)
		{
			this->Recordings_repository.erase(recordings_iterator);
			return;
		}
	throw RepositoryExceptions("Not in the repository");}

vector<TElem> RecordingsRepository::ListAllRecordings() 
{
	vector<TElem> list_vector = this->Recordings_repository;
	return list_vector;
}
int RecordingsRepository::RepositorySize()
{
	return this->Recordings_repository.size();
}
TElem RecordingsRepository::NextRecording(int index)
{
	return Recordings_repository[index];
}

bool RecordingsRepository::EndOfList(int index)
{
	if (index < this->Recordings_repository.size())
		return false;
	else
		return true;
}

TElem RecordingsRepository::SearchinList(TElem element)
{
	for (auto recordings_iterator = Recordings_repository.begin(); recordings_iterator != Recordings_repository.end(); ++recordings_iterator)
		if (*recordings_iterator == element)
		{
			return *recordings_iterator;
		}
	throw RepositoryExceptions("Not in the repository");}



vector<TElem> RecordingsRepository::Filtered(string location, int times_accessed) 
{
	vector<TElem> filtered_list;
	filtered_list.resize(Recordings_repository.size());
	auto filter_iterator = std::copy_if(Recordings_repository.begin(), Recordings_repository.end(),filtered_list.begin(), [location,times_accessed](TElem recording){ return recording.getLocation()==location && times_accessed>recording.getTimesAccessed();});
	filtered_list.resize(std::distance(filtered_list.begin(), filter_iterator));
	return filtered_list;
}

void RecordingsRepository::FileLoadStore(string file_load)
{
	this->file = file_load;
	LoadFromFile();
}

void RecordingsRepository::LoadFromFile()
{
	ifstream input_file(file);
	if (!input_file.is_open())
		return;
	TElem recording;
	while (input_file >> recording)
	{
		if(recording.getTitle()!="fail078")
			this->AddNewRecording(recording);	
	}
	input_file.close();
}
void RecordingsRepository::StoreToFile()
{
	ofstream output_file(file);
	if (!output_file.is_open())
		return;
	for (auto const& recording : Recordings_repository)
	{
		output_file << recording;
	}

	output_file.close();
}



