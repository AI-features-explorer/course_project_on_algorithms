#include "../Libs/BinaryTree.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib> // Для функции rand()
#include <ctime>   // Для функции time()
using namespace CourseProjectOnAlgorithms;
using namespace std;

int main()
{
    BinaryTree* tree = new BinaryTree(20);

    // Insert elements into the tree
    srand(time(nullptr)); 
        for (int i = 0; i < 14; ++i) {
            tree->insert(rand() % 50); // Вставляем случайное значение от 0 до 50
        }

    // Print the tree
    cout << "Binary Tree:" << std::endl;
    tree->printTree();

    // geting the variabels
    int x; int y;
    cout << "Write the first hode: ";
    cin >> x;
    cout << "Write the first hode: ";
    cin >> y;

    // Find Lowest Common Ancestor (LCA) of two nodes
    cout << "LCA is "<< tree->findLCA(tree, x, y);

    // Clean up the memory and wait 
    delete tree;
    int end;
    cin >> end;
    
    return 0;
}