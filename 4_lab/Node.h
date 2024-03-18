#pragma once
#include <ostream>

using std::ostream;

struct Node {
    int val;
    Node* next;

    Node(int _val) {
        val = _val;
        next = nullptr;
    }
    friend ostream& operator<<(ostream& os, Node& node) {
        os << node.val << " ";
        return os;
    }
};