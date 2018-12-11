#include "Person.h"

std::string Person::getName()
{
	return name;
}

int Person::getHomeLoc()
{
	return homeLoc;
}

int Person::getWorkLoc()
{
	return workLoc;
}

int Person::getCurrentLoc()
{
	return currentLoc;
}

int Person::getPersonState()
{
	return personState;
}

void Person::setName(std::string n)
{
	name = n;
}

void Person::setHomeLoc(int h)
{
	homeLoc = h;
}

void Person::setWorkLoc(int w)
{
	workLoc = w;
}

void Person::setCurrentLoc(int c)
{
	currentLoc = c;
}
