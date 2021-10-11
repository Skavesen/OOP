#include "stdafx.h"
#include "Resources.h"

Resources resources;

bool Resources::Load(Language langIndex, const char* fileName)
{
	if (langIndex >= sizeof(this->m_messages) / sizeof(this->m_messages[0]))
		return false;

	ifstream dataFile(fileName);
	if (!dataFile.is_open())
	{
		cerr << "Can't open file \"" << fileName << "\"!" << endl;
		return false;
	}

	this->m_messages[langIndex].clear();

	while (!dataFile.eof())
	{
		char buffer[1024];
		dataFile.getline(buffer, sizeof(buffer) / sizeof(buffer[0]));
		this->m_messages[langIndex].push_back(string(buffer));
	}
	dataFile.close();

	return true;
};

ostream& operator << (ostream& os, const Message& message)
{
	os << resources[message];
	return os;
};
