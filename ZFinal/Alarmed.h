#ifndef ALARMED_H
#define ALARMED_H
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Person.h"
#include "Zombie.h"

//Derived class of Person
class Alarmed : public Person
{
public:
	Alarmed() : Person() {}
	Alarmed(std::string n, int h, int w)
	{
		name = n;
		homeLoc = h;
		workLoc = w;
		personState = 1;
	}
	//Virtual void functions defined in Person
	void move();
	Person* interact(Person &p);
};

#endif
