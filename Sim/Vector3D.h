#include <math.h>

#ifndef VECTOR3D_H_
#define VECTOR3D_H_

template <class T>
class Vector3D {
public:
	Vector3D();
	Vector3D(T,T,T);
	T operator*(const T &other);
	Vector3D<T> operator-(const T &other);
	void InSpherical(T &R, T &Theta, T &Phi);
	inline T length();
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

template<class T>
Vector3D<T> Vector3D<T>::operator-(const T &other){
	Vector3D<T> result;
	result.x = x - other.x;
	result.y = y - other.y;
	result.z = z - other.z;
	return result;
}

template<class T>
inline T Vector3D<T>::length(){
	return pow(pow(x,2) + pow(y,2) + pow(z,2),0.5);
}

template<class T>
void Vector3D<T>::InSpherical(T &R, T &Theta, T &Phi){
	R = pow(pow(x,2) + pow(y,2) + pow(z,2),0.5);
	Theta = acos(z/R);
	Phi = atan(y/x);
}


#endif /* VECTOR3D_H_ */
