#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

class Person
{
private:
	std::string name;
	int homeLoc;
	int workLoc;
	int currentLoc;
	int personState;	//can be either 0, 1, or 2 and each corresponds to Ignorant, Alarmed, or Zombie

	friend class Zombie;
	friend class Alarmed;
	friend class Ignorant;

public:
	Person()	//Default no-arg constructor
	{
		name = "John";
		homeLoc = 0;
		workLoc = 0;
		currentLoc = 0;
	}
	Person(std::string n, int h, int w)		//Overloaded constructor
	{
		name = n;
		homeLoc = h;
		workLoc = w;
		currentLoc = h;
	}

	//Getter functions
	std::string getName();
	int getHomeLoc();
	int getWorkLoc();
	int getCurrentLoc();
	int getPersonState();

	//Setter functions
	void setName(std::string n);
	void setHomeLoc(int h);
	void setWorkLoc(int w);
	void setCurrentLoc(int c);

	//Virtual void functions which define behavior for Person objects
	virtual void move() = 0;
	virtual Person* interact(Person &p) = 0;
};

#endif
