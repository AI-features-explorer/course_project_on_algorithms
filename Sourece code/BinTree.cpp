#include "BinTree.h"
#include<iostream>
using namespace std;

//todo: class realization
class BinaryTree {
    public:
        int data;
        BinaryTree* left;
        BinaryTree* right;

        BinaryTree(int val) : data(val), left(nullptr), right(nullptr) {}
        // first insert
        void insert(int value){

        }
        // all subsequent inserts
        BinaryTree* insertRecursive(BinaryTree* node, int value){

        }
        // print tree - no var's
        void printTree(){
            PrintTreeLR(this);
        };
        // output with params realization
        void PrintTreeLR(BinaryTree* Tree, int level = 0){
            int i;
            if (Tree)
            {
                PrintTreeLR(Tree->right,level+1);
                for (i=0; i<level; i++)
                    cout << "\t";
                cout << Tree->data << "[" << level+1 << "]";
                PrintTreeLR(Tree->left, level+1);
            }
            else  cout << endl;

        };
        // find node in tree method
        bool isNodeInStock(BinaryTree* root, BinaryTree* node){

        }
        // lowest (least) common ancestor. finding method
        bool findLCA(BinaryTree* root, BinaryTree* &lca, BinaryTree* x, BinaryTree* y){

        };
        // lowest (least) common ancestor. giving result in console method
        void findLCA(BinaryTree* root, BinaryTree* x, BinaryTree* y){

        };

};