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

	double getMassInKg() const {
		return massInKg;
	}

	void setMassInKg(double massInKg) {
		this->massInKg = massInKg;
	}

	static std::vector<Object*>& getAllObjects(){
		return AllObjects;
	}

	static long getNumber(){
		return number;
	}

	const Vector3D<double>& getAcc() const {
		return acc;
	}

	void setAcc(const Vector3D<double>& acc) {
		this->acc = acc;
	}

	const Vector3D<double>& getPos() const {
		return pos;
	}

	void setPos(const Vector3D<double>& pos) {
		this->pos = pos;
	}

	const Vector3D<double>& getVel() const {
		return vel;
	}

	void setVel(const Vector3D<double>& vel) {
		this->vel = vel;
	}

private:

	Vector3D<double> pos,vel,acc;
	double massInKg;

	static long number;
	long index;

	static std::vector<Object*> AllObjects;

};

#endif /* OBJECT_H_ */
