#include "ArrayList.hpp"
#include "AVLTree.hpp"
#include "BinaryTree.hpp"
#include "LinkedList.hpp"

void demonstrarion_mode() {
    cout<<"ARRAY LIST"<<endl;
    cout<<"using specific type DayTime";
    ArrayList<DateTime> journal;
    journal.create_empty();

    DateTime d1 = {2024, 5, 20, 10, 0};  //May
    DateTime d2 = {2024, 1, 15, 12, 30}; //January
    DateTime d3 = {2024, 12, 31, 23, 59}; //December
    DateTime d4 = {2024, 5, 20, 8, 15};  //May

    cout << "Adding dates" << endl;
    journal.add(d1);
    journal.add(d2);
    journal.add(d3);
    journal.add(d4);
    journal.print();

    cout << "Testing range: searching for dates in May" << endl;
    DateTime startMay = {2024, 5, 1, 0, 0};
    DateTime endMay   = {2024, 5, 31, 23, 59};
    pair<int, int> range = journal.range(startMay, endMay);
    if (range.first != -1) {
        cout << "Found entries from index " << range.first << " to " << range.second << ":" << endl;
        for (int i = range.first; i <= range.second; i++) {
            cout << "  [" << i << "] " << journal.data[i] << endl;
        }
    } else {
        cout << "No dates found in this range." << endl;
    }
    cout << "Applying +1 hour to all (Like switching from summer time to winter time)" << endl;
    journal.apply([](DateTime& dt) {
        dt.hour = (dt.hour + 1) % 24;
    });
    journal.print();
    cout<<endl;

    cout<<"LINKED LIST"<<endl;
    LinkedList<int> linkedList;
    linkedList.create_empty();
    for(int i = 60; i <= 100; i += 10) linkedList.add(i);
    linkedList.print();
    cout<<"Add 45"<<endl;
    linkedList.add(45);
    linkedList.print();
    cout<<"Pop 80"<<endl;
    linkedList.pop(80);
    linkedList.print();
    cout<<"Find range from 15 to 45 (only 45 should be found)"<<endl;
    pair<Node<int>*, Node<int>*> res2 = linkedList.range(15, 45);
    cout<<"Start element: "<<res2.first->data<<", ending element: "<<res2.second->data<<endl;
    cout<<"Multiply each value by 2"<<endl;
    linkedList.apply([](int& x) {x *= 2;});
    linkedList.print();
    cout<<endl;

    cout<<"BINARY TREE"<<endl;
    BinaryTree<int> binaryTree;
    binaryTree.create_empty();
    for(int i = 100; i <= 150; i += 10) binaryTree.add(i);
    binaryTree.print();
    cout<<"Add 145"<<endl;
    binaryTree.add(145);
    binaryTree.print();
    cout<<"Pop 100"<<endl;
    binaryTree.pop(100);
    binaryTree.print();
    cout<<"Find range from 105 to 135"<<endl;
    pair<BinNode<int>*, BinNode<int>*> res3 = binaryTree.range(105, 135);
    cout<<"Start element: "<<res3.first->data<<", ending element: "<<res3.second->data<<endl;
    cout<<"Multiply each value by 2"<<endl;
    binaryTree.apply([](int& x) {x *= 2;});
    binaryTree.print();
    binaryTree.show();
    cout<<endl;

    cout<<"AVL TREE"<<endl;
    AVLTree<int> avlTree;
    avlTree.create_empty();
    avlTree.add(10);
    avlTree.add(20);
    avlTree.add(30);
    cout<<"Root after adding 10, 20, 30: "<<avlTree.root->data<<" (Expected: 20)"<<endl;
    avlTree.show();
    avlTree.add(40);
    avlTree.add(50);
    avlTree.add(25);
    cout<<"Adding 40, 50, 25"<<endl;
    avlTree.show();
    cout<<"Tree height: "<< avlTree.root->h<<" (Expected for 6 elements: 3)"<<endl;
    avlTree.pop(20);
    cout<<"New root after popping element 20: "<<avlTree.root->data<<endl;
    avlTree.show();
    cout<<"In-order elements: ";
    avlTree.print(); //Має бути 10 25 30 40 50
    cout<<endl;
}


int main() {
    demonstrarion_mode();
}