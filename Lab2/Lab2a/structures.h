#include <iostream>
#include <vector>

template <typename T>

//Static array
class Array {
public:
    int n;
    int tail;
    T *arr;

    void create_empty(int num) {
        n = num;
        arr = new T[n];
        tail = -1;
    }

    void append_left (T c) {
        if (tail<n-1) {
            for (int i = tail; i>=0; i--) {
                arr[i+1]=arr[i];
            }
            arr[0]=c;
            tail++;
        } else {
            std::cout<<"size!"<<std::endl;
        }
    }

    void append (T c) {
        if (tail<n-1) {
            arr[tail+1]=c;
            tail++;
        } else {
            std::cout<<"size!"<<std::endl;
        }
    }

    void pop_left () {
        if (tail>=0) {
            for (int i = 0; i<tail; i++) {
                arr[i]=arr[i+1];
            }
            tail--;
        }
    }

    void pop () {
        if (tail>=0) {
            tail--;
        }
    }

    bool is_empty() {
        if (tail<0) {
            return true;
        }
        return false;
    }

    void show() {
        if (tail==-1) {
            std::cout<<"Empty"<<std::endl;
        }else {
            for (int i = 0; i<=tail; i++) {
                std::cout<<arr[i]<<" ";
            }
        }
        std::cout<<std::endl;
    }
};

template <typename T>
class ArrayList {
public:
    std::vector<T> arrlist;

    void create_empty(){}

    void append_left(T c) {
        arrlist.insert(arrlist.begin(), c);
    }

    void append(T c) {
        arrlist.push_back(c);
    }

    void pop_left() {
        arrlist.erase(arrlist.begin());
    }

    void pop() {
        arrlist.pop_back();
    }

    bool is_empty() {
        return arrlist.empty();
    }

    void show() {
        if (arrlist.empty()) {
            std::cout<<"Empty"<<std::endl;
        } else {
            for (T t: arrlist) {
                std::cout<<t<<" ";
            }
        }
        std::cout<<std::endl;
    }
};

template <typename T>
struct Node {
    T data;
    Node *next;
};
template <typename T>
class LinkedList {
public:
    Node<T> *head, *tail;

    void create_empty() {
        head=NULL;
        tail=NULL;
    }

    void append_left(T c) {
        Node<T> *node = new Node<T>;
        node->data = c;
        node->next = head;
        if (head==NULL) {
            tail=node;
        }
        head=node;
    }

    void append(T c) {
        Node<T> *node = new Node<T>;
        node->data = c;
        node->next=NULL;
        if (head==NULL) {
            head=tail=node;
            return;

        }
        tail->next=node;
        tail=node;
    }

    void pop_left() {
        if (head==NULL) return;
        if (head==tail) {
            delete head;
            head=tail=NULL;
            return;
        }
        Node<T> *tmp = head;
        head=head->next;
        delete tmp;
    }

    void pop() {
        if (head==NULL) return;
        if (head==tail) {
            delete head;
            head=tail=NULL;
            return;
        }
        Node<T> *tmp = head;
        while (tmp->next!=tail) tmp=tmp->next;
        delete tail;
        tmp->next = NULL;
        tail = tmp;
    }

    bool is_empty() {
        if (head==NULL && tail==NULL) return true;
        return false;
    }

    void show() {
        if (head==NULL && tail==NULL) {
            std::cout<<"Empty"<<std::endl;
            std::cout<<std::endl;
        }
        Node<T>* tmp = head;
        while (tmp!=NULL) {
            std::cout<<tmp->data<<" ";
            tmp=tmp->next;
        }
        std::cout<<std::endl;
    }
};