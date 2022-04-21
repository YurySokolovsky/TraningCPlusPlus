#pragma once
#include <iostream>
#include <exception>

template<class T>
class Vector
{
private:
	int vSize;
	int vCapacity;
	T* elements;
	void addMemory();
public:
	Vector();
	Vector(int s);
	Vector(const Vector& other);
	Vector(Vector&& other) noexcept;
	~Vector();
	int size() const;
	int capacity() const;
	bool empty();
	void push_back(const T& value);
	void pop_back();
	void insert(const int index, const T& value);
	void remove(const int index);
	void clear();
	T* begin();
	const T* begin() const;
	T* end();
	const T* end() const;
	T& operator[](const int index);
	const T& operator[](const int index) const;
	Vector<T>& operator=(Vector<T>& other);
	Vector<T>& operator=(Vector<T>&& other) noexcept;
 };

//Default constructor
template<class T>
Vector<T>::Vector() :vSize(0), elements(new T[4]), vCapacity(4)
{
	std::cout << "Default Vector constructor" << std::endl;
}

//Vector with capacity constructor 
template<class T>
Vector<T>::Vector(int s) : vSize(0), elements(new T[s]), vCapacity(s)
{
	std::cout << "Vector constructor, capacity = " << s << std::endl;
}

//Destructor
template<class T>
Vector<T>::~Vector()
{
	std::cout << "Vector destructor" << std::endl;
	delete[] elements;
}

//Copy constructor
template<class T>
Vector<T>::Vector(const Vector& other):elements(new T[other.vCapacity]), vSize(other.vSize), vCapacity(other.vCapacity)
{
	std::cout << "Copy constructor" << std::endl;

    for (int i = 0; i < other.vSize; ++i)
	{
		elements[i] = other.elements[i];
	}
}

//Moving constructor
template<class T>
Vector<T>::Vector(Vector<T>&& other) noexcept: elements(other.elements), vSize(other.vSize), vCapacity(other.vCapacity)
{
	std::cout << "Moving constructor" << std::endl;
	other.elements = nullptr;
	other.vSize = 0;
	other.vCapacity = 0;
}

//Return vector size
template<class T>
int Vector<T>::size() const
{
	return vSize;
}

//Return vector capacity
template<class T>
int Vector<T>::capacity() const
{
	return vCapacity;
}

//Return is vector empty
template<class T>
bool Vector<T>::empty()
{
	return vSize == 0;
}

//Increase vector size method
template<class T>
void Vector<T>::addMemory()
{
	vCapacity *= 2;
	T* tmp = elements;
	elements = new T[vCapacity];

	for (int i = 0; i < vSize; ++i) {
		elements[i] = tmp[i];
	}

	delete[] tmp;
}

//Add new (last) element to vector
template<class T>
void Vector<T>::push_back(const T& value)
{
	if (vSize >= vCapacity) {
		addMemory();
	}

	elements[vSize++] = value;
}

//Delete last element from vector
template<class T>
void Vector<T>::pop_back()
{
	if (vSize != 0) {
		elements[vSize--] = 0;
	}
}

//Insert element into vector
template<class T>
void Vector<T>::insert(const int index, const T& value)
{
	if (index > vSize - 1) {
		throw std::out_of_range("Index out of range");
	}

	++vSize;

	if (vSize >= vCapacity) {
		addMemory();
	}

	for (int i = vSize; i > index; i--) {
		elements[i] = elements[i - 1];
	}

	elements[index] = value;
}


template<class T>
void Vector<T>::remove(int index)
{
	if (index > vSize - 1) {
		throw std::out_of_range("Index out of range");
	}

	for (int i = index + 1; i < vSize; ++i) {
		elements[i - 1] = elements[i];
	}

	--vSize;
}

template<class T>
void Vector<T>::clear()
{
	for (int i = vSize - 1; i >= 0; i--)
	{
		elements[i] = 0;
		--vSize;
	}
}

//Iterator begin
template<class T>
T* Vector<T>::begin()
{
	return &elements[0];
}

//Constant iterator begin
template<class T>
const T* Vector<T>::begin() const
{
	return &elements[0];
}

//Iterator end
template<class T>
T* Vector<T>::end()
{
	return &elements[vSize];
}

//Constant iterator end
template<class T>
const T* Vector<T>::end() const
{
	return &elements[vSize];
}

//Return element by index (operator [])
template<class T>
T& Vector<T>::operator[](int index)
{
	if (index > vSize - 1) {
		throw std::out_of_range("Index out of range");
	}

	return elements[index];
}

//Return element by index (const operator[])
template<class T>
const T& Vector<T>::operator[](int index) const
{
	if (index > vSize - 1) {
		throw std::out_of_range("Index out of range!!!");
	}

	return elements[index];
}

//Copy operator
template<class T>
Vector<T>& Vector<T>::operator=(Vector& other)
{
	std::cout << "Copy operator=()" << std::endl;

	if (this != &other) {
		vSize = other.vSize;
		vCapacity = other.vCapacity;
		elements = new T[other.vCapacity];
		for (int i = 0; i < vSize; i++)
		{
			elements[i] = other.elements[i];
		}

		////Another implementation of operator logic
		//Vector<T> tmp(other);
		//std::swap(elements, tmp.elements);
		//std::swap(vSize, tmp.vSize);
		//std::swap(vCapacity, tmp.vCapacity);
	}

	return *this;
}

//Copy operator with moving semntic
template<class T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept
{
	std::cout << "Copy moving operator=()" << std::endl;

	if (this != &other) {
		vSize = other.vSize;
		vCapacity = other.vCapacity;
		elements = other.elements;
		other.elements = nullptr;
		other.vCapacity = 0;
		other.vSize = 0;

		////Another implementation of operator logic
		//std::swap(elements, other.elements);
		//std::swap(vSize, other.vSize);
		//std::swap(vCapacity, other.vCapacity);
		//other.elements = nullptr;
	}

	return *this;
}

//Put vector to ostream
//The "friend" function is not used in the declaration in the class
//because access to private members of the class Vector is not used
template<class T>
std::ostream& operator<<(std::ostream & os, const Vector<T>&vec)
{
	for (int i = 0; i < vec.size(); i++)
	os << vec[i] << " ";
	return os;
}