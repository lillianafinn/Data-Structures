#include <iostream>
using namespace std;

#include "bst.h"

int main(int argc, char *argv[]) {
    bst<int> T;

    int key;
    while (cin >> key) {
        T.insert(key);
    }

    cout << "BINARY TREE" << endl;

    cout << "num_nodes  =" << T.num_nodes() << endl;
    cout << "num_leaves =" << T.num_leaves() << endl;
    cout << "num_nodes  =" << T.height() << endl;


    cout << '\n' << "in-order" << endl;
    T.print_inorder();

    cout << '\n' << "level-order" << endl;
    T.print_levelorder();

    T.clear();
}