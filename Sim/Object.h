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


private:

	Vector3D<double> pos,vel,acc;
	double massInKg;

	static long number;
	long index;

	static std::vector<Object*> AllObjects;

};

#endif /* OBJECT_H_ */
