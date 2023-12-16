#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H

namespace  CourseProjectOnAlgorithms{

    class BinaryTree {
        private:
            int data;
            BinaryTree* left;
            BinaryTree* right;

        public:
            BinaryTree(int val) : data(val), left(nullptr), right(nullptr) {}
            ~BinaryTree();
            // base method insert
            void insert(int value);
            // submethod insert
            static BinaryTree* insertRecursive(BinaryTree* node, int value);
            //base clear tree method
            void clearTree();
            //clear tree submethod
            static void clearTreeRecursive(BinaryTree* node) ;
            // base print tree method
            void printTree() const ;
            // print tree submethod
            static void PrintTreeLR( const BinaryTree* Tree, int level);
            // find node in tree method
            bool isNodeInStock( const BinaryTree* root, BinaryTree* node);
            // lowest (least) common ancestor. existence search method
            bool findLCA(BinaryTree* root, BinaryTree* &lca, BinaryTree* x, BinaryTree* y);
            // lowest (least) common ancestor. giving result in console method
            void findLCA(BinaryTree* root, BinaryTree* x, BinaryTree* y);

    };
};

#endif // BINARYTREE_H