#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <time.h>

#include "Stack.h"
#include "LinkedList.h"


using namespace std;

void printStructs(Stack* stack, List* list) {
	cout << "Stack: ";
	stack->print(cout);
	cout << "List: ";
	list->print(cout);
}

int main() {
	srand(time(0));

	Stack* stack = new Stack();
	List* list = new List();
	for (int i = 0; i < 10; i++) {
		list->push(rand() % 20);
		stack->push(rand() % 20);
	}
	printStructs(stack, list);

	cout << "pop: " << endl;
	cout << *(stack->pop()) << endl;
	cout << *(list->pop()) << endl;
	printStructs(stack, list);

	cout << "max: " << endl;
	cout << *(stack->max()) << endl;
	cout << *(list->max()) << endl;
	printStructs(stack, list);

	cout << "min: " << endl;
	cout << *(stack->min()) << endl;
	cout << *(list->min()) << endl;
	printStructs(stack, list);

	ofstream of;
	stack->writeToFile(of);
	list->writeToFile(of);



	return 0;
}
