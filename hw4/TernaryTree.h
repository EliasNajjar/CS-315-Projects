#include <iostream>

using namespace std;

class Node {
friend class TernaryTree;
public:
    void print() const;
private:
    int num1;
    int num2 = -1;
    Node* left = nullptr;
    Node* middle = nullptr;
    Node* right = nullptr;
};

class TernaryTree {
public:
    void insert(int num);
    bool search(int num) const;
    void print() const;
private:
    Node* root = nullptr;
};