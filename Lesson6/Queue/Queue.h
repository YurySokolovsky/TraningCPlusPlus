#pragma once

#include <iostream>

template <class T>
class Queue
{
	private:
		const int size;
		int lenght;
		T* queuePtr;

	public:
		Queue(const int size);
		~Queue();
		void push(const T& value);
		void pop();
		T front();
		T back();
		bool empty();
		void print();
};

template <class T>
Queue<T>::Queue(const int size) : size(size), lenght(0)
{
	if (size <= 0) {
		throw "Size cant't be less then 1!";
	}

	queuePtr = new T[size];
}

template <class T>
Queue<T>::~Queue()
{
	delete queuePtr;
}

//Add element to queue
template <class T>
void Queue<T>::push(const T& value)
{
	if (size <= lenght)
	{
		throw "Element didn't add. Maximum queue size reached!";
	}

	queuePtr[lenght] = value;
	lenght++;
}

//Delete element from queue
template <class T>
void Queue<T>::pop()
{
	if (lenght == 0) {
		throw "Queue is empty. Deleting isn't impossible!";
	}

	for (int i = 0; i < lenght-1; i++)
	{
		queuePtr[i] = queuePtr[i + 1];
	}

	queuePtr[lenght - 1] = 0;
	lenght--;
}

//Return first element
template <class T>
T Queue<T>::front()
{
	return queuePtr[0];
}

//Return last element
template <class T>
T Queue<T>::back()
{
	return queuePtr[lenght-1];
}

//Check queue is empty
template <class T>
bool Queue<T>::empty()
{
	return lenght > 0;
}

//Print queue
template <class T>
void Queue<T>::print()
{
	if (lenght != 0) {
		std::cout << "Queue values: ";

		for (int i = 0; i < lenght; i++)
		{
			std::cout << queuePtr[i] << " ";
		}
	}
	else {
		std::cout << "Queue is empty!";
	}

	std::cout << std::endl;
}
