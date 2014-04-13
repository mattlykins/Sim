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

	Vector3D<double> CalcGravity(Object &A);
	void GetNetForce();

	void UpdateAcc();
	void UpdateVel();
	void UpdatePos();

	void ZeroForce();


	Vector3D<double> getForce();
	Vector3D<double> getAcc();
	Vector3D<double>& getVel();
	Vector3D<double>& getPos();



	void setMass(double A);

	void Update();
	void Print();
	void PrintHeader();


private:

	Vector3D<double> pos,vel,acc,force;

	double massInKg;

	static long number;
	static double time;
	long index;

	static std::vector<Object*> AllObjects;
};

#endif /* OBJECT_H_ */
