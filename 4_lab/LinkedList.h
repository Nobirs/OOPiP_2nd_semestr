#pragma once
#include <iostream>
#include <fstream>

#include "Node.h"
#include "DDS.h"

using namespace std;


class List : public DDS {
private:
    Node* first;
    Node* last;
public:
    List();

    bool is_empty();
    void push_back(int _val);
    Node* find(int _val);
    void remove_first();
    void remove_last();
    void remove(int _val, ostream& err);

    void push(int _val) override { push_back(_val); }
    Node* pop() override;
    void print(ostream& os) override;
    Node* max() override;
    Node* min() override;
    void writeToFile(ofstream& of) override;

    Node* operator[](const int index);
};


