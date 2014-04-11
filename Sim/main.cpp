#include <cstdlib>
#include <iostream>

#include "Object.h"



int main(){

	Object A;
	Object B;

	A.setMass(1.0);
	A.getVel().x(0.5);
	B.setMass(1.0);

	B.getPos().x(5);

	B.getVel().y(0.25);




	A.PrintHeader();
	A.Print();
	B.Print();

	for( int i = 0; i < 10; ++i){

		A.CalcGravity(B);
		B.CalcGravity(A);
		A.Update();
		B.Update();
		A.Print();
		B.Print();
	}



	return 0;
}

