#include <iostream>
#include "structures.h"

struct Circle {
    double x, y, r;
};
// Запитала в Gemini як перевизначити оператор << , бо в мене щось првильно не виходило
std::ostream& operator<<(std::ostream& os, const Circle& c) {
    os << "(x:" << c.x << ", y:" << c.y << ", r:" << c.r << ")"<<" ";
    return os;
}

void demonstration() {

    std::cout << "DEMONSTRATION" << std::endl;
    std::cout << "Array: " << std::endl;
    Array<Circle> arr;
    arr.create_empty(2);
    Circle c1 = {1, 1, 1};
    Circle c2 = {2, 2, 2};
    Circle c3 = {3, 3, 3};
    arr.append(c1);
    arr.append(c2);
    arr.append(c3);
    arr.show();
    arr.pop_left();
    arr.append(c3);
    arr.show();
    std::cout<<std::endl;

    std::cout <<"Array list: "<<std::endl;
    ArrayList<Circle> arrlist;
    arrlist.append(c3);
    arrlist.append(c2);
    arrlist.append(c1);
    arrlist.print();
    std::cout<<std::endl;

    std::cout<<"Linked list"<<std::endl;
    LinkedList<Circle> list;
    list.create_empty();
    list.append(c1);
    list.append(c2);
    list.append_left(c3);
    list.print();
    list.pop_left();
    list.pop();
    list.print();
    std::cout<<std::endl;

    // для інштого типу
    std::cout<<"Linked list for integers"<<std::endl;
    LinkedList<int> intList;
    intList.create_empty();
    intList.append(42);
    intList.append(100);
    intList.print();
    intList.pop_left();
    intList.print();
    std::cout<<std::endl;
}


template <typename T_st>
void command(T_st strc){
    int op = -1;
    while (op != 0) {
        std::cout << "1. Append Circle\n2. Append_left\n3. Pop\n4. Pop_left\n5. Show\n0. End\nCommand: ";
        std::cin >> op;

        if (op == 1) {
            Circle c;
            std::cout << "Enter x y r: ";
            std::cin >> c.x >> c.y >> c.r;
            strc.append(c);
        } else if (op == 2) {
            Circle c;
            std::cout << "Enter x y r: ";
            std::cin >> c.x >> c.y >> c.r;
            strc.append_left(c);
        } else if (op == 3) {
            strc.pop();
            std::cout << "Deleted.\n";
        } else if (op == 4) {
            strc.pop_left();
            std::cout << "Deleted.\n";
        }else if (op== 5) {
            std::cout << "Show: ";
            strc.show();
        }
    }
}

void interactive() {
    std::cout<<"INTERACTIVE"<<std::endl;
    std::cout<<"Coose implementation: 1-Array, 2-Array List, 3-Linked List"<<std::endl;
    int n;
    std::cin>>n;
    if (n==1) {
        Array<Circle> arr;
        std::cout<<"Creating array. Input size: ";
        int inp;
        std::cin>>inp;
        arr.create_empty(inp);
        command(arr);
    } else if (n==2) {
        ArrayList<Circle> arr;
        std::cout<<"Array list created"<<std::endl;
        command(arr);
    } else if (n==3) {
        LinkedList<Circle> arr;
        arr.create_empty();
        std::cout<<"Linked list created"<<std::endl;
        command(arr);
    }
}

int main() {
    demonstration();
    interactive();
    return 0;
}