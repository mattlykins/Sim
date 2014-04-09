#include <cstdlib>
#include <iostream>
#include <vector>
#include "Object.h"


long Object::number = 0;
std::vector<Object*> Object::AllObjects;

Object::Object(){
		index = number;
		++number;
		AllObjects.push_back(this);

		massInKg = 0.;
}

Object::~Object(){
	--number;
	AllObjects.erase(AllObjects.begin() + this->index);

}



