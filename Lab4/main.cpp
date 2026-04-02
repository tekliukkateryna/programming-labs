#include <iostream>

#include "Arithmetic_tree.hpp"
#include "Tree.hpp"
#include "Binary_tree.hpp"
#include "Threaded_binary_tree.hpp"
using namespace std;


int main() {
    /*Tree tree;

    // Додаємо корінь
    add_by_path(tree, {}, 10);

    // Додаємо дітей до кореня (шлях {} вказує на корінь)
    add_by_path(tree, {}, 20);
    add_by_path(tree, {}, 30);

    // Додаємо дитину до вузла 20 (вузол 20 має індекс 0 у кореня)
    add_by_path(tree, {0}, 42);

    cout << "Tree structure:" << endl;
    print_tree(tree.root);

    vector<int> p;
    if (find_path(tree.root, 42, p)) {
        cout << "Path to 42: ";
        for (int i : p) cout << i << " "; // Виведе: 0 0 (перша дитина кореня, потім її перша дитина)
        cout << endl;
    }

    cout<<"delete"<<endl;
    delete_by_path(tree, {0, 0});
    print_tree(tree.root);
    */

    /*Binary_tree btree;
    add_to_binary(btree.root, 1);
    add_to_binary(btree.root, 2);
    add_to_binary(btree.root, 3);
    add_to_binary(btree.root, 4);
    add_to_binary(btree.root, 5);
    add_to_binary(btree.root, 1);
    print_binary(btree.root);*/

    Binary_tree btree;
    add_to_binary(btree.root, 1);
    add_to_binary(btree.root, 2);
    add_to_binary(btree.root, 3);
    add_to_binary(btree.root, 4);
    add_to_binary(btree.root, 5);
    add_to_binary(btree.root, 1);
    print_binary_tree(btree.root);
    Threaded_tree tdtree;
    build_threaded_tree(btree.root, tdtree);
    print_threaded_tree(&tdtree);

    /*Arithm_tree atree;
    Arithm_node* curr = new Arithm_node(OP);
    atree.root = curr;
    atree.root->op = '*';
    Arithm_node* left_nd = new Arithm_node(OP);
    curr->left=left_nd;
    left_nd->op = '+';
    Arithm_node* right_nd = new Arithm_node(OP);
    curr->right=right_nd;
    right_nd->op = '+';*/

// Я ще додам вивід з дужками і демонстраційний режим, вибачте не встигала

    return 0;
}