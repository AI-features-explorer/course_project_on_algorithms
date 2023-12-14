#include "../Libs/BinaryTree.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
using namespace CourseProjectOnAlgorithms;
using namespace std;

int main()
{
    BinaryTree* tree = new BinaryTree(20);

    // Insert elements into the tree
    tree->insert(10);
    tree->insert(30);
    tree->insert(5);
    tree->insert(15);
    tree->insert(25);
    tree->insert(35);

    // Print the tree
    std::cout << "Binary Tree:" << std::endl;
    tree->printTree();

    // Find Lowest Common Ancestor (LCA) of two nodes
    BinaryTree* x = tree->insertRecursive(tree, 5);   // Assuming 5 exists in the tree
    BinaryTree* y = tree->insertRecursive(tree, 15);  // Assuming 15 exists in the tree
    tree->findLCA(tree, x, y);

    // Clean up the memory
    delete tree;
    
    return 0;
}