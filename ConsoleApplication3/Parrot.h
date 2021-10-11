#include "stdafx.h"
#include "Utils.h"

class Parrot: public Animal
{
private:
	Parrot(float weight, char sex, unsigned int age, const char* breed, const char* color, const char* name)
		:Animal(weight, sex, age, breed, color, name)
	{
	}

	virtual void Validate(vector<string> &errors)
	{
		Animal::Validate(errors);

		if (this->Age() > 70)
			errors.push_back("������������ ������� �������");
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
			   !getValue("������� ���", weight)
			|| !getValue("������� ���", sex)
			|| !getValue("������� �������", age)
			|| !getValue("������� ������", breed)
			|| !getValue("������� ���������", color)
			|| !getValue("������� ������", name)
			)
			return NULL;

		Parrot* result = new Parrot(weight, sex[0], age, breed, color, name);

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
		return "�������";
	}

	virtual const char* Description() const
	{
		return "���� ��������";
	}

	virtual const char* Sex() const
	{
		switch (this->m_sex)
		{
		case 'M': return "�����";
		case 'F': return "�����";
		default:
			return "?";
		}
	}
};