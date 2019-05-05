#include "HTMLRepository.h"



void HTMLRepository::StoreToFile()
{
	ofstream file(file_name);
	if (!file.is_open()) return;

	file << "<!DOCTYPE html>";
	file << "<html>";
	file << "	<head>";
	file << "		<title>Recordings</title>";
	file << "	</head>";
	file << "	<body>";
	file << "		<table border=" << char(34) << "1" << char(34) << ">";
	file << "		<tr>";
	file << "			<td>Title</td>";
	file << "			<td>Location</td>";
	file << "			<td>Creation Date</td>";
	file << "			<td>Number of times accessed</td>";
	file << "			<td>Footage Preview</td>";
	file << "		</tr>";

	for (auto const&  recording: User_list) {
		file << "		<tr>";
		file << "			<td>" << recording.getTitle() << "</td>";
		file << "			<td>" << recording.getLocation() << "</td>";
		file << "			<td>" << recording.getCreationDate() << "</td>";
		file << "			<td>" << recording.getTimesAccessed() << "</td>";
		file << "			<td><a href = \"" << recording.getFootagePreview() << "\">Recording link</a></td>";
		file << "		</tr>";
	}
	file << "		</table>";
	file << "	</body>";
	file << "</html>";
	file.close();

}



HTMLRepository::~HTMLRepository()
{
}
