/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaryTree.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:17:31 by linyao            #+#    #+#             */
/*   Updated: 2024/10/17 15:06:19 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/algo.hpp"

/*
给定一棵二叉树的前序遍历 `preorder` 和中序遍历 `inorder` 
请从中构建二叉树，返回二叉树的根节点。假设二叉树中没有值重复的节点
*/

treeNode *dfs(vector<int> &preorder, unordered_map<int, int> &inorderMap, \
                                                    int i, int l, int r) {
    // i is the index of the current root node in preorder
    // l and r are the indices of the left and right subtrees in inorder
    if (r - l < 0)
        return (NULL);
        treeNode *root = new treeNode(preorder[i]);
        int m = inorderMap[preorder[i]];
        root->left = dfs(preorder, inorderMap, i + 1, l, m - 1);
        root->right = dfs(preorder, inorderMap, i + 1 + m - l, m + 1, r);
        return (root);    
}

treeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    unordered_map<int, int> inorderMap;
    // initialize inorderMap to establish the mapping 
    // between elements of inorder and their indices in inorder
    for (int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }
    treeNode *root = dfs(preorder, inorderMap, 0, 0, inorder.size() - 1);
    return (root);
}

int main() {
    vector<int> preorder = {3, 9, 2, 1, 7};
    vector<int> inorder = {9, 3, 1, 2, 7};
    cout << "preorder traversal = ";
    printVector(preorder);
    cout << "inorder traversal = ";
    printVector(inorder);
    
    treeNode *root = buildTree(preorder, inorder);
    cout << "buildTree result = \n";
    printTree(root);
    
    return (0);
}