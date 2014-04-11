#include <cstdlib>
#include <iostream>

#include "Object.h"



int main(){

	Object A;

	A.setMass(1.0);

	A.force.x(1);

	A.PrintHeader();
	A.Print();

	for( int i = 0; i < 10; ++i){

		A.Update();
		A.Print();
	}



	return 0;
}

