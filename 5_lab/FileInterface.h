#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::ofstream;
using std::string;
using std::ios;

class FileInterface {
private:
	string filePath;
protected:
	bool isOpen;
	ofstream out;
public:
	FileInterface() {
		filePath = "default.txt";
		out.open(filePath, ios::app);
		isOpen = out.is_open();
	}
	FileInterface(string filePath) {
		this->filePath = filePath;
		this->out.open(this->filePath, ios::app);
		this->isOpen = out.is_open();
	}
	~FileInterface() {
		this->out.close();
	}
	void openFile() {
		if (!isOpen) {
			out.open(filePath, ios::app);
			isOpen = true;
		}
	}
	void closeFile() {
		if (isOpen) {
			out.close();
			isOpen = false;
		}
	}
	virtual int writeToFile() = 0;
};