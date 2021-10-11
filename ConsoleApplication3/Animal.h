#include "stdafx.h"

class Animal 
{
private:
	float m_weight;
	unsigned  int m_age;
	string m_breed;
	string m_color;
	string m_name;

protected:
	char m_sex;

public:
	Animal(float weight, char sex, unsigned int age, const char* breed, const char* color, const char* name)
	{
		this->m_weight = weight;
		this->m_sex = sex;
		this->m_age = age;
		this->m_breed = breed;
		this->m_color = color;
		this->m_name = name;
	}

	virtual const char* Kind() const = 0;

	virtual const char* Description() const = 0;

	virtual void Validate(vector<string> &errors)
	{
		if (0 == this->m_weight)
			errors.push_back("не указан вес животного");
		if ('F' != this->m_sex && 'M' != this->m_sex)
			errors.push_back("пол животного обозначается либо F (female), либо M (male)");
		if (0 == this->m_age)
			errors.push_back("не указан возраст животного");
		if (0 == this->m_breed.length())
			errors.push_back("не указана порода животного");
		if (0 == this->m_color.length())
			errors.push_back("не указана расцветка животного");
		if (0 == this->m_name.length())
			errors.push_back("не указана кличка животного");
	}

	const float Weight() const
	{
		return this->m_weight;
	}

	virtual const char* Sex() const = 0;

	const unsigned int Age() const
	{
		return this->m_age;
	}

	void operator--()
	{
		if (m_weight >= 0.1)
			m_weight -= 0.1;
	}

	const char* Breed() const
	{
		return this->m_breed.c_str();
	}

	const char* Color() const
	{
		return this->m_color.c_str();
	}

	const char* Name() const
	{
		return this->m_name.c_str();
	}
};

ostream& operator << (ostream& os, const Animal* animal) 
{
	os  << '\t' << animal->Kind() << ' ' << " (" << animal->Description() << ')' << endl
		<< '\t' << "Кличка  : " << animal->Name() << endl
		<< '\t' << "Вес     : " << animal->Weight() << endl
		<< '\t' << "Возраст : " << animal->Age() << endl
		<< '\t' << "Пол     : " << animal->Sex() << endl
		<< '\t' << "Порода  : " << animal->Breed() << endl
		<< '\t' << "Окрас   : " << animal->Color() << endl
		;

	return os;
}