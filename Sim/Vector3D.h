/*
 * Vector3D.h
 *
 *  Created on: Apr 8, 2014
 *      Author: Maxwell
 */

#ifndef VECTOR3D_H_
#define VECTOR3D_H_
template <class T>
class Vector3D {
public:
	Vector3D();
	Vector3D(T,T,T);
	T operator*(const T &other);
private:
	T x;
	T y;
	T z;
};

template<class T>
Vector3D<T>::Vector3D(){
	x = 0;
	y = 0;
	z = 0;
}

template <class T>
Vector3D<T>::Vector3D(T xIn,T yIn,T zIn): x(xIn),y(yIn),z(zIn){

}

template<class T>
T Vector3D<T>::operator*(const T & other){
	return other.x*x + other.y*y + other.z*z;
}

#endif /* VECTOR3D_H_ */
