/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:19:21 by linyao            #+#    #+#             */
/*   Updated: 2024/10/17 21:19:00 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <stdexcept>

using namespace std;

struct treeNode {
    int val{};
    int height = 0;
    treeNode *parent{};
    treeNode *left{};
    treeNode *right{};
    treeNode() = default;
    explicit treeNode(int x, treeNode *parent = nullptr) : val(x), parent(parent) {      
    }
};

struct Trunk {
    Trunk *prev;
    string str;
    Trunk(Trunk *prev, string str) {
        this->prev = prev;
        this->str = str;
    }
};

void showTrunk(Trunk *p) {
    if (p == nullptr) {
        return ;
    }
    
    showTrunk(p->prev);
    cout << p->str;
}

// print tree in level order
void printTree(treeNode *root, Trunk *prev, bool isRight) {
    if (root == nullptr) {
        return ;
    }
    string prev_str = "   ";
    Trunk trunk(prev, prev_str);
    
    printTree(root->right, &trunk, true);
    if (!prev) {
        trunk.str = "/---";
        prev_str = "   |";
    } else {
        trunk.str = "\\---";
        prev->str = prev_str;
    }

    showTrunk(&trunk);
    cout << " " << root->val << endl;

    if (prev) {
        prev->str = prev_str;
    }
    trunk.str = "   |";

    printTree(root->left, &trunk, false);
}

void printTree(treeNode *root) {
    printTree(root, nullptr, false);
}

template <typename T> string strJoin(const T &vec, const string &delimiter) {
    ostringstream s;
    for (const auto &i : vec) {
        if (&i != &vec[0]) {
            s << delimiter;
        }
        s << i;
    }
    return s.str();
}

template <typename T> string getVectorString(vector<T> &list) {
    return "[" + strJoin(list, ", ") + "]";
}

template <typename T> void printVector(vector<T> list) {
    cout << getVectorString(list) << '\n';
}

// 顶点类
struct Vertex {
    int val;
    Vertex(int x) : val(x) {
    }
}