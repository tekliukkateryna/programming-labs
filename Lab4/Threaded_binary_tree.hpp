#include <iostream>
using namespace std;

//Block 5
struct Thread_node{
    int value;
    Thread_node* left = nullptr;
    Thread_node* right = nullptr;
    bool left_thread = false;
    bool right_thread = false;

};

struct Threaded_tree {
    Thread_node *root=nullptr;
};

//First attempt with single threaded tree
/*Thread_node* to_threaded_tree(Binary_node* &curr, Thread_node* &td_node ) {

    td_node=new Thread_node(curr->value);

    cout<<curr->value<<endl;

    Thread_node* prev = td_node;

    if (curr->left!=nullptr) {
        prev = to_threaded_tree(curr->left, td_node->left);
        prev->right = td_node;
        prev->right_tread = true;
    }
    if (curr->right!=nullptr) {
        prev = to_threaded_tree(curr->right, td_node->right);
    }
    return (prev);
}*/

void to_threaded_tree(Binary_node* bin_nd, Thread_node*& curr, Thread_node* &prev) {
    if (bin_nd == nullptr) {
        curr = nullptr;
        return;
    }

    curr = new Thread_node{bin_nd->value};

    to_threaded_tree(bin_nd->left, curr->left, prev);

    if (prev != nullptr && prev->right == nullptr) {
        prev->right = curr;
        prev->right_thread = true;
    }

    if (prev != nullptr && curr->left == nullptr) {
        curr->left = prev;
        curr->left_thread = true;
    }

    prev = curr;

    to_threaded_tree(bin_nd->right, curr->right, prev);
}

//I need to pass previous with nullptr inside it
//and it looked a little strange in main, so that`s why this method exists
void build_threaded_tree(Binary_node* bin_root, Threaded_tree& tree) {
    Thread_node* prev = nullptr;
    to_threaded_tree(bin_root, tree.root, prev);
}

void print_threaded_tree(Threaded_tree* tree) {
    if (tree == nullptr || tree->root == nullptr) return;

    Thread_node* curr = tree->root;

    while (curr->left != nullptr && !curr->left_thread) {
        curr = curr->left;
    }

    while (curr != nullptr) {
        cout << "->" << curr->value;

        if (curr->right_thread) {
            curr = curr->right;
        }
        else if (curr->right != nullptr) {
            curr = curr->right;
            while (curr->left != nullptr && !curr->left_thread) {
                curr = curr->left;
            }
        }
        else {
            curr = nullptr;
        }
    }
    cout<<endl;
}