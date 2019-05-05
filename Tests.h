#pragma once
#include <assert.h>
#include "Service.h"

void TestAll()
{
	ServiceModeA test_service = ServiceModeA();
	test_service.KeepFile(".dummy");
	test_service.TransformValidatorAndRepository(2);
	test_service.AddNewRecording(Recordings("alakazam", "yoy", "234", 34, "www.no"));
	test_service.AddNewRecording(Recordings("charmander", "23-34-FGDF", "LOLz",34, "www.yes"));
	//test_service.AddNewRecording(Recordings("totodile", "23-34-HHDF", "15-04-78", 10, "www.trap"));
	//test_service.AddNewRecording(Recordings("torterra", "antyyoy", "1.2.3", 340, "www.45.html"));
	test_service.SaveInList(Recordings("alakazam", "yoy", "234", 34, "www.no"));
	assert(test_service.MylistSize() == 1);
	try
	{
		test_service.SaveInList(Recordings("alakazam", "yoy", "234", 34, "www.no"));
		assert(false);
	}
	catch (RepositoryExceptions& error)
	{
		if (strcmp(error.what(), "No way to add") == 0)
			assert(true);
		else
			assert(false);
	}
	try
	{
		test_service.SaveInList(Recordings("charmander", "yoy", "234", 34, "www.no"));
		assert(false);
	}
	catch (RepositoryExceptions& error)
	{
		if (strcmp(error.what(), "Weak pokemon") == 0)
			assert(true);
		else
			assert(false);
	}
	TElem test_next = test_service.NextRecording();
	assert(test_next.getTitle() == "alakazam");
	TElem test_next_second = test_service.NextRecording();
	assert(test_next_second.getTitle() == "charmander");
	TElem test_restart = test_service.NextRecording();
	assert(test_restart.getTitle() == "alakazam");
	test_service.AddNewRecording(Recordings("torterra", "antyyoy", "1.2.3", 340, "www.45.html"));
	test_service.SaveInList(Recordings("torterra", "yoy", "234", 34, "www.no"));
	assert(test_service.MylistSize() == 2);
	
	try
	{
		test_service.SaveInList(Recordings("charizard", "3", "234", 34, "www.no"));
		assert(false);
	}
	catch (ValidateExceptions& error)
	{
		if (strcmp(error.what(), "LOL") == 0)
			assert(true);
		else
			assert(false);
	}
	

} 
