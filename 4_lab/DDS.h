#pragma once
#include <ostream>
#include <fstream>


#include "Node.h"

using std::ostream;
using std::ofstream;

class DDS {
public:
	virtual void push(int _val) = 0;
	virtual Node* pop() = 0;
	virtual void print(ostream& os) = 0;
	virtual Node* max() = 0;
	virtual Node* min() = 0;
	virtual void writeToFile(ofstream& of) = 0;

};