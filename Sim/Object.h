#include <cstdlib>
#include <iostream>
#include <vector>

#include "Vector3D.h"


#ifndef OBJECT_H_
#define OBJECT_H_

class Object {
public:
	Object();
	~Object();

	void UpdateAcc();
	void UpdateVel();
	void UpdatePos();

	Vector3D<double> force;

	Vector3D<double> getForce();
	Vector3D<double> getAcc();
	Vector3D<double> getVel();
	Vector3D<double> getPos();
	void setMass(double A);


private:

	Vector3D<double> pos,vel,acc;

	double massInKg;

	static long number;
	long index;

	static std::vector<Object*> AllObjects;

};

#endif /* OBJECT_H_ */
