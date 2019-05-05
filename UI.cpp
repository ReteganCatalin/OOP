#include "UI.h"
#include <iostream>
#include <typeinfo>
#include <string>
#include <cstddef> 

void UI::StartMenu()
{
	string command;
	string title, location, create_date, footage_preview;
	int times_accessed = 0;
	string mode;
	string file,read_command;
	bool exit = false;
	int running_mode = 0;
	std::cout << "Give file:\n";
	getline(cin, read_command);
	bool ok = false;
	
	int index;
	this->service_modeA.TransformValidatorAndRepository(1);
	while (read_command.compare(0, 12, "fileLocation") != 0) {
		std::cout << "Give command for file again\n";
		getline(cin, read_command);
	}
	for (index=0; index < read_command.size() && ok == false; index++)
	{
		if (read_command[index] == ' ')
			ok = true;
	}
	file.append(read_command.begin() + index, read_command.end());
	try
	{
		this->service_modeA.FileLoadStore(file);
	}
	catch(exception& error)
	{
		std::cout << error.what() << "\n";
	}
	std::cout << "Give user file:\n";
	string new_command,user_file;
	ok = false;
	getline(cin, new_command);
	while (new_command.compare(0, 14, "mylistLocation") != 0) {
		std::cout << "Give command for user file again\n";
		getline(cin, new_command);
	}
	for (index = 0; index < new_command.size() && ok == false; index++)
	{
		if (new_command[index] == ' ')
			ok = true;
	}
	user_file.append(new_command.begin() + index, new_command.end());
	try
	{
		this->service_modeA.KeepFile(user_file);
	}
	catch (exception& error)
	{
		std::cout << error.what() << "\n";
		return;
	}
	std::cout << "Which mode to use A|B:\n";
	getline(cin, mode);
	if (mode =="mode A")
	{
		running_mode = 1;
	}
	else if (mode=="mode B")
	{
		running_mode = 2;
	}
	else
	{
		std::cout << "Invalid mode";
	}
	while (exit==false && running_mode>0)
	{
		getline(cin,command);
		if (command.size() == 0)
		{
			std::cout << "Invalid input"<<"\n";
		}
		else
		{
			if (command.compare(0,4,"mode") == 0)
			{
				if (command[5]=='A')
					running_mode = 1;
				else if (command[5]=='B')
				{
					running_mode = 2;
				}
				else
				{
					std::cout << "Invalid mode";
					return;
				}
			}
			else
			{
				if (running_mode == 1)
				{
					if (command.compare(0,3,"add") == 0 || command.compare(0,6,"update") == 0)
					{
						try
						{
							Recordings command_new = validate.CreateCommandandValidate(command);
							if (validate.validate_input(command_new))
							{
								if (command.compare(0, 3, "add") == 0)
								{
									try
									{
										this->service_modeA.AddNewRecording(command_new);
									}
									catch (RepositoryExceptions& error)
									{
										std::cout << error.what() << "\n";
									}
								}
								else {
									try
									{
										this->service_modeA.UpdateExistingRecordings(command_new);
									}
									catch (RepositoryExceptions& error)
									{
										std::cout << error.what() << "\n";
									}
								}
							}

						}
						catch (ValidateExceptions& input_error)
						{
							std::cout << input_error.what() << "\n";
						}
					}
					else
					{
					
						if (command.compare(0,6,"delete") == 0) 
						{
						
							title = validate.ValidateString(command);
							if (validate.ValidateEnd() != true)
								std::cout << "Invalid input\n";
							times_accessed = 0;
							Recordings command_new = Recordings(title, location, create_date, times_accessed, footage_preview);
							if (strcmp(typeid(title).name(), "int") != 0)
							{
								try
								{
									this->service_modeA.DeleteRecordings(command_new);
								}
								catch (RepositoryExceptions& error) {
									std::cout << error.what() << "\n";
								}
							}
						}
						else
						{
							if (command.compare(0,4,"list") == 0)
							{
								if (validate.ValidateEndNothing(command) != true)
									std::cout << "Too many parameters\n";
								vector<TElem> Recordings_for_Printing = this->service_modeA.ListAllRecordings();
								//int size_of_repository = this->service_modeA.VectorSize();
								for (auto const& recording : Recordings_for_Printing)
								{
									std::cout<<"Title: "<<recording.getTitle();
									std::cout<<", Location: "<<recording.getLocation();
									std::cout<<", Creation date: "<<recording.getCreationDate();
									std::cout<<", Times accessed: "<<recording.getTimesAccessed();
									std::cout << ", Footage preview: " << recording.getFootagePreview() << "\n";
								}
							}
							else
							{
								if (command.compare(0,4,"exit") == 0 && command.size()==4)
								{
									this->service_modeA.StoreToFile();
									exit = true;
								}
								else
									std::cout << "Invalid input";
							}
						}
					}
				}
				else if (running_mode == 2)
				{
					if (command.compare(0,4,"exit") == 0 && command.size() == 4)
					{
						this->service_modeA.StoreToFile();
						exit = true;
					}
					else if (command.compare(0,4,"next") == 0)
					{
						if (validate.ValidateEndNothing(command) != true)
							std::cout << "Too many parameters\n";
						else
						{
							try
							{
								TElem next_recording = this->service_modeA.NextRecording();
								std::cout << "Title: " << next_recording.getTitle();
								std::cout << ", Location: " << next_recording.getLocation();
								std::cout << ", Creation date: " << next_recording.getCreationDate();
								std::cout << ", Times accessed: " << next_recording.getTimesAccessed();
								std::cout << ", Footage preview: " << next_recording.getFootagePreview() << "\n";
							
							}
							catch (RepositoryExceptions* error)
							{
								std::cout << error << "\n";
							}
						}
					}
					else if (command.compare(0,4,"save") == 0)
					{
						
						title = validate.ValidateString(command);
						times_accessed = 0;
						Recordings recording = Recordings(title, location, create_date, times_accessed, footage_preview);
						if (validate.ValidateEnd() != true)
							std::cout << "Invalid input\n";
						else
						{
							try
							{
								this->service_modeA.SaveInList(recording);
							}
							catch (RepositoryExceptions& error)
							{
								std::cout << error.what() << "\n";
							}
						}
					}
					else if (command.compare(0,6,"mylist") == 0)
					{
						if (validate.ValidateEndNothing(command) != true)
							std::cout << "Invalid input\n";
						else
						{
							this->service_modeA.ListAllMyList();
						}
					}
					else if (command.compare(0, 4, "list") == 0)
					{
						try
						{
							
							location = validate.ValidateString(command);
							if (validate.ValidateEnd() != false)
								throw ValidateExceptions("Invalid input\n");
							string times = validate.ValidateStringNext(command);
							if (validate.ValidateEnd() != true)
								throw ValidateExceptions("Invalid input");
							times_accessed = stoi(times);
							vector<TElem>filtered_recordings = this->service_modeA.Filtered(location, times_accessed);
							for (auto const& recording : filtered_recordings)
							{
								std::cout << "Title: " << recording.getTitle();
								std::cout << ", Location: " << recording.getLocation();
								std::cout << ", Creation date: " << recording.getCreationDate();
								std::cout << ", Times accessed: " << recording.getTimesAccessed();
								std::cout << ", Footage preview: " << recording.getFootagePreview() << "\n";
							}
						}
						catch (ValidateExceptions& error)
						{
							std::cout << error.what() << "\n";
						}
					}
					else
						std::cout << "Invalid input";
				}
			}
		}
	}
		
}