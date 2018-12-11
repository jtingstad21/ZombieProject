#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Person.h"
#include "Alarmed.h"

//Derived class of Person
class Zombie : public Person
{
public:
	Zombie() : Person() {}
	Zombie(std::string n, int h, int w)
	{
		name = n;
		homeLoc = h;
		workLoc = w;
		personState = 2;
	}

	//Virtual functions laid out in Person
	void move();
	Person* interact(Person &p);
};

#endif
