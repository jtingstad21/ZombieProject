#include "Zombie.h"

void Zombie::move()		//Zombies move randomly to adjacent districts to the one that they are currently in or stay put
{
	int random = rand() % 3;
	int cLoc = this->getCurrentLoc();
	if (cLoc <= 1) {
		++cLoc;
		this->setCurrentLoc(cLoc);
	}
	else if (cLoc > 4) {
		--cLoc;
		this->setCurrentLoc(cLoc);
	}
	else {
		if (random == 0) {
			--cLoc;
			this->setCurrentLoc(cLoc);
		}
		else if (random == 1) {
			this->setCurrentLoc(cLoc);
		}
		else {
			++cLoc;
			this->setCurrentLoc(cLoc);
		}
	}
}

Person* Zombie::interact(Person &p)		//Defines what happens when a zombie bites (can fail or succeed)
{
	int state = p.getPersonState();
	int biteChance = (rand() % 10) + 1;
	if (state == 0) {
		if (biteChance <= 8) {
			std::string name = p.getName();
			int h = p.getHomeLoc();
			int w = p.getWorkLoc();
			Zombie* newZombie = new Zombie(name, h, w);
			return newZombie;
		}
		else {
			std::string name = p.getName();
			int h = p.getHomeLoc();
			int w = p.getWorkLoc();
			Alarmed* newAlarmed = new Alarmed(name, h, w);
			return newAlarmed;
		}
	}
	else if (state == 1) {
		if (biteChance <= 6) {
			std::string name = p.getName();
			int h = p.getHomeLoc();
			int w = p.getWorkLoc();
			Zombie* newZombie = new Zombie(name, h, w);
			return newZombie;
		}
		else {
			std::string name = p.getName();
			int h = p.getHomeLoc();
			int w = p.getWorkLoc();
			Alarmed* newAlarmed = new Alarmed(name, h, w);
			return newAlarmed;
		}
	}
	else {
		std::string name = p.getName();
		int h = p.getHomeLoc();
		int w = p.getWorkLoc();
		Zombie* newZombie = new Zombie(name, h, w);
		return newZombie;
	}
}


