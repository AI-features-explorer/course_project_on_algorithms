#include "BinaryTree.h"
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <tuple>
#include <stdexcept>

using namespace CourseProjectOnAlgorithms;

BinaryTree::~BinaryTree() {
    delete left;
   delete right;
}

BinaryTree::BinaryTree(int arr[], int start, int end)  : data(_data = -1), left(_left = nullptr), right(_right = nullptr)  {

    if (start > end) {
        this->left = nullptr;
        this->right = nullptr;
        return;
    }
    int mid = (start + end) / 2;
    this->data = arr[mid];
    this->left = (start <= mid - 1) ? new BinaryTree(arr, start, mid - 1) : nullptr;
    this->right = (mid + 1 <= end) ? new BinaryTree(arr, mid + 1, end) : nullptr;
}

void BinaryTree::printTree() const {
    PrintTreeUD(this);
}

void BinaryTree::PrintTreeUD(const BinaryTree* node) {
        #define _MAX(x, y) ((x) > (y) ? (x) : (y))
        #define _MIN(x, y) ((x) < (y) ? (x) : (y))

        auto RepStr = [](std::string const & s, size_t cnt) {
            if (ptrdiff_t(cnt) < 0)
                throw std::runtime_error("RepStr: Bad value " + std::to_string(ptrdiff_t(cnt)) + "!");
            std::string r;
            for (size_t i = 0; i < cnt; ++i)
                r += s;
            return r;
        };
        std::function<std::tuple<std::vector<std::string>, size_t, size_t>(BinaryTree const * node, bool)> Rec;
        
        Rec = [&RepStr, &Rec](const BinaryTree * node, bool left){
            std::vector<std::string> lines;
            if (!node)
                return std::make_tuple(lines, size_t(0), size_t(0));
            auto sval = std::to_string(node->data);
            auto resl = Rec(node->left, true), resr = Rec(node->right, false);
            auto const & vl = std::get<0>(resl);
            auto const & vr = std::get<0>(resr);
            auto cl = std::get<1>(resl), cr = std::get<1>(resr), lss = std::get<2>(resl), rss = std::get<2>(resr);
            size_t lv = sval.size();
            size_t ls = vl.size() > 0 ? lss : size_t(0);
            size_t rs = vr.size() > 0 ? rss : size_t(0);
            size_t lis = ls == 0 ? lv / 2 : _MAX(int(lv / 2 + 1 - (ls - cl)), 0);
            size_t ris = rs == 0 ? (lv + 1) / 2 : _MAX(int((lv + 1) / 2 - cr), (lis > 0 ? 0 : 1));
            size_t dashls = (ls == 0 ? 0 : ls - cl - 1 + lis - lv / 2), dashrs = (rs == 0 ? 0 : cr + ris - (lv + 1) / 2);

            lines.push_back(
                (ls == 0 ? "" : (RepStr(" ", cl) + ch_ddia + RepStr(ch_hor, dashls))) +
                sval + (rs == 0 ? "" : (RepStr(ch_hor, dashrs) + ch_rddia + RepStr(" ", rs - cr - 1)))
            );

            for (size_t i = 0; i < _MAX(vl.size(), vr.size()); ++i) {
                std::string sl = RepStr(" ", ls), sr = RepStr(" ", rs);
                if (i < vl.size()) sl = vl[i];
                if (i < vr.size()) sr = vr[i];
                sl = sl + RepStr(" ", lis);
                sr = RepStr(" ", ris) + sr;
                lines.push_back(sl + sr);
            }
            return std::make_tuple(lines, (left || ls + lis == 0 || lv % 2 == 1) ? ls + lis : ls + lis - 1, ls + lis + ris + rs);
        };
        auto v = std::get<0>(Rec(node, true));
        for (size_t i = 0; i < v.size(); ++i)
            std::cout << v[i] << std::endl;
            
        #undef _MAX
        #undef _MIN
    }

bool BinaryTree::findPath(const BinaryTree* root, std::vector<int>& path, int target){
     if (root == NULL) 
        return false;
 
    path.push_back(root->data);

    if (root->data == target)
        return true;
 
    if ((root->left && findPath(root->left, path, target))
        || (root->right && findPath(root->right, path, target)))
        return true;
 
    path.pop_back();
    return false;
}

int  BinaryTree::findLCA(BinaryTree* root, int x, int y){
            
    std::vector<int> path1, path2;
 
    if (!findPath(root, path1, x)
        || !findPath(root, path2, y))
        return -1;
 
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;
    return path1[i - 1]; 
}

