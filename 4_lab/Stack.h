#pragma once
#include "DDS.h"
#include "Node.h"


class Stack : public DDS
{
private:
	int length;
	Node* first;
public:
	Stack();
	~Stack();

	void push(int _val) override;
	Node* pop() override;
	void print(ostream& os) override;
	void writeToFile(ofstream& of) override;
	int clear();
	int* toArray();
	int getLength();

	void sortByPointers();
	void sortByValues();

	Node* min();
	Node* max();
	void swapValues(Node* a, Node* b);
};

