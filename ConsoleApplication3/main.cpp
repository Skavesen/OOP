#include "stdafx.h"

#include "Resources.h"
#include "Utils.h"

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Parrot.h"

vector<Animal*> animals = {};

void clearAnimals()
{
	for (vector<Animal*>::iterator it = animals.begin(); it != animals.end(); it++)
	{
		delete *it;
	}

	animals.clear();
}

void addAnimal()
{
	while (true)
	{
		Animal* newAnimal = NULL;

		switch (getChoice(
			Message::Choose_an_animal
			,4
			,Message::Dog
			,Message::Cat
			,Message::Parrot
			,Message::Go_back
		))
		{
		case 1:
			newAnimal = Dog::Create();
			break;

		case 2:
			newAnimal = Cat::Create();
			break;

		case 3:
			newAnimal = Parrot::Create();
			break;

		case 4:
			return;
		}

		if (NULL != newAnimal)
		{
			animals.push_back(newAnimal);
			cout << endl << Message::Ok << endl;
		}
	}
}

void continueAsManager()
{
	while (true)
	{
		switch (getChoice(
			Message::Select_an_action
			,5
			,Message::Add_an_animal
			,Message::View_the_statement
			,Message::Removing_an_animal
			,Message::Full_cleaning_of_the_list
			,Message::Return_to_main_menu
		))
		{
		case 1:
			addAnimal();
			break;

		case 2:
			{
				int index = 0;
				for (vector<Animal*>::iterator it = animals.begin(); it != animals.end(); it++)
				{
					cout << '#' << ++index << endl << (Animal*) *it << endl;
				}
			}
			break;

		case 3:
			unsigned int erasedIndex;
			if (getValue("Введите порядковый номер удаляемого животного в ведомости (начиная с 1)", erasedIndex))
			{
				if (erasedIndex >= 1 && erasedIndex <= animals.size())
				{
					Animal* erasedAnimal = animals[erasedIndex - 1];
					animals.erase(animals.begin() + erasedIndex - 1);
					delete erasedAnimal;
					cout << Message::Ok << endl;
				}
				else
					cout << Message::BadItemIndex << endl;
			}
			break;

		case 4:
			/*cout << Message::Clear_the_list << endl;*/
			if (confirm("Вы действительно хотите очистить ведомость?"))
			{
				clearAnimals();
				cout << Message::Ok << endl;
			}
			break;

		case 5:
			return;
		}
	}
}

void continueAsClient()
{
	while (true)
	{
		switch (getChoice(
			 Message::Select_an_operation
			,2
			,Message::View_Assortment
			,Message::Return_to_main_menu
		))
		{
		case 1:
			for (vector<Animal*>::iterator it = animals.begin(); it != animals.end(); it++)
			{
				cout << (Animal*) *it;
			}
			break;

		case 2:
			return;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (!resources.Load(Language::Russian, "Lang\\Ru.txt") || !resources.Load(Language::English, "Lang\\En.txt"))
	{
		return -1;
	}

	resources.SetLanguage(Language::Russian);

	cout << Message::MainGreeting << endl;

	while (true)
	{
		switch (getChoice(
			Message::SelectUserTypePrompt   
				,3
				,Message::UserIsAdmin
				,Message::UserIsClient
				,Message::ExitFromProgram
		))
		{
			case 1:
				if (checkAccess("password"))
					continueAsManager();
				else
					cout << Message::AccessDenied << endl;
				break;
			
			case 2:
				continueAsClient();
				break;
			
			case 3:
				cout << endl << Message::MainExit << endl;
				
				clearAnimals();
				resources.Clear();

				_CrtDumpMemoryLeaks();

				return 0;
		}
	}
}
