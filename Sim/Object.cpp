#include <cstdlib>
#include <iostream>
#include <vector>
#include "Object.h"
#include "constants.h"


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

void Object::UpdateAcc(){
	acc = force/massInKg;
}
void Object::UpdateVel(){
	vel = vel + acc*TICK;
}
void Object::UpdatePos(){
	pos = pos + vel*TICK + (acc*pow(TICK,2)*0.5);
}

Vector3D<double> Object::getAcc(){
	return acc;
}

Vector3D<double> Object::getVel(){
	return vel;
}

Vector3D<double> Object::getPos(){
	return pos;
}

void Object::setMass(double A){
	massInKg = A;
}



