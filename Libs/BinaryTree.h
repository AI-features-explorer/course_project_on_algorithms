#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <vector>
#include <string>
// ASCII chars
/** static std::string ch_hor = "-", ch_ver = "|", ch_ddia = "/",
 ch_rddia = "\\", ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-",
  ch_ddia_hor = "/-", ch_ver_spa = "| ";  **/

// UNICODE chars
static std::string ch_hor = "\u2500" /*─*/, ch_ver = "\u2502" /*│*/,
 ch_ddia = "\u250C" /*┌*/, ch_rddia = "\u2510" /*┐*/, ch_udia = "\u2514" /*└*/,
 ch_ver_hor = "\u251C\u2500" /*├─*/, ch_udia_hor = "\u2514\u2500" /*└─*/, 
 ch_ddia_hor = "\u250C\u2500" /*┌─*/, ch_ver_spa = "\u2502 " /*│ */;



namespace  CourseProjectOnAlgorithms{

    class BinaryTree {
        private:
            int _data;
            BinaryTree* _left;
            BinaryTree* _right;

        public:
            BinaryTree(int val) : data(_data = val), left(_left = nullptr), right(_right = nullptr) {}
            //prop
            const int &data;
            BinaryTree* &left;
            BinaryTree* &right;

            ~BinaryTree();
            BinaryTree* createBinaryTree(int arr[], int start, int end);
            void clearTree();
            static void clearTreeRecursive(BinaryTree* node) ;
            void printTree() const;
            static void PrintTreeLR( const BinaryTree* Tree, int level);
            static void PrintTreeUD(const BinaryTree* node);
            bool findPath( const BinaryTree* root, std::vector<int>& path, int target);
            int  findLCA(BinaryTree* root, int x, int y);

    };
};

#endif // BINARYTREE_H