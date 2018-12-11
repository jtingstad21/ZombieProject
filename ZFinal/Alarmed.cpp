#include "Alarmed.h"

void Alarmed::move()	//Defines how alarmed people move. Alarmed citizens cannot go to their home locations
{
	int random = rand() % 6;
	if (random != this->getHomeLoc())
		this->setCurrentLoc(random);
	else if (random == this->getHomeLoc())
	{
		if (random <= 1)
		{
			++random;
			this->setCurrentLoc(random);
		}
		else if (random > 4)
		{
			--random;
			this->setCurrentLoc(random);
		}
		else
		{
			++random;
			this->setCurrentLoc(random);
		}
	}
}

Person* Alarmed::interact(Person &p)	//Creates new Alarmed person if the interaction is with an ignorant (state 0)
{
	int state = p.getPersonState();
	if (state == 0) {
		std::string name = p.getName();
		int h = p.getHomeLoc();
		int w = p.getWorkLoc();
		Alarmed* newAlarmed = new Alarmed(name, h, w);
		return newAlarmed;
	}
	else if (state == 1) {
		std::string name = p.getName();
		int h = p.getHomeLoc();
		int w = p.getWorkLoc();
		Alarmed* newAlarmed = new Alarmed(name, h, w);
		return newAlarmed;
	}
	else {
		std::string name = p.getName();
		int h = p.getHomeLoc();
		int w = p.getWorkLoc();
		Zombie* newZombie = new Zombie(name, h, w);
		return newZombie;
	}
}
