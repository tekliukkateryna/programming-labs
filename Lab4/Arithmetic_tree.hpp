#include <cmath>
#include <format>
#include <iostream>
using namespace std;

//Block 6
enum NodeType {
    CONST, VAR, OP
};
struct Arithm_node{

    NodeType type;

    char op = 0;
    double value = 0;
    string var = "";

    Arithm_node* left = nullptr;
    Arithm_node* right = nullptr;
};

struct Arithm_tree {
    Arithm_node *root=nullptr;
};

double calculate (char op, double a, double b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw runtime_error("Division by zero");
            return a / b;
        case '^': return pow(a, b);
        default:
            throw runtime_error("Error! Unknown operation");
    }
}

bool equal(Arithm_node* a, Arithm_node* b) {
    if (!a || !b) return a == b;

    if (a->type != b->type) return false;

    if (a->type == CONST)
        return a->value == b->value;

    if (a->type == VAR)
        return a->var == b->var;

    if (a->type == OP) {
        if (a->op != b->op) return false;

        return equal(a->left, b->left) &&
               equal(a->right, b->right);
    }

    return false;
}

int priority (char op) {
    switch (op) {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
    }
}

string print_tree(Arithm_node* node, int prev = 0) {
    if (!node) return "";

    if (node->type == VAR) return node->var;
    if (node->type == CONST) return std::format("{}", node->value);

    string s = print_tree(node->left, priority(node->op))
             + string(1, node->op)
             + print_tree(node->right, priority(node->op));

    if (priority(node->op) < prev) s = "(" + s + ")";
    return s;
}

Arithm_node* simplify(Arithm_node* node) {

    if (!node) return nullptr;

    if (node->type != OP) return node;

    if (node->left==nullptr || node->right==nullptr) {
        throw runtime_error("Error! No value");
    }

    node->left = simplify(node->left);
    node->right = simplify(node->right);

    // For constats
    if (node->left->type == CONST && node->right->type == CONST) {
        double res = calculate(node->op,node->left->value,node->right->value);

        delete node->left;
        delete node->right;

        node->left = node->right = nullptr;
        node->type = CONST;
        node->value = res;

        return node;
    }

    // For basic simplifications
    if (node->op == '+' && node->left->type==CONST && node->left->value==0) {
        Arithm_node* res = node->right;
        delete node->left;
        delete node;
        return res;
    }

    if (node->op == '+' && node->right->type==CONST && node->right->value==0) {
        Arithm_node* res = node->left;
        delete node->right;
        delete node;
        return res;
    }

    if (node->op == '+' && equal(node->left,node->right)) {
        Arithm_node* old_left = node->left;
        node->op = '*';
        node->left = new Arithm_node(CONST);
        node->left->value = 2;
        node->right = old_left;
        return node;

    }

    if (node->op == '-' && node->right->type==CONST && node->right->value==0) {
        Arithm_node* res = node->left;
        delete node->right;
        delete node;
        return res;
    }

    if (node->op == '-' && equal(node->left, node->right)) {

        delete node->left;
        delete node->right;

        node->left = node->right = nullptr;
        node->type = CONST;
        node->value = 0;

        return node;
    }

    if (node->op == '*' &&
       ((node->left->type==CONST && node->left->value==0)
           || (node->right->type==CONST && node->right->value==0))) {

        delete node->left;
        delete node->right;

        node->left = node->right = nullptr;
        node->type = CONST;
        node->value = 0;

        return node;
    }

    if (node->op == '*' && node->right->type==CONST && node->right->value==1) {
        Arithm_node* res = node->left;
        delete node->right;
        delete node;
        return res;
    }

    if (node->op == '*' && node->left->type==CONST && node->left->value==1) {
        Arithm_node* res = node->right;
        delete node->left;
        delete node;
        return res;
    }

    if (node->op == '/' && node->left->type==CONST && node->left->value==0) {
        delete node->left;
        delete node->right;

        node->left = node->right = nullptr;
        node->type = CONST;
        node->value = 0;

        return node;
    }

    if (node->op == '/' && node->right->type==CONST && node->right->value==1) {
        Arithm_node* res = node->left;
        delete node->right;
        delete node;
        return res;
    }

    if (node->op == '/' && node->right->type==CONST && node->right->value==0) {
        throw runtime_error("Division by zero");
    }

    if (node->op == '/' && equal(node->right, node->left)) {
        delete node->left;
        delete node->right;

        node->left = node->right = nullptr;
        node->type = CONST;
        node->value = 1;

        return node;
    }

    if (node->op == '^' && node->right->type==CONST && node->right->value==1) {
        Arithm_node* res = node->left;
        delete node->right;
        delete node;
        return res;
    }

    if (node->op == '^' && node->right->type==CONST && node->right->value==0) {
        delete node->left;
        delete node->right;

        node->left = node->right = nullptr;
        node->type = CONST;
        node->value = 1;

        return node;
    }

    if (node->op == '*' && equal (node->left, node->right)) {

        node->op = '^';

        delete node->right;
        node->right = new Arithm_node();
        node->right->type = CONST;
        node->right->value = 2;

        return node;
    }

    return node;
}

struct Variable {
    string name;
    double value;
};

double evaluate (Arithm_node* node, Variable vars[], int num) {
    if (!node) return 0;

    if (node->type==CONST) {
        return node->value;
    }

    if (node->type==VAR) {
        for (int i = 0; i < num; i++) {
            if (vars[i].name == node->var) {
                return vars[i].value;
            }
        }
        throw runtime_error("Error! Variable not found");
    }

    double left_res = evaluate(node->left, vars, num);
    double right_res = evaluate(node->right, vars, num);
    double res = calculate(node->op,left_res, right_res);

    return res;
}