#include <math.h>

#ifndef VECTORSPHERE_H_
#define VECTORSPHERE_H_

template <class T>
class VectorSphere {
public:
	VectorSphere();
	VectorSphere(T,T,T);
	T operator*(const T &other);
	VectorSphere<T> operator-(const T &other);
	void InCartesian(T &x, T &y, T &z);
	inline T length();
private:
	T R;
	T Theta;
	T Phi;
};

template<class T>
VectorSphere<T>::VectorSphere(){
	R = 0;
	Theta = 0;
	Phi = 0;
}

template <class T>
VectorSphere<T>::VectorSphere(T RIn,T ThetaIn,T PhiIn): R(RIn),Theta(ThetaIn),Phi(PhiIn){

}

template<class T>
T VectorSphere<T>::operator*(const T & other){
	return other.R*R + other.Theta*Theta + other.Phi*Phi;
}

template<class T>
VectorSphere<T> VectorSphere<T>::operator-(const T &other){
	VectorSphere<T> result;
	result.R = R - other.R;
	result.Theta = Theta - other.Theta;
	result.Phi = Phi - other.Phi;
	return result;
}

template<class T>
inline T VectorSphere<T>::length(){
	return R;
}

template<class T>
void VectorSphere<T>::InCartesian(T &x, T &y, T &z){
	x = R*sin(Theta)*cos(Phi);
	y = R*sin(Theta)*sin(Phi);
	z = R*cos(Theta);
}

#endif /* VECTORSPHERE_H_ */
