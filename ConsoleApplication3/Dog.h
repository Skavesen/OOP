#include "stdafx.h"
#include "Utils.h"

class Dog:public Animal
{
private:
	Dog(float weight, char sex, unsigned int age, const char* breed, const char* color, const char* name)
		:Animal(weight, sex, age, breed, color, name)
	{
	}

	virtual void Validate(vector<string> &errors)
	{
		Animal::Validate(errors);
	}

public:
	static Animal* Create()
	{
		float weight;
		char sex[128];
		unsigned int age;
		char breed[128];
		char color[128];
		char name[128];

		if (
			   !getValue("¬ведите вес", weight)
			|| !getValue("¬ведите пол", sex)
			|| !getValue("¬ведите возраст", age)
			|| !getValue("¬ведите породу", breed)
			|| !getValue("¬ведите расцветку", color)
			|| !getValue("¬ведите кличку", name)
			)
			return NULL;

		Dog* result = new Dog(weight, sex[0], age, breed, color, name);

		vector<string> errors;
		result->Validate(errors);
		if (0 == errors.size())
			return result;

		delete result;
		for (vector<string>::iterator it = errors.begin(); it != errors.end(); it++)
		{
			cout << (*it).c_str() << endl;
		}
		
		return NULL;
	}

	virtual const char* Kind() const
	{
		return "собака";
	}

	virtual const char* Description() const
	{
		return "друг человека";
	}

	virtual const char* Sex() const
	{
		switch (this->m_sex)
		{
		case 'M': return "кобель";
		case 'F': return "сука";
		default:
			return "?";
		}
	}
};