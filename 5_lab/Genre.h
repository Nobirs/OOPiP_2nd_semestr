#pragma once
#include <iostream>
#include <string>

using std::string;

class Genre {
protected:
	string genre;

public:
	Genre() : genre("default") {}
	Genre(string _genre) : genre(_genre) {}
	~Genre() {}

	string getGenre() {
		return genre;
	}

	void setGenre(const string& _genre) { 
		genre = _genre; 
	}
};