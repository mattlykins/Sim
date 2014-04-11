#include <cstdlib>
#include <iostream>

#include "Object.h"



int main(){

	Object A;

	A.setMass(1.0);

	A.force.x(1);

	for( int i = 0; i < 10; ++i){
		A.UpdateAcc();
		A.UpdateVel();
		A.UpdatePos();

		std::cout << "Force: " << A.force.x() << std::endl;
		std::cout << "ACC: " << A.getAcc().x() << std::endl;
		std::cout << "VEL: " << A.getVel().x() << std::endl;
		std::cout << "POS: " << A.getPos().x() << std::endl;//"\t" << A.pos.y() << "\t" << A.pos.z() << std::endl;
	}



	return 0;
}

