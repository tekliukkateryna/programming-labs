#include <iostream>
using namespace std;

//Block 4
struct Binary_node{
    int value;
    Binary_node* left = nullptr;
    Binary_node* right = nullptr;
};

struct Binary_tree {
    Binary_node *root=nullptr;
};

void add_to_binary (Binary_node* &nd, int val) {
    if (nd==nullptr) {
        nd= new Binary_node(val);
        return;
    }

    if (val<nd->value) {
        add_to_binary(nd->left, val);
    } else {
        add_to_binary(nd->right, val);
    }
}
void print_binary_tree(Binary_node* node, std::string st="") {
    if (node==nullptr) return;

    cout<<st<<node->value<<endl;

    print_binary_tree(node->left, st+"  ");
    print_binary_tree(node->right, st+"  ");
}