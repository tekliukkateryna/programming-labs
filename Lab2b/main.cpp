#include <iostream>

template <typename T, int N>
class UnrolledLinkedList {
public:
    struct Node {
        T elem [N];
        int count = 0;
        Node *next = nullptr;
        Node *prev = nullptr;
    };
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

    void forward(){
        Node* current = head;
        while (current!=nullptr) {
            for (size_t i = 0; i < current->count; ++i)
                std::cout << current->elem[i] << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    void backward() {
        Node* current = tail;
        while (current!=nullptr) {
            for (int i = current->count-1; i >= 0; --i)
                std::cout << current->elem[i] << " ";
            current = current->prev;
        }
        std::cout << "\n";
    }

    void append(T t) {
        if (tail==nullptr) {
            Node* node = new Node;
            node->elem[0]=t;
            node->count++;
            size++;
            head = tail = node;
        } else if (tail->count==N) {
            Node* node = new Node;
            int half = N/2;
            for (int i = half; i<N; i++) {
                node->elem[node->count]=tail->elem[i];
                node->count++;
                tail->count--;
            }
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        tail->elem[tail->count]=t;
        tail->count++;
        size++;
    }

    void append_left(T t) {
        if (head==nullptr) {
            Node* node = new Node;
            node->elem[0]=t;
            node->count++;
            size++;
            head = tail = node;
            return;
        }
        if (head->count==N) {
            Node* node = new Node;
            int half = N/2;
            for (int i = half; i<head->count; i++) {
                node->elem[node->count++]=head->elem[i];
                head->count--;
            }
            node->next = head;
            head->prev = node;
            head = node;
        }
        for (int i = head->count-1; i>0; i--) {
            head->elem[i]=head->elem[i-1];
        }
        head->elem[0]=t;
        head->count++;
        size++;
    }

    void insert(int ind, T t) {
        if (ind<0 || ind>size) {
            std::cout<<"Size!";
            return;
        }
        Node *curr = head;
        while (curr!=nullptr) {
            if (ind<curr->count) {
                break;
            }
            ind-=curr->count;
            curr=curr->next;
        }
        if (curr->count==N) {
            Node *node = new Node;
            node->prev = curr;
            node->next = curr->next;
            curr->next = node;
            if (node->next != nullptr) {
                node->next->prev = node;
            }
            if (curr==tail) {
                tail=node;
            }
            int half = N/2;
            for (int i = half; i<N; i++) {
                node->elem[node->count]=curr->elem[i];
                node->count++;
            }
            curr->count=half;
            if (ind>=half) {
                ind-=half;
                curr=node;
            }
        }
        for (int i = curr->count; i>ind; i--) {
            curr->elem[i]=curr->elem[i-1];
        }
        curr->elem[ind]=t;
        curr->count++;
        size++;
    }

    void erase (int ind) {
        if (ind<0 || ind>=size) {
            std::cout<<"Size!"<<std::endl;
            return;
        }
        Node *curr = head;
        while (curr!=nullptr) {
            if (ind<curr->count) {
                break;
            }
            ind-=curr->count;
            curr = curr->next;
        }
        for (int i = ind; i<curr->count-1; i++) {
            curr->elem[i]=curr->elem[i+1];
        }
        curr->count--;
        size--;
        if (curr->next != nullptr && curr->count+curr->next->count<N/2) {
            Node *node = curr->next;
            for (int i = 0; i<node->count; i++) {
                curr->elem[curr->count++]=node->elem[i];
            }
            if (node==tail) {
                tail=node->prev;
                tail->next=nullptr;
                delete node;
            } else {
                node->prev->next=node->next;
                node->next->prev=node->prev;
                delete node;
            }
        }
    }

    T* find_by_index (int ind) {
        if (ind < 0 || ind >= size) return nullptr;
        Node *curr = head;
        while (curr!=nullptr) {
            if (ind<curr->count) {
                return &curr->elem[ind];
            }
            ind-=curr->count;
            curr = curr->next;
        }
        return nullptr;;
    }

    T* find_by_value (T t) {
        Node *curr = head;
        while (curr!=nullptr) {
            for (int i = 0; i<curr->count; i++) {
                if (t==curr->elem[i]) {
                    return &curr->elem[i];
                }
            }
            curr=curr->next;
        }
        return nullptr;
    }

};

int main() {
    std::cout<<"Some tests"<<std::endl;
    UnrolledLinkedList<int, 4> list;

    for (int i = 1; i <= 10; i++) {
        list.append(i);
    }
    list.forward();   // 1 2 3 4 5 6 7 8 9 10
    list.backward();  // 10 9 8 7 6 5 4 3 2 1

    list.append_left(100);
    list.append_left(200);
    list.forward();   // 200 100 1 2 3 4 5 6 7 8 9 10

    list.insert(3, 999);
    list.forward();        // 200 100 1 999 2 3 4 5 6 7 8 9 10
    int* ptr = list.find_by_index(3);
    if (ptr) std::cout << "Index 3 = " << *ptr << "\n"; // 999
    int* ptr2 = list.find_by_value(999);
    if (ptr2) std::cout << "Found value = " << *ptr2 << "\n"; // 999

    list.erase(3);
    list.forward();   // 200 100 1 2 3 4 5 6 7 8 9 10
    list.erase(0);
    list.forward();   // 100 1 2 3 4 5 6 7 8 9 10
    list.erase(list.size - 1);
    list.forward();            // 100 1 2 3 4 5 6 7 8 9

    std::cout << "End";

    return 0;
}