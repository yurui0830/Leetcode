//
//  main.cpp
//  106 Construct Binary Tree from Inorder and Postorder Traversal
//
//  Created by 睿于 on 2020/6/30.
//  Copyright © 2020 睿于. All rights reserved.
//
/* 106 Construct Binary Tree from Inorder and Postorder Traversal / Medium / Given inorder and postorder traversal of a tree, construct the binary tree. Note: You may assume that duplicates do not exist in the tree.

    For example, given
    inorder = [9,3,15,20,7]
    postorder = [9,15,7,20,3]
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

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    TreeNode* root = nullptr;
    if (postorder.size() != 0){
        int rootVal = postorder.back();
        postorder.pop_back();
        root = new TreeNode(rootVal);
        // divide into two subtrees, recrusive
        auto it = find(inorder.begin(), inorder.end(), rootVal);
        int nLeft = int(it - inorder.begin()); // number of the left subtree
        int nRight = int(postorder.size()) - nLeft; // number of the right subtree
        vector<int> inLeft = {inorder.begin(), it}; // left child inorder traversal
        vector<int> inRight = {it+1, inorder.end()}; // right child inorder traversal
        vector<int> postLeft = {postorder.begin(), postorder.begin()+nLeft}; // left child postorder traversal
        vector<int> postRight = {postorder.end()-nRight, postorder.end()}; // right child postorder traversal
        root->left = buildTree(inLeft, postLeft);
        root->right = buildTree(inRight, postRight);
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
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* tree = buildTree(inorder, postorder);
    printTree(tree);
    return 0;
}
