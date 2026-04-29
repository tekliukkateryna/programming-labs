#include <functional>
#include <iostream>
using namespace std;

template <typename T>
struct AVLNode {
    T data;
    AVLNode *right, *left;
    int h;

    AVLNode(T data, AVLNode* right = nullptr, AVLNode* left = nullptr, int height = 1) : data(data), right(right), left(left), h(height) {}
};
template <typename T>
class AVLTree {
public:
    AVLNode<T> *root;
    int size;

    void create_empty() {
        root=nullptr;
        size = 0;
    }

    AVLNode<T>* LL (AVLNode<T>* A) {
        AVLNode<T>* B = A->left;
        AVLNode<T>* C = B->left;   //По факту не міняється

        A->left = B->right; //підчепляємо, бо зараз перезапишемо B->left
        B->right = A;

        A->h = 1 + max(height(A->left), height(A->right));
        B->h = 1 + max(height(B->left), height(B->right));

        return B;
    }

    AVLNode<T>* RR (AVLNode<T>* A) {
        AVLNode<T>* B = A->right;

        A->right = B->left; //підчепляємо, бо зараз перезапишемо B->left
        B->left = A;

        A->h = 1 + max(height(A->left), height(A->right));
        B->h = 1 + max(height(B->left), height(B->right));

        return B;
    }

    AVLNode<T>* LR (AVLNode<T>* A) {
        A->left = RR(A->left);
        return LL(A);
    }

    AVLNode<T>* RL (AVLNode<T>*A) {
        A->right=LL(A->right);
        return RR(A);
    }

    int height(AVLNode<T>* n) {
        return n ? n->h : 0; //якщо вузла немає, його висота 0
    }

    void add (T a) {
        add(a, root);
    }

    void add (T a, AVLNode<T>* &curr) {
        if (curr==nullptr) {
            curr = new AVLNode<T>(a);
            size++;
            return;
        }

        if (a<curr->data) {
            add(a, curr->left);
            if (height(curr->left)-height(curr->right)>1) {
                if (a<curr->left->data) {
                    curr = LL(curr);
                } else {
                    curr = LR(curr);
                }
            }
        } else {
            add(a, curr->right);
            if (height(curr->right)-height(curr->left)>1) {
                if (a>curr->right->data) {
                    curr = RR(curr);
                } else {
                    curr = RL(curr);
                }
            }
        }

        curr->h = 1 + max(height(curr->left), height(curr->right));
    }

    void pop(T a) {
        pop(a, root);
    }

    void pop (T a, AVLNode<T>*& curr) {
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
                AVLNode<T>* new_nd = curr->right;
                while (new_nd->left != nullptr) {
                    new_nd = new_nd->left;
                }
                curr->data = new_nd->data;
                pop (curr->data, curr->right);
            } else {
                AVLNode<T>* temp = curr;
                if (curr->left != nullptr) {
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
                delete temp;
            }
        }

        if (curr == nullptr) return;

        curr->h = 1 + max(height(curr->left), height(curr->right));

        int balance = height(curr->left) - height(curr->right);
        if (balance > 1) {
            if (height(curr->left->left) >= height(curr->left->right))
                curr = LL(curr);
            else
                curr = LR(curr);
        }
        else if (balance < -1) {
            if (height(curr->right->right) >= height(curr->right->left))
                curr = RR(curr);
            else
                curr = RL(curr);
        }
    }

    AVLNode<T>* find (T a, AVLNode<T>* curr) {
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

    pair<AVLNode<T>*, AVLNode<T>*> range (T min, T max) {
        AVLNode<T>* min_node = findMin (min,root, nullptr);
        AVLNode<T>* max_node = findMax (max,root, nullptr);
        return {min_node, max_node};
    }

    AVLNode<T>* findMin (T min, AVLNode<T>* curr, AVLNode<T>* best = nullptr) {
        if (curr == nullptr) return best;
        if (curr->data == min) return curr;
        if (curr->data>=min) {
            return findMin(min, curr->left, curr);
        } else {
            return findMin(min, curr->right, best);
        }
    }

    AVLNode<T>* findMax (T max, AVLNode<T>* curr, AVLNode<T>* best = nullptr) {
        if (curr == nullptr) return best;
        if (curr->data == max) return curr;
        if (curr->data<=max) {
            return findMax(max, curr->right, curr);
        } else {
            return findMax(max, curr->left, best);
        }
    }

    void print () {
        print(root);
    }

    void print(AVLNode<T>* curr) {
        if (curr == nullptr) return;
        print(curr->left);
        cout<<curr->data<<" ";
        print(curr->right);
    }

    void apply(function<void(T&)> op) {
        apply(op, root);
    }

    void apply(std::function<void(T&)> op, AVLNode<T>* curr) {
        if (curr == nullptr) return;
        apply(curr->left);
        op(curr->data);
        apply(curr->right);
    }

    void show() {
        show(root, 0);
    }
    void show(AVLNode<T>* curr, int indent, char prefix = ' ') {
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