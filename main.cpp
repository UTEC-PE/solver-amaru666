#include <iostream>
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int a);
};
Node::Node(int a) {
    this->data = a;
    this->left=this->right= nullptr;
}
class BinaryTree{
public:
    Node* root;
    BinaryTree();
    void insert(int data, Node* node);
    Node* search(int data, Node* node);
    Node* minimum(Node* node);
    Node* maximum(Node* node);
};
BinaryTree::BinaryTree() {
    root= nullptr;
}
void BinaryTree::insert(int data, Node *node) {
    Node * x = node;
    Node * y = nullptr;
    Node * z = new Node(data);
    while (x != nullptr) {
        y = x;
        if (z->data < x->data) x = x->left;
        else x = x->right;
    }
    if(y == nullptr) this->root = z;
    else if(z->data < y->data) y->left = z;
    else y->right = z;
}
Node* BinaryTree::search(int data, Node *node) {
    if(node == nullptr || data == node->data) return node;
    if(data<node->data) return search(data,node->left);
    else return search(data,node->right);
}
Node* BinaryTree::maximum(Node *node) {
    while (node->right != nullptr) node=node->right;
    return node;
}
Node* BinaryTree::minimum(Node *node) {
    while (node->left != nullptr) node=node->left;
    return node;
}
int main() {

    BinaryTree mytree = BinaryTree();
    mytree.insert(5,mytree.root);
    mytree.insert(3,mytree.root);
    mytree.insert(4,mytree.root);
    mytree.insert(2,mytree.root);
    mytree.insert(1,mytree.root);
    mytree.insert(6,mytree.root);
    mytree.insert(0,mytree.root);
    Node* find = mytree.search(4,mytree.root);
    std::cout<<&find<<"\n";
    Node* max = mytree.maximum(mytree.root);
    std::cout<<max->data<<"\n";
    return 0;
}