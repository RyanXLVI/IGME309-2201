#pragma once
#include <iostream>

using namespace std;

template<class Placeholder>
class queue
{
public:
	queue()
	{
		arraySize = 1;
		numItems = 0;
		top = -1;
		dataArray = new Placeholder[arraySize];
	};

	queue(const queue& other)
	{
		arraySize = other.arraySize;
		dataArray = new Placeholder[arraySize];
		numItems = other.numItems;
		top = other.top;

		copy(other.dataArray, other.dataArray + other.numItems, dataArray);
	};

	queue& operator=(const queue& other)
	{
		if (this == &other)
		{
			return *this;
		}

		if (dataArray != nullptr)
		{
			delete[] dataArray;
			dataArray = nullptr;
			arraySize = 0;
		}

		arraySize = other.arraySize;
		dataArray = new Placeholder[arraySize];
		numItems = other.numItems;
		top = other.top;

		copy(other.dataArray, other.dataArray + other.numItems, dataArray);

		return *this;
	};

	~queue()
	{
		delete[] dataArray;
		dataArray = nullptr;
		arraySize = 0;
	};

	void Push(Placeholder data)
	{
		numItems++;

		if (numItems > arraySize)
		{
			arraySize *= 2;
			Placeholder* tempArray = dataArray;
			dataArray = new Placeholder[arraySize];

			copy(tempArray, tempArray + arraySize / 2, dataArray);

			delete[] tempArray;
			tempArray = nullptr;
		}

		top++;
		dataArray[top] = data;

		sortQueue();
	};

	Placeholder Pop()
	{
		if (numItems <= 0)
		{
			return NULL;
		}

		Placeholder popData = dataArray[top];
		dataArray[top] = NULL;
		top--;
		numItems--;

		return popData;
	};

	void Print()
	{
		for (int i = 0; i < GetSize(); i++)
		{
			cout << dataArray[i] << " ";
		}
		cout << endl;
	};

	int GetSize()
	{
		return numItems;
	};

	bool isEmpty()
	{
		if (numItems <= 0)
		{
			return true;
		}

		return false;
	};

	void sortQueue()
	{
		for (int i = 0; i < numItems - 1; i++)
		{
			Placeholder key = dataArray[i];
			
			for (int j = i + 1; j < numItems; j++)
			{
				if (dataArray[j] < key)
				{
					Placeholder temp = key;
					key = dataArray[j];
					dataArray[i] = key;
					dataArray[j] = temp;
				}
				
			}
		}
	}

private:
	int arraySize;
	int numItems;
	int top;
	Placeholder* dataArray;
};

;