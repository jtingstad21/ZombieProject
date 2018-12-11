#include "Ignorant.h"

void Ignorant::move()	//Ignorant people only move between their home and work locations
{
	if (this->getCurrentLoc() == this->getHomeLoc())
		this->setCurrentLoc(this->getWorkLoc());
	else if (this->getCurrentLoc() == this->getWorkLoc())
		this->setCurrentLoc(this->getHomeLoc());
	else
		this->setCurrentLoc(this->getHomeLoc());
}

Person* Ignorant::interact(Person &p)	//the interact for ignorant people doesn't do anything so it returns a null pointer
{
	return nullptr;
}
