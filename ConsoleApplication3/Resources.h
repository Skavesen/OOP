#include "stdafx.h"
#include "Messages.h"

enum Language : unsigned int
{
	 Russian = 0
	,English = 1
};

class Resources
{
private:
	Language m_currLang = Language::Russian;
	vector<string> m_messages[2] = {{ }, {}};

public:
	void SetLanguage(Language newLanguage)
	{
		this->m_currLang = newLanguage;
	}

	Language GetLanguage() const
	{
		return this->m_currLang;
	}

	bool Load(Language langIndex, const char* fileName);

	void Clear()
	{
		for (int i = 0; i < (sizeof(this->m_messages) / sizeof(this->m_messages[0])); i++)
			this->m_messages[i].clear();
	}

	const char* operator[] (Message messageIndex)
	{
		if (messageIndex >= this->m_messages[this->m_currLang].size())
			return "?";
		else
			return this->m_messages[this->m_currLang][messageIndex].c_str();
	}
};

ostream& operator << (ostream& os, const Message& message);

extern Resources resources;

