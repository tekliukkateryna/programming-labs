#include <iostream>

#include "Arithmetic_tree.hpp"
#include "Tree.hpp"
#include "Binary_tree.hpp"
#include "Threaded_binary_tree.hpp"
using namespace std;

void demonstration_mode () {

    cout<<"TREE"<<endl;
    cout<<"Add by path:"<<endl;
    Tree tree;
    // root
    add_by_path(tree, {}, 10);
    // add to root
    add_by_path(tree, {}, 20);
    add_by_path(tree, {}, 30);
    // add to 20 node
    add_by_path(tree, {0}, 42);
    print_tree(tree.root);

    cout<<"Find path: ";
    vector<int> p;
    if (find_path(tree.root, 42, p)) {
        cout << "Path to 42: ";
        for (int i : p) cout << i << " "; // Виведе: 0 0 (перша дитина кореня, потім її перша дитина)
        cout << endl;
    }

    cout<<"Delete by path: "<<endl;
    delete_by_path(tree, {0, 0});
    print_tree(tree.root);

    cout<<endl;
    cout<<"BINARY TREE"<<endl;
    cout<<"Add to binary: "<<endl;
    Binary_tree btree;
    add_to_binary(btree.root, 1);
    add_to_binary(btree.root, 2);
    add_to_binary(btree.root, 3);
    add_to_binary(btree.root, 4);
    add_to_binary(btree.root, 5);
    add_to_binary(btree.root, 1);
    print_binary_tree(btree.root);

    cout<<endl;
    cout<<"THREADED TREE"<<endl;
    cout<<"Create from binary tree and print using threads: "<<endl;
    Threaded_tree tdtree;
    build_threaded_tree(btree.root, tdtree);
    print_threaded_tree(&tdtree);

    cout<<endl;
    cout<<"ARITHMETIC TREE"<<endl;
    Arithm_tree a1tree;
    Arithm_node* curr = new Arithm_node(OP);
    a1tree.root = curr;
    a1tree.root->op = '*';
    Arithm_node* left_nd = new Arithm_node(OP);
    curr->left=left_nd;
    left_nd->op = '+';
    Arithm_node* right_nd = new Arithm_node(OP);
    curr->right=right_nd;
    right_nd->op = '+';
    Arithm_node* x = new Arithm_node(VAR);
    x->var = "x";
    Arithm_node* zero = new Arithm_node(CONST);
    zero->value = 0;
    left_nd->left = x;
    left_nd->right = zero;
    Arithm_node* two = new Arithm_node(CONST);
    two->value = 2;
    Arithm_node* three = new Arithm_node(CONST);
    three->value = 3;
    right_nd->left = two;
    right_nd->right = three;

    cout<<"1 - Before: "<<endl;
    cout<<print_tree(a1tree.root)<<endl;

    cout<<"After: "<<endl;
    a1tree.root = simplify(a1tree.root);
    cout<<print_tree(a1tree.root)<<endl;

    cout<<"Calculate: "<<endl;
    Variable vars [] = {{"x", 1}, {"y", 2}};
    cout<<evaluate(a1tree.root, vars, 2)<<endl;

    Arithm_tree a2tree;

    Arithm_node* root = new Arithm_node(OP);
    root->op = '+';
    a2tree.root = root;

    Arithm_node* left_mul = new Arithm_node(OP);
    left_mul->op = '*';
    root->left = left_mul;

    Arithm_node* x_2 = new Arithm_node(VAR);
    x_2->var = "x";

    Arithm_node* one = new Arithm_node(CONST);
    one->value = 1;

    left_mul->left = x_2;
    left_mul->right = one;

    Arithm_node* right_mul = new Arithm_node(OP);
    right_mul->op = '*';
    root->right = right_mul;

    Arithm_node* zr = new Arithm_node(CONST);
    zr->value = 0;

    Arithm_node* y = new Arithm_node(VAR);
    y->var = "y";

    right_mul->left = zr;
    right_mul->right = y;

    cout<<"2 - Before: "<<endl;
    cout<<print_tree(a2tree.root)<<endl;

    cout<<"After: "<<endl;
    a2tree.root = simplify(a2tree.root);
    cout<<print_tree(a2tree.root)<<endl;

    cout<<"Calculate: "<<endl;
    cout<<evaluate(a2tree.root, vars, 2)<<endl;
}


int main() {
    demonstration_mode();
    return 0;
}