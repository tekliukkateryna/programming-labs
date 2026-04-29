#include <functional>
#include <iostream>
using namespace std;

template <typename T>
struct BinNode {
    T data;
    BinNode *right, *left;

    BinNode(T data, BinNode* right = nullptr, BinNode* left = nullptr) : data(data), right(right), left(left) {}
};
template <typename T>
class BinaryTree {
public:
    BinNode<T> *root;
    int size;

    void create_empty() {
        root=nullptr;
        size = 0;
    }

    void add (T a) {
        add(a, root);
    }
    void add (T a, BinNode<T>* &curr) {
        if (curr==nullptr) {
            curr = new BinNode<T>(a);
            size++;
            return;
        }

        if (a<curr->data) {
            add(a, curr->left);
        } else {
            add(a, curr->right);
        }
    }

    void pop(T a) {
        pop(a, root);
    }

    void pop (T a, BinNode<T>*& curr) {
        if (curr == nullptr) {
            cout << "Not found" << endl;
            return;
        }

        if (a<curr->data) {
            pop(a, curr->left);
        } else if (a>curr->data) {
            pop(a, curr->right);
        } else {
            if (curr->left!=nullptr && curr->right!=nullptr) {
                BinNode<T>* new_nd = curr->right;
                while (new_nd->left != nullptr) {
                    new_nd = new_nd->left;
                }
                curr->data = new_nd->data;
                pop (curr->data, curr->right);
            } else {
                BinNode<T>* temp = curr;
                if (curr->left != nullptr) {
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
                delete temp;
                size--;
            }
        }
    }

    BinNode<T>* find (T a, BinNode<T>* curr) {
        if (curr == nullptr) {
            cout<<"Not found"<<endl;
            return nullptr;
        }
        if (curr->data==a) {
            return curr;
        }

        if (a<curr->data) {
            return find(a, curr->left);
        } else {
            return find(a, curr->right);
        }
    }

    pair<BinNode<T>*, BinNode<T>*> range (T min, T max) {
        BinNode<T>* min_node = findMin (min,root, nullptr);
        BinNode<T>* max_node = findMax (max,root, nullptr);
        return {min_node, max_node};
    }

    BinNode<T>* findMin (T min, BinNode<T>* curr, BinNode<T>* best = nullptr) {
        if (curr == nullptr) return best;
        if (curr->data == min) return curr;
        if (curr->data>=min) {
            return findMin(min, curr->left, curr);
        } else {
            return findMin(min, curr->right, best);
        }
    }

    BinNode<T>* findMax (T max, BinNode<T>* curr, BinNode<T>* best = nullptr) {
        if (curr == nullptr) return best;
        if (curr->data == max) return curr;
        if (curr->data<=max) {
            return findMax(max, curr->right, curr);
        } else {
            return findMax(max, curr->left, best);
        }
    }

    void print() {
        print(root);
        cout<<endl;
    }

    void print(BinNode<T>* curr) {
        if (curr == nullptr) return;
        print(curr->left);
        cout<<curr->data<<" ";
        print(curr->right);
    }

    void apply(function<void(T&)> op) {
        apply(op, root);
    }

    void apply(function<void(T&)> op, BinNode<T>* curr) {
        if (curr == nullptr) return;
        apply(op, curr->left);
        op(curr->data);
        apply(op, curr->right);
    }

    void show() {
        show(root, 0);
    }
    void show(BinNode<T>* curr, int indent, char prefix = ' ') {
        if (curr == nullptr) return;

        if (curr->right) {
            show(curr->right, indent + 8, '/');
        }

        if (indent > 0) {
            cout << string(indent - 8, ' ') << " " << prefix << "-------";
        }
        cout << "[" << curr->data << "]" << endl;

        if (curr->left) {
            show(curr->left, indent + 8, '\\');
        }
    }
};