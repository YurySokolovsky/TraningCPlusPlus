#pragma once

template <class T>
struct S
{
	T val;
	S(const T& val);
};

//Costructor
template <class T>
S<T>::S(const T& val) : val(val) {};