//
//  main.cpp
//  105 Construct Binary Tree from Preorder and Inorder Traversal
//
//  Created by 睿于 on 2020/6/30.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 105 Construct Binary Tree from Preorder and Inorder Traversal / Medium / Given preorder and inorder traversal of a tree, construct the binary tree. Note: You may assume that duplicates do not exist in the tree.

    For example, given
    preorder = [3,9,20,15,7]
    inorder = [9,3,15,20,7]
    Return the following binary tree:
        3
       / \
      9  20
        /  \
       15   7
 */

#include <iostream>
#include <vector>
using namespace::std;

class TreeNode{
public:
    // variables
    int val;
    TreeNode *left;
    TreeNode *right;
    
    // construction function
    TreeNode(int val = 0, TreeNode *left = nullptr, TreeNode *right = nullptr){
        this->val = val;
        this->left = left;
        this->right = right;
    }
    // deconstruction function
    ~TreeNode(){}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    TreeNode* root = nullptr;
    if (preorder.size() != 0){
        int rootVal = preorder[0];
        root = new TreeNode(rootVal);
        // divide into two subtrees, recrusive
        auto it = find(inorder.begin(), inorder.end(), rootVal);
        int rootIdx = int(it - inorder.begin());
        vector<int> inLeft = {inorder.begin(), it}; // left child inorder traversal
        vector<int> inRight = {it+1, inorder.end()}; // right child inorder traversal
        vector<int> preLeft = {preorder.begin()+1, preorder.begin()+1+rootIdx}; // left child preorder traversal
        vector<int> preRight = {preorder.begin()+1+rootIdx, preorder.end()}; // right child preorder traversal
        root->left = buildTree(preLeft, inLeft);
        root->right = buildTree(preRight, inRight);
    }
    return root;
}

// preorder print
void printTree(TreeNode* tree){
    cout<< tree->val << endl;
    if (tree->left != nullptr)
        printTree(tree->left);
    if (tree->right != nullptr)
        printTree(tree->right);
    return;
}

int main(int argc, const char * argv[]) {
    // test
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* tree = buildTree(preorder, inorder);
    printTree(tree);
    return 0;
}
