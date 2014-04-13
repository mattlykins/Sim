#include <cstdlib>
#include <iostream>
#include <vector>
#include "Object.h"
#include "constants.h"


long Object::number = 0;
double Object::time = 0.;
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

Vector3D<double> Object::CalcGravity(Object &A){
	//Find R2-R1
	Vector3D<double> R21 = A.pos - this->pos;
	Vector3D<double> uR21 = R21/R21.length();

	//Protect against div by zero
	double forceMultiplier = G*A.massInKg*this->massInKg/pow(R21.length(),2);

	return uR21*forceMultiplier;
}

void Object::GetNetForce(){
	std::vector<Object*>::iterator it;

	ZeroForce();

	for( it = AllObjects.begin(); it != AllObjects.end(); ++it ){
		if( *it != this ){
			force = force + CalcGravity(**it);
		}
	}
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

Vector3D<double>& Object::getVel(){
	return vel;
}

Vector3D<double>& Object::getPos(){
	return pos;
}

void Object::setMass(double A){
	massInKg = A;
}

void Object::ZeroForce(){
	force.x(0);
	force.y(0);
	force.z(0);
}

void Object::Update(){
	GetNetForce();
	UpdateAcc();
	UpdatePos();
	UpdateVel();
	time = time + TICK;
}

void Object::Print(){
	std::cout << index << "\t";
	std::cout << time << "\t";
	std::cout << pos.x() << "\t" << pos.y() << "\t" << pos.z() << "\t";
	std::cout << vel.x() << "\t" << vel.y() << "\t" << vel.z() << "\t";
	std::cout << acc.x() << "\t" << acc.y() << "\t" << acc.z() << "\t";
	std::cout << force.x() << "\t" << force.y() << "\t" << force.z() << "\t";
	std::cout << std::endl;
}
void Object::PrintHeader(){
	std::cout << "INDEX\tTIME(s)\tx(m)\ty(m)\tz(m)\tv_x(m/s)\tv_y(m/s)\tv_z(m/s)\ta_x(m/s/s)\ta_y(m/s/s)\ta_z(m/s/s)\tF_x(N)\tF_y(N)\tF_z(N)\n";

}



