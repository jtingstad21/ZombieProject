#ifndef IGNORANT_H
#define IGNORANT_H
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Person.h"

//Derived class of Person
class Ignorant : public Person
{
public:
	Ignorant() : Person() {}
	Ignorant(std::string n, int h, int w)
	{
		name = n;
		homeLoc = h;
		workLoc = w;
		currentLoc = h;
		personState = 0;
	}

	//Defines the virtual void functions that are created in Person
	void move();
	Person* interact(Person &p);
};

#endif
