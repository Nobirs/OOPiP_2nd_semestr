#include "Stack.h"


Stack::Stack() {
	length = 0;
	first = nullptr;
}


Stack::~Stack() {
	clear();
}


void Stack::push(int _val) {
	Node* elem = new Node(0);
	elem->val = _val;
	elem->next = first;
	first = elem;
	length++;
}


Node* Stack::pop() {
	Node* value = first;
	Node* elem = first;
	first = first->next;
	length--;
	return value;
}


int Stack::clear() {
	while (first != nullptr) {
		Node* current = first;
		first = first->next;
		delete current;
	}
	length = 0;
	return 0;
}


int* Stack::toArray() {
	int* arr = new int[length];
	Node* ptr = first;
	for (int i = 0; i < length; i++, ptr = ptr->next) {
		arr[i] = ptr->val;
	}
	return arr;
}


int Stack::getLength() {
	return length;
}

void Stack::sortByPointers() {
	push(0);
	Node* t = nullptr, * t1, * r;
	if (first->next->next == nullptr) return;
	do {
		for (t1 = first; t1->next->next != t; t1 = t1->next)
			if (t1->next->val > t1->next->next->val) {
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		t = t1->next;
	} while (first->next->next != t);
	pop();
}


void Stack::sortByValues() {
	Node* t = nullptr, * t1;
	int r;
	do {
		for (t1 = first; t1->next != t; t1 = t1->next)
			if (t1->val > t1->next->val) {
				r = t1->val;
				t1->val = t1->next->val;
				t1->next->val = r;
			}
		t = t1;
	} while (first->next != t);
}

Node* Stack::min()
{
	if (length == 0) return nullptr;
	Node* current = first;
	Node* result = first;
	while (current != nullptr) {
		if (current->val < result->val) result = current;
		current = current->next;
	}
	return result;
}

Node* Stack::max()
{
	if (length == 0) return nullptr;
	Node* current = first;
	Node* result = first;
	while (current != nullptr) {
		if (current->val >= result->val) result = current;
		current = current->next;
	}
	return result;
}

void Stack::swapValues(Node* a, Node* b)
{
	if (a != nullptr and b != nullptr) {
		int temp = a->val;
		a->val = b->val;
		b->val = temp;
	}
}


void Stack::print(ostream& os)
{
	Node* p = first;
	os << "\n---------------------------------\n";
	while (p != nullptr) {
		os << p->val << " ";
		p = p->next;
	}
	os << "\n---------------------------------\n";
}

void Stack::writeToFile(ofstream& of)
{
	if (length == 0) return;
	of.open("Stack.txt");
	if (of.is_open()) {
		Node* p = first;
		of << "\n---------------------------------\n";
		while (p != nullptr) {
			of << p->val << " ";
			p = p->next;
		}
		of << "\n---------------------------------\n";
	}
	of.close();
}