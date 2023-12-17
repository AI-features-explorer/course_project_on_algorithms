#pragma once
#include <vector>
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
            // Finds the path, returns true if path exists otherwise false
            bool findPath( const BinaryTree* root, std::vector<int>& path, int target);
            // lowest (least) common ancestor. giving result in console method
            int  findLCA(BinaryTree* root, int x, int y);

    };
};

#endif // BINARYTREE_H