#pragma once
#include <typeinfo>

template <class T>
struct S1
{
	private:
		T val;

	public:
		S1();
		T& get();
		void set(const T& value);
		void read_val();
};

//Costructor
template <class T>
S1<T>::S1(){};

//Getter
template <class T>
T& S1<T>::get()
{
	return val;
}

//Setter
template <class T>
void S1<T>::set(const T& value)
{
	val = value;
}

//Function read values from std::cin 
template<class T> 
void S1<T>::read_val()
{
	std::cout << "\nInput variable type of " << typeid(val).name() << ": ";
	std::cin >> val;
}


