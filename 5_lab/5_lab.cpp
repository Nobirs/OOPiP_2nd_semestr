#include <iostream>
#include <fstream>

#include "Product.h"
#include "Movie.h"
#include "Book.h"
#include "FileInterface.h"


using namespace std;

int main() {
	Book* books = new Book[10];

	Movie* movies = new Movie[10];

	for (int i = 0; i < 10; i++) {
		//books[i].writeToFile();
	}
	for (int i = 0; i < 10; i++) {
		movies[i].writeToFile();
	}

	Product* prods = new Product[10];
	for (int i = 0; i < 10; i++) {
		prods[i].printDescription();
	}

	FileInterface* ptr;
	for (int i = 0; i < 10; i++) {
		ptr = &books[i];
		ptr->writeToFile();
	}
}