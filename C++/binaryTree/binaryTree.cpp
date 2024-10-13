/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaryTree.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:17:31 by linyao            #+#    #+#             */
/*   Updated: 2024/10/13 14:33:08 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/algo.hpp"

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