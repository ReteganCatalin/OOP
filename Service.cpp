#include "service.h"
#include "HTMLRepository.h"
#include "DummyRepository.h"
#include "Validators.h"
#include "repository.h"
void ServiceModeA::AddNewRecording(Recordings add)
{
	this->ServiceToRepository->AddNewRecording(add);
}

void ServiceModeA::UpdateExistingRecordings(Recordings update) 
{
	this->ServiceToRepository->UpdateExistingRecording(update);
}

void ServiceModeA::DeleteRecordings(Recordings delete_command) 
{
	this->ServiceToRepository->DeleteRecording(delete_command);
}

vector<TElem> ServiceModeA::ListAllRecordings() 
{
	return this->ServiceToRepository->ListAllRecordings();
}
int ServiceModeA::VectorSize()
{
	return this->ServiceToRepository->RepositorySize();
}

TElem ServiceModeA::NextRecording()
{
	TElem next_recording = this->ServiceToRepository->NextRecording(this->next_index);
	next_index++;
	if (this->ServiceToRepository->EndOfList(next_index) == true)
		next_index = 0;
	return next_recording;
}

void ServiceModeA::SaveInList(TElem element)
{
	if(this->validate->validate_input(element)==true)
	{
		TElem save_element = this->ServiceToRepository->SearchinList(element);
		this->ServiceToUserList->SaveList(save_element);
	}
	
}

void ServiceModeA::ListAllMyList()
{
	ServiceToUserList->ListMyList();
}

int ServiceModeA::MylistSize()
{
	return this->ServiceToUserList->MyListSize();
}

vector<TElem> ServiceModeA::Filtered(string location,int times_accessed)
{
	return this->ServiceToRepository->Filtered(location,times_accessed);
}

void ServiceModeA::FileLoadStore(string file)
{
	this->ServiceToRepository->FileLoadStore(file);
}

void ServiceModeA::StoreToFile()
{
	this->ServiceToRepository->StoreToFile();
	this->ServiceToUserList->StoreToFile();
}

void ServiceModeA::KeepFile(string file)
{
	std::size_t found = file.find_last_of(".");
	
	if (file.compare(found+1, 3, "csv") == 0)
	{
		ServiceToUserList = new CSVRepository{};
	}
	else if (file.compare(found+1, 4, "html") == 0)
	{
		ServiceToUserList = new HTMLRepository{};
	}
	else if (file.compare(found+1, 5, "dummy") == 0)
	{
		ServiceToUserList = new DummyRepository{};
	}
	else
		throw std::exception("File not found");
	ServiceToUserList->KeepFile(file);
}

void ServiceModeA::TransformValidatorAndRepository(int choice)
{
	if (choice == 1)
	{
		ServiceToRepository = new RecordingsRepository;
		this->validate= new Validators;
	}	
	else if (choice == 2)
	{
		ServiceToRepository = new FakeRepository{};
		this->validate = new FakeValidator{};
	}
		
}
