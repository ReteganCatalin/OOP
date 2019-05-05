#pragma once
#include "repository.h"
#include "UserRepository.h"
#include "CSVRepository.h"
#include "Validators.h"
class ServiceModeA 
{
private:
	RecordingsRepository* ServiceToRepository;
	UserRepository* ServiceToUserList ;
	Validators* validate;
	int next_index;
public:
	ServiceModeA() { this->next_index = 0; };
	void AddNewRecording(Recordings add);
	void UpdateExistingRecordings(Recordings update);
	void DeleteRecordings(Recordings delete_command);
	int VectorSize();
	vector<TElem> ListAllRecordings();
	TElem NextRecording();
	void SaveInList(TElem element);
	void ListAllMyList();
	int MylistSize();
	vector<TElem> Filtered(string location, int times_accessed);
	void FileLoadStore(string file);
	void StoreToFile();
	void KeepFile(string file);
	void TransformValidatorAndRepository(int choice);
};