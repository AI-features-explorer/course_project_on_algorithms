#pragma once

//todo: class and structure pattern
class BinaryTree {
    public:
        int data;
        BinaryTree* left;
        BinaryTree* right;

        BinaryTree(int val) : data(val), left(nullptr), right(nullptr) {}
        // base method insert
        void insert(int value){}
        // submethod insert
        static BinaryTree* insertRecursive(BinaryTree* node, int value){}
        //base clear tree method
        void clearTree(){};
        //clear tree submethod
        static void clearTreeRecursive(BinaryTree* node) {};
        // base print tree method
        void printTree(){};
        // print tree submethod
        static void PrintTreeLR(BinaryTree* Tree, int level){};
        // find node in tree method
        bool isNodeInStock(BinaryTree* root, BinaryTree* node){}
        // lowest (least) common ancestor. existence search method
        bool findLCA(BinaryTree* root, BinaryTree* &lca, BinaryTree* x, BinaryTree* y){};
        // lowest (least) common ancestor. giving result in console method
        void findLCA(BinaryTree* root, BinaryTree* x, BinaryTree* y){};

};