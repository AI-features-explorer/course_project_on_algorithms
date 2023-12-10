#pragma once

//todo: class and structure pattern
class BinaryTree {
    public:
        int data;
        BinaryTree* left;
        BinaryTree* right;

        BinaryTree(int val) : data(val), left(nullptr), right(nullptr) {}
        // first insert
        void insert(int value){}
        // all subsequent inserts
        BinaryTree* insertRecursive(BinaryTree* node, int value){}
        // print tree - no var's
        void printTree(){};
        // output with params realization
        void PrintTreeLR(BinaryTree* Tree, int level){};
        // find node in tree method
        bool isNodeInStock(BinaryTree* root, BinaryTree* node){}
        // lowest (least) common ancestor. finding method
        bool findLCA(BinaryTree* root, BinaryTree* &lca, BinaryTree* x, BinaryTree* y){};
        // lowest (least) common ancestor. giving result in console method
        void findLCA(BinaryTree* root, BinaryTree* x, BinaryTree* y){};

};