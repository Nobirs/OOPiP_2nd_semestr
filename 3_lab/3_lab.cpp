#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <time.h>


using namespace std;



#include "CurrentTime.h"
#include "Check.h"
#include "TotalCheck.h"
#include "Department.h"
#include "Product.h"
#include "StoreBasket.h"


Department department;
vector<TotalCheck*> allChecks;


void menuInCatalog(StoreBasket* basket);


TotalCheck* getMax() {
	TotalCheck* maxCheck = nullptr;
	if (allChecks.size() == 0) return maxCheck;
	else {
		maxCheck = allChecks[0];
	}
	for (auto ch : allChecks) {
		if (ch->getEndPrice() > maxCheck->getEndPrice())
		{
			maxCheck = ch;
		}
	}
	return maxCheck;
}


void writeMaxCheck() {
	ofstream outMax;
	outMax.open("MaxCheck.txt");
	if (outMax.is_open()) {
		outMax << *getMax();
		outMax.close();
	}
	return;
}


void writeCheckToFile(TotalCheck* ch) {
	ofstream outChecks;
	outChecks.open("AllChecks.txt", ios::app);
	if (outChecks.is_open()) {
		outChecks << *ch;
		outChecks.close();
	}
	return;
}



void fillDepartment() {
	Product* p = new Product("clip"s, ProductTypes::PaperClips, Countries::Canada, rand(), 1.99);
	department.addProduct(p, 100);
	p = new Product("paper"s, ProductTypes::Paper, Countries::Canada, rand(), 3.99);
	department.addProduct(p, 100);
	p = new Product("clamp"s, ProductTypes::PaperClips, Countries::Canada, rand(), 0.99);
	department.addProduct(p, 100);
	p = new Product("pen"s, ProductTypes::Paints, Countries::Canada, rand(), 1.99);
	department.addProduct(p, 100);
	p = new Product("eraser"s, ProductTypes::Other, Countries::Canada, rand(), 1.99);
	department.addProduct(p, 100);
}


void printCatalog() {
	cout << "������� ������ ����������:" << endl;
	for (auto t : *(department.getProducts()))
	{
		cout << get<Product*>(t)->getName() << "  ";
		cout << "��������: " << get<uint32_t>(t) << "  ";
		cout << "���� �� ����: " << get<Product*>(t)->getPrice();
		cout << endl;
	}
	cout << "------------------------------------------------------" << endl;
}



//-------------------------------------


void mainMenu() {
	StoreBasket* basket = new StoreBasket();
	int choice = 0;
	while (choice > 5 or choice < 1) {
		cout << endl;
		cout << BREAK_LINE;
		cout << "������ �� �������� ����������:" << endl;
		cout << "1.���������� ������� �������" << endl;
		cout << "2.���� ������� ��� ���(��� �� ����?)" << endl;
		cout << "3.����� ��� ���������� �� �������� ���!" << endl;
		cout << "4.� �������, ����!!!" << endl;
		cout << "5.�� ���, � �����..." << endl;
		cout << ">>>>";
		cin >> choice;
		cout << BREAK_LINE;
		switch (choice)
		{
		case 1:
			printCatalog();
			menuInCatalog(basket);
			break;
		case 2:
			cout << *(basket->getTotalCheck());
			break;
		case 3:
		{
			TotalCheck* maxCheck = getMax();
			if (maxCheck != nullptr) {
				cout << BREAK_LINE;
				cout << "����� <�����> ������ �� �������:";
				cout << BREAK_LINE;
				cout << *maxCheck;
				cout << BREAK_LINE;
				writeMaxCheck();
			}
			else cout << "� ��� �� ���� ��� �����������....." << endl;
			break;
		}
		case 4:
		{
			cout << *(basket->getTotalCheck());
			allChecks.push_back(basket->getTotalCheck());
			writeCheckToFile(basket->getTotalCheck());
			cout << "�� ��������, ��������� �� ����������(^_^)" << endl;
			basket = new StoreBasket();
			break;
		}
		case 5:
			cout << "��������� ����� ������ ��������(^_^)";
			return;
		}
		choice = 0;
	}
}

void menuInCatalog(StoreBasket* basket) {
	int choice = 0;
	while (choice > 3 or choice < 1) {
		cout << BREAK_LINE;
		cout << "���� ��������:" << endl;
		cout << "1.������ �����-������ ����� � �������..." << endl;
		cout << "2.������� ���������� �����" << endl;
		cout << "3.����� � ����" << endl;
		cout << ">>>>";
		cin >> choice;
		cout << BREAK_LINE;
		switch (choice)
		{
		case 1:
		{
			tuple<Product*, uint32_t> t = department.getProducts()->at(rand() % department.getSize());
			uint32_t overallCount = get<uint32_t>(t);
			uint32_t count = rand() % overallCount;
			Product* p = get<Product*>(t);
			basket->addProduct(p, count);
			department.getProduct(p->getName(), count);
			break;
		}
		case 2:
		{
			string name;
			uint32_t count;
			cout << "���� ����? ";
			cin >> name;
			cout << "�� � �������? ";
			cin >> count;
			tuple<Product*, uint32_t> t = department.getProduct(name, count);
			if (get<uint32_t>(t) != 0) basket->addProduct(get<Product*>(t), get<uint32_t>(t));
			break;
		}
		case 3:
			return;
		}
		choice = 0;
	}
}



int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << getCurrLocalDate() << endl;
	cout << getCurrLocalTime() << endl;



	fillDepartment();
	mainMenu();

	return 0;
}