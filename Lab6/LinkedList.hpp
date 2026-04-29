#include <iostream>
#include "DateTime.hpp"
using namespace std;

template <typename T>
struct Node {
    T data;
    Node *next;

    Node(T val, Node* nxt = nullptr) : data(val), next(nxt) {}
};
template <typename T>
class LinkedList {
public:
    Node<T> *head;

    void create_empty() {
        head=nullptr;
    }

    void add (T a) {
        Node<T> *curr = head;
        Node<T> *new_nd = new Node(a);
        if (head==nullptr || curr->data > a) {
            new_nd->next=head;
            head = new_nd;
            return;
        }
        while (curr->next != nullptr) {
            if (curr->next->data > a) {
                new_nd->next = curr->next;
                curr->next = new_nd;
                return;
            }
            curr = curr->next;
        }
        curr->next = new_nd;
    }

    void pop (T a) {
        Node<T> *curr = head;
        if (head==nullptr) {
            cout<<"Not found"<<endl;
            return;
        }

        if (curr->data == a) {
            head = curr->next;
            delete curr;
            return;
        }
        while (curr->next != nullptr) {
            if (curr->next->data == a) {
                Node<T> * temp = curr->next->next;
                delete curr->next;
                curr->next = temp;
                return;
            }
            curr = curr->next;
        }
        cout<<"Not found"<<endl;
    }

    Node<T>* find (T a) {
        Node<T> *curr = head;
        while (curr != nullptr) {
            if (curr->data == a) {
                return curr;
            }
            curr = curr->next;
        }
        cout<<"Not found"<<endl;
        return nullptr;
    }

    pair<Node<T>*, Node<T>*> range (T min, T max) {
        Node<T> *curr = head;
        Node<T>* st = nullptr;
        Node<T>* end = nullptr;
        while (curr != nullptr) {
            if (curr->data>max) {
                cout<<"Lower boundary can`t be found"<<endl;
                return {nullptr, nullptr};
            }
            if (curr->data>=min) {
                st = curr;
                break;
            }
            curr = curr->next;
        }

        while (curr != nullptr) {
            if (curr->next==nullptr) {
                end = curr;
                break;
            }
            if (curr->next->data>max) {
                end = curr;
                break;
            }
            curr = curr->next;
        }

        return {st, end};
    }

    void print() {
        if (head==nullptr) {
            std::cout<<"Empty"<<std::endl;
            std::cout<<std::endl;
            return;
        }
        Node<T>* curr = head;
        while (curr!=nullptr) {
            std::cout<<curr->data<<" ";
            curr=curr->next;
        }
        std::cout<<std::endl;
    }

    void apply(std::function<void(T&)> op) {
        if (head==nullptr) {
            std::cout<<"Empty"<<std::endl;
            std::cout<<std::endl;
            return;
        }
        Node<T>* curr = head;
        while (curr!=nullptr) {
            op(curr->data);
            curr=curr->next;
        }
    }
};