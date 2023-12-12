#include "BinTree.h"
#include <iostream>

class BinaryTree {
    public:
        int data;
        BinaryTree* left;
        BinaryTree* right;

        BinaryTree(int val) : data(val), left(nullptr), right(nullptr) {}

        ~BinaryTree() {
        clearTree();
        }

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
                clearTreeRecursive(node->left);
                clearTreeRecursive(node->right);
                delete node;
                node = nullptr;
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
        
        bool findLCA(BinaryTree* root, BinaryTree* &lca, BinaryTree* x, BinaryTree* y){
            
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

        void findLCA(BinaryTree* root, BinaryTree* x, BinaryTree* y){
            
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

};