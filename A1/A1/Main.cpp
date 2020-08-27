#include "Main.h"
#include "templateQueue.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

void wrapper()
{
	queue<int> intQueue;
	queue<float> floatQueue;
	queue<char> charQueue;

	cout << "Int queue" << endl;

	intQueue.Push(5);
	intQueue.Push(7);
	intQueue.Push(15);
	intQueue.Push(21);
	intQueue.Push(-12);

	intQueue.Print();

	cout << "Popping some elements" << endl;
	intQueue.Pop();
	intQueue.Pop();

	intQueue.Print();
	cout << endl;

	cout << "Float queue" << endl;

	floatQueue.Push(.05);
	floatQueue.Push(7.54);
	floatQueue.Push(1.5);
	floatQueue.Push(21.25);
	floatQueue.Push(-9.76);
	
	floatQueue.Print();

	cout << "Popping some elements" << endl;
	floatQueue.Pop();
	floatQueue.Pop();

	floatQueue.Print();
	cout << endl;

	cout << "char queue" << endl;
	
	charQueue.Push('D');
	charQueue.Push('A');
	charQueue.Push('V');
	charQueue.Push('I');
	charQueue.Push('R');
	
	charQueue.Print();
	
	cout << "Popping some elements" << endl;
	charQueue.Pop();
	charQueue.Pop();
	
	charQueue.Print();
	cout << endl;

	queue<int> copyQueue = intQueue;

	cout << "Copy Constructor queue" << endl;
	copyQueue.Print();
	cout << "Final Pops" << endl;
	copyQueue.Pop();
	copyQueue.Print();
	cout << "Setting the copied queue equal to the original" << endl;
	copyQueue = intQueue;
	copyQueue.Print();
}

int main()
{
	wrapper();

	_CrtDumpMemoryLeaks();
}
