#pragma once

#include <memory>
#include "Queue.h"

class InsertValues
{
	private:
		std::unique_ptr <Queue<int>> queue;

	public:
		void printMenu();
		void selectAction();
		void createQueue();
		void addValues();
		void deleteValues();
		void printQueue();
		void confirmationOfWorkContinue();
		int readIntValue();
};

