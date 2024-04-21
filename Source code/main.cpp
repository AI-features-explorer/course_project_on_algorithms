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
    SetConsoleOutputCP(CP_UTF8);
   
    const int array_size = 20; 
    int init_data[array_size]; 
    std::srand(std::time(0));

    for(int i = 0; i < array_size; ++i) {
        init_data[i] = std::rand() % 80; 
    }

    BinaryTree* tree = new BinaryTree(init_data, 0, array_size - 1);

    bool loop = true;

    while(loop) {

        cout << "Binary Tree:" << std::endl;
        tree->printTree();

        bool isFirstValueIncorrect = true;
        bool isSecondValueIncorrect = true;
        int x, y;

        do {
            cout << endl << "Write the first node: > ";
            if (cin >> x) {
                isFirstValueIncorrect = false;
            } else {
                cout << "Incorrect input for first node." << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        
        } while (isFirstValueIncorrect);

         do {
            cout << endl << "Write the second node: > ";
            if (cin >> y) {
                isSecondValueIncorrect = false;
            } else {
                cout << "Incorrect input for second node." << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            
        } while (isSecondValueIncorrect);

        int result = tree->findLCA(tree, x, y);
        if(result != -1) 
            cout << endl  << "LCA is " << result << endl;
        else 
            cout << endl << "First or second (or both) value not in the tree";

        string arg;
        cout << endl << "exit the program? y/n > ";
        cin >> arg;

        if (arg == "y" || arg == "Y"|| arg == "Yes"|| arg == "yes"|| arg == "YES")
        { cout << endl; loop = false;}
        else { cout << endl << "continue..." << endl; system("cls"); }
    }

    delete tree;
    system("pause.exe");
    return 0;
}