#pragma once

template <class T>
struct S2
{
private:
	T* arrayPtr;
	const int size;

public:
	S2(const int = 10);
	S2(const int size, const int val);
	~S2();
	T& operator[](int i);
	const T& operator[](int i) const;
};

//First costructor
template <class T>
S2<T>::S2(const int arraySize):size(arraySize)
{
	arrayPtr = new T[size];
}

//Second constructor
template <class T>
S2<T>::S2(const int arraySize, const int val) :size(arraySize)
{
	arrayPtr = new T[size];
	for (int i = 0; i < size; i++)
		arrayPtr[i] = val;
}

//Destructor
template <class T>
S2<T>::~S2()
{
	delete[] arrayPtr;
}

//Non-constant version of operator[]
template <class T>
T& S2<T>::operator[](int i)
{
	return arrayPtr[i];
}

//Constant version of operator[]
template <class T>
const T& S2<T>::operator[](int i) const
{
	return arrayPtr[i];
}

