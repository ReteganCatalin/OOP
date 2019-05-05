#pragma once
#include "Recordings.h"
#include <vector>
#include <stdexcept>

typedef Recordings TElem;
class RecordingsRepository {
private:
	vector<TElem> Recordings_repository;
	//vector<TElem> User_list;
	string file;
public:
	RecordingsRepository() {};
	void AddNewRecording(TElem new_recording);
	void UpdateExistingRecording(TElem new_recording);
	void DeleteRecording(TElem new_recording);
    vector<TElem> ListAllRecordings();
	int RepositorySize();
	TElem NextRecording(int index);
	bool EndOfList(int index);
	virtual TElem SearchinList(TElem element);
	/*
	vector<TElem> ListMyList();
	int MyListSize();*/
	vector<TElem> Filtered(string location,int times_accessed);
	void FileLoadStore(string file);
	void LoadFromFile();
	void StoreToFile();
};

class FakeRepository : public RecordingsRepository
{
public:
	TElem SearchinList(TElem element) override
	{
		return element;
	}
	
};
