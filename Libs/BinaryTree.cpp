#include "BinaryTree.h"
#include <vector>
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
}

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
}

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

}

bool BinaryTree::findPath(const BinaryTree* root, std::vector<int>& path, int target){
     if (root == NULL) 
        return false;
 
    path.push_back(root->data);

    if (root->data == target)
        return true;
 
    if ((root->left && findPath(root->left, path, target))
        || (root->right && findPath(root->right, path, target)))
        return true;
 
    path.pop_back();
    return false;
}

int  BinaryTree::findLCA(BinaryTree* root, int x, int y){
            
    std::vector<int> path1, path2;
 
    if (!findPath(root, path1, x)
        || !findPath(root, path2, y))
        return -1;
 
    /* Compare the paths to get the first different value */
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;
    return path1[i - 1]; 
}

