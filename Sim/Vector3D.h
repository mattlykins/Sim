#include <math.h>

#ifndef VECTOR3D_H_
#define VECTOR3D_H_

template <class T>
class Vector3D {
public:
	Vector3D();
	Vector3D(T,T,T);
	Vector3D<T> operator-(const Vector3D<T> &other);
	Vector3D<T> operator+(const Vector3D<T> &other);
	Vector3D<T> operator*(const T &A);
	Vector3D<T> operator/(const T &A);
	void InSpherical(T &R, T &Theta, T &Phi);
	inline T length();

	T x();
	void x(const T &A);
	T y();
	void y(const T &A);
	T z();
	void z(const T &A);
private:
	T xVar;
	T yVar;
	T zVar;
};

template<class T>
T Vector3D<T>::x(){
	return xVar;
}

template<class T>
void Vector3D<T>::x(const T &A){
	this->xVar = A;
}

template<class T>
void Vector3D<T>::y(const T &A){
	this->yVar = A;
}

template<class T>
void Vector3D<T>::z(const T &A){
	this->zVar = A;
}

template<class T>
T Vector3D<T>::y(){
	return yVar;
}

template<class T>
T Vector3D<T>::z(){
	return zVar;
}

template<class T>
Vector3D<T>::Vector3D(){
	xVar = 0;
	yVar = 0;
	zVar = 0;
}

template <class T>
Vector3D<T>::Vector3D(T xIn,T yIn,T zIn): xVar(xIn),yVar(yIn),zVar(zIn){
}

template<class T>
Vector3D<T> Vector3D<T>::operator-(const Vector3D<T> &other){
	Vector3D<T> result;
	result.xVar = xVar - other.xVar;
	result.yVar = yVar - other.yVar;
	result.zVar = zVar - other.zVar;
	return result;
}

template<class T>
Vector3D<T> Vector3D<T>::operator+(const Vector3D<T> &other){
	Vector3D<T> result;
	result.xVar = xVar + other.xVar;
	result.yVar = yVar + other.yVar;
	result.zVar = zVar + other.zVar;
	return result;
}

template<class T>
Vector3D<T> Vector3D<T>::operator*(const T &A){
	Vector3D<T> result;
	result.xVar = this->xVar * A;
	result.yVar = this->yVar * A;
	result.zVar = this->zVar * A;
	return result;
}

template<class T>
Vector3D<T> Vector3D<T>::operator/(const T &A){
	Vector3D<T> result;

	//Check if A != 0
	result.xVar = this->xVar / A;
	result.yVar = this->yVar / A;
	result.zVar = this->zVar / A;
	return result;
}

template<class T>
inline T Vector3D<T>::length(){
	return pow(pow(xVar,2) + pow(yVar,2) + pow(zVar,2),0.5);
}

template<class T>
void Vector3D<T>::InSpherical(T &R, T &Theta, T &Phi){
	R = pow(pow(xVar,2) + pow(yVar,2) + pow(zVar,2),0.5);
	Theta = atan2(pow(pow(xVar,2) + pow(yVar,2),0.5),zVar);
	Phi = atan(yVar/xVar);
}


#endif /* VECTOR3D_H_ */
