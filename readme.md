# Course project on algorithms

In the course of the course work, we developed a binary tree structure and implemented an algorithm to find the Lowest Common Ancestor (LCA) of two nodes in this tree.

One of the important problems solved with a binary tree is finding the least common ancestor of two nodes. In the course work we implemented a non-recursive algorithm for finding the least common ancestor (findLCA) and submethod (findPath)

### Here is the code:

#### `Submethod`

```cpp
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
```

#### `Main method`

```cpp
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
```

### Here the working example

<video width="520" height="340" controls>
  <source src="image/readme/1713705507036.mp4" type="video/mp4">
</video>

### `note: the g++ compiler was used for this work`
  