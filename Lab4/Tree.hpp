#include <iostream>
#include <vector>
using namespace std;

//Block 0
struct Node{
    int value;
    Node* parent=nullptr;
    vector<Node*>children={};
};

struct Tree {
    Node *root=nullptr;
};

//Block 1
Node* find_by_path(Tree tree, vector<int> path) {
    int n = path.size();
    Node* curr = tree.root;
    if (n==0) {
        return curr;
    }
    for (int i = 0; i<n; i++) {
        if (curr->children.size()>path[i] && path[i]>=0) {
            curr=curr->children[path[i]];
        }
    }
    return curr;
}

bool find_path (Node* node, int value, vector<int> &path) {
    if (node==nullptr) {
        return false;
    }

    if (node->value==value) {
        return true;
    }

    for (int i = 0; i<node->children.size(); i++) {
        path.push_back(i);
        if (find_path(node->children[i], value, path)) {
            return true;
        }
        path.pop_back();
    }

    return false;
}

void add_by_path(Tree &tree, vector<int> path, int val) {
    Node* nd = new Node();
    nd->value = val;

    Node* curr = find_by_path(tree, path);

    if (curr==nullptr) {
        tree.root=nd;
        return;
    }

    curr->children.push_back(nd);
    nd->parent=curr;
}

//Block 2
void print_tree(Node* node, string st="") {
    if (node==nullptr) return;

    cout<<st<<node->value<<endl;

    int n = node->children.size();
    for (int i = 0; i<n; i++) {
        print_tree(node->children[i], st+"  ");
    }
}

//Block 3
Tree delete_by_path(Tree tree, vector<int> path) {
    Node* node = find_by_path(tree, path);
    Node* curr = node->parent;
    curr->children.erase(curr->children.begin()+path.size()-1);

    Tree res;
    res.root = node;
    return res;
}