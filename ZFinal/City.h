#ifndef CITY_H
#define CITY_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <utility>
#include <cstdlib>
#include <fstream>
#include "Person.h"
#include "Ignorant.h"
#include "Zombie.h"

class City
{
private:
	friend class Person;
	friend class Zombie;
	friend class Alarmed;
	friend class Ignorant;

public:
	City() {}

	//City locations
	std::vector<Person*> Docks;
	std::vector<Person*> MedicalHill;
	std::vector<Person*> Downtown;
	std::vector<Person*> University;
	std::vector<Person*> Soho;
	std::vector<Person*> Uptown;

	//Key = person state (0, 1, or 2) allows us to count the number of zombies, ignorants, and alarmed people
	//Value = the actual person represented by the key
	std::multimap<int, Person*> personMap;

	//Holds the layout of all of the locations
	std::vector<std::vector<Person*>> District;

	//Takes the names from file IO
	std::vector<std::string> listNames;

	//File IO, puts names into listNames
	void addNames();

	//Creates the initial people in the City
	void createPeople();

	//Puts the people from each location into the map personMap
	void sortPeople();

	//Counts the number of people with a specific key in personMap and displays how many people are in each state
	void countPeople();

	//Pushes back locations into District
	void fillDistrict();
};

#endif
