#include "BinaryTree.h"
#include <iostream>
using namespace CourseProjectOnAlgorithms;



BinaryTree::~BinaryTree() {
    delete left;
   delete right;
}

void BinaryTree::insert(int value){
    insertRecursive(this, value);
}

BinaryTree* BinaryTree::insertRecursive(BinaryTree* node, int value){
    if (node == nullptr) { return new BinaryTree(value);}

    if (value < node->data) {
        node->left = insertRecursive(node->left, value);
    } else if (value > node->data) {
        node->right = insertRecursive(node->right, value);
    }

    return node;
}

void BinaryTree::clearTree(){
    clearTreeRecursive(this);
};

void BinaryTree::clearTreeRecursive(BinaryTree* node) {
    if (node) {
        clearTreeRecursive(node->left);
        clearTreeRecursive(node->right);
        delete node;
        node = nullptr;
    }
}

void BinaryTree::printTree() const {
    PrintTreeLR(this, 0);
};

void BinaryTree::PrintTreeLR(const BinaryTree* Tree, int level = 0){
    int i;
    if (Tree)
    {
        PrintTreeLR(Tree->right,level+1);
        for (i=0; i<level; i++)
            std::cout << "\t";
        std::cout << Tree->data << "[" << level+1 << "]";
        PrintTreeLR(Tree->left, level+1);
    }
    else  std::cout << std::endl;

};

bool BinaryTree::isNodeInStock(const BinaryTree* root, BinaryTree* node){
    if (root == nullptr) { return false; }
    if (root == node) { return true; }
    return isNodeInStock(root->left, node) || isNodeInStock(root->right, node);
}

bool BinaryTree::findLCA(BinaryTree* root, BinaryTree* &lca, BinaryTree* x, BinaryTree* y){
    
    if (root == nullptr) { return false; }
    if (root == x || root == y)
    {
        lca = root;
        return true;
    }

    bool left = findLCA(root->left, lca, x, y);
    bool right = findLCA(root->right, lca, x, y);
    if (left && right) { lca = root; }

    return left || right;
};

void BinaryTree::findLCA(BinaryTree* root, BinaryTree* x, BinaryTree* y){
            
            BinaryTree* lca = nullptr;
            if (isNodeInStock(root, y) && isNodeInStock(root, x)) {
                findLCA(root, lca, x, y);
            }
        
            // if LCA exists, print it
            if (lca != nullptr) {
                std::cout << "Lowest common ancestor is " << lca->data << std::endl;
            }
            else {
                std::cout << "Lowest common ancestor does not exist\n";
            }
        };

