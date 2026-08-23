#include "TernaryTree.h"

void TernaryTree::insert(int num) {
    Node* trav = root;
    Node* parent = nullptr; // for adding new node

    while (trav != nullptr && trav->num2 != -1) { // end if no node or only 1 value
        parent = trav;
        if (num <= trav->num1) {
            trav = trav->left;
        }
        else if (num <= trav->num2) {
            trav = trav->middle;
        }
        else {
            trav = trav->right;
        }
    }

    if (trav == nullptr) { // create new node, make parent point to it in the correct subtree
        trav = new Node();
        trav->num1 = num;

        if (parent == nullptr) { // empty tree
            root = trav;
        }
        else if (num <= parent->num1) {
            parent->left = trav;
        }
        else if (num <= parent->num2) {
            parent->middle = trav;
        }
        else {
            parent->right = trav;
        }
    }
    else if (num < trav->num1) { // num is less than num1, make num1 num2 and num the new num1
        trav->num2 = trav->num1;
        trav->num1 = num;
    }
    else {
        trav->num2 = num;
    }
}

bool TernaryTree::search(int num) const {
    Node* trav = root;

    while (trav != nullptr) {
        if (num == trav->num1 || num == trav->num2) { // found if equal to num1 or num2
            return true;
        }

        if (num <= trav->num1) { // traverse correct subtree
            trav = trav->left;
        }
        else if (num <= trav->num2) {
            trav = trav->middle;
        }
        else {
            trav = trav->right;
        }
    }

    return false;
}

void TernaryTree::print() const {
    if (root != nullptr) {
        root->print();
    }
    cout << endl;
}

void Node::print() const { // print subtree/value if it exists
    if (left != nullptr) {
        cout << "(";
        left->print();
        cout << ") ";
    }
    cout << num1;
    if (middle != nullptr) {
        cout << " (";
        middle->print();
        cout << ")";
    }
    if (num2 != -1) {
        cout << " " << num2;
    }
    if (right != nullptr) {
        cout << " (";
        right->print();
        cout << ")";
    }
}