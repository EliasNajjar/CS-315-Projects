#include "TernaryTree.h"

int main() {
    TernaryTree tree;

    cout << "Enter a sequence of integers to put into the tree, -1 to stop:" << endl;
    int num = 0;
    cin >> num;
    while (num != -1) {
        tree.insert(num);
        cin >> num;
    }

    tree.print();
    cout << endl;

    cout << "Enter a value to search for:" << endl;
    cin >> num;
    tree.search(num) ? cout << "found" : cout << "not found";
    cout << endl;

    return 0;
}