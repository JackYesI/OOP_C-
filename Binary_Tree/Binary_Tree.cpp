#include <iostream>
#include "BTree.h"
using namespace std;

int main()
{
    Binary<int> tree;
    tree.add(10);
    tree.add(2);
    tree.add(3);
    tree.add(4);
    tree.add(-1);
    tree.add(8);
    tree.add(-12);
    tree.add(11);
    tree.print();
    cout << "Size :: " << tree.getSize() << endl;

    /*tree.clear();
    tree.print();
    cout << "Size :: " << tree.getSize() << endl;*/

    cout << tree.min() << endl;
    tree.popMin();
    cout << tree.min() << endl;
    tree.popMin();
    cout << tree.min() << endl;
    tree.print();
    cout << tree.max() << endl;
    tree.popMax();
    cout << tree.max() << endl;
    tree.popMax();
    cout << tree.max() << endl;

    tree.print();
    cout << "Size :: " << tree.getSize() << endl;

    tree.clearRecursia();
    tree.print();
    cout << "Size :: " << tree.getSize() << endl;

    tree.add(10);
    tree.add(2);
    tree.add(3);
    tree.add(4);
    tree.add(-1);
    tree.add(8);
    tree.add(-12);
    tree.add(11);

    cout << "----------------------" << endl;
    tree.print();
    cout << "Size :: " << tree.getSize() << endl;
    Node<int>* del = tree.getNode(2);


    /*tree.popNode(del);
    tree.print();
    cout << "Size :: " << tree.getSize() << endl;*/

    tree.findDataDiapazon(3, 10);

    tree.clearRecursia();

}


