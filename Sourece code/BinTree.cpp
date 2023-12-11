#include "BinTree.h"
#include <iostream>

//todo: class realization
class BinaryTree {
    public:
        int data;
        BinaryTree* left;
        BinaryTree* right;

        BinaryTree(int val) : data(val), left(nullptr), right(nullptr) {}

        void insert(int value){
            insertRecursive(this, value);
        }
        
        static BinaryTree* insertRecursive(BinaryTree* node, int value){
            if (node == nullptr) { return new BinaryTree(value);}

            if (value < node->data) {
                node->left = insertRecursive(node->left, value);
            } else if (value > node->data) {
                node->right = insertRecursive(node->right, value);
            }

            return node;
        }

        void clearTree(){
            clearTreeRecursive(this);
        };

        void clearTreeRecursive(BinaryTree* node) {
            if (node) {
                clearTree(node->left);
                clearTree(node->right);
                delete node;
            }
        }
        
        void printTree(){
            PrintTreeLR(this);
        };
        
        static void PrintTreeLR(BinaryTree* Tree, int level = 0){
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
        
        bool isNodeInStock(BinaryTree* root, BinaryTree* node){
            if (root == nullptr) { return false; }
            if (root == node) { return true; }
            return isNodeInStock(root->left, node) || isNodeInStock(root->right, node);
        }
        
        // lowest (least) common ancestor. finding method
        bool findLCA(BinaryTree* root, BinaryTree* &lca, BinaryTree* x, BinaryTree* y){

        };
        // lowest (least) common ancestor. giving result in console method
        void findLCA(BinaryTree* root, BinaryTree* x, BinaryTree* y){

        };

};