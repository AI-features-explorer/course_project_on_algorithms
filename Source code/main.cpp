#include "../Libs/BinaryTree.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <windows.h>
#include <cstdlib> 
#include <ctime>  
using namespace CourseProjectOnAlgorithms;
using namespace std;

int main()
{
    //for unicode
    SetConsoleOutputCP(CP_UTF8);
    
    BinaryTree* tree = new BinaryTree(20);

    // Insert elements into the tree
    srand(time(nullptr)); 
        for (int i = 0; i < 14; ++i) {
            tree->insert(rand() % 50);
        }

    bool loop = true;

    while(loop) {
        // Print the tree
        cout << "Binary Tree:" << std::endl;
        tree->printTree();

        // geting the variabels
        bool isValueIncorrect = true;
        int x; int y;

        do {
            cout << endl << "Write the first node: > ";
            if (cin >> x) {
                isValueIncorrect = false;
            } else {
                cout << "Incorrect input for first node." << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

            cout << endl << "Write the second node: > ";
            if (cin >> y) {
                isValueIncorrect = false;
            } else {
                cout << "Incorrect input for second node." << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

        } while (isValueIncorrect);

        // Find Lowest Common Ancestor (LCA) of two nodes
        int result = tree->findLCA(tree, x, y);
        if(result != -1)
            cout << endl  << "LCA is " << result << endl;
        else {cout << endl << "Incorrect data or the given numbers are not in the tree" << endl; }
        
        string arg;
        cout << endl << "exit the program? y/n > ";
        cin >> arg;

        if (arg == "y" || arg == "Y"|| arg == "Yes"|| arg == "yes"|| arg == "YES")
        { cout << endl; loop = false;}
        else { cout << endl << "continue..." << endl; system("cls"); }
    }

    // Clean up the memory
    delete tree;
    system("pause.exe");
    return 0;
}