/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanota.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:47:05 by linyao            #+#    #+#             */
/*   Updated: 2024/10/17 15:02:32 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/algo.hpp"

/*
分治算法求解汉诺塔问题 
divide and conquer algorithm to solve the Tower of Hanoi problem
*/
class HanoiTower {
    private:
        vector<int> A;
        vector<int> B;
        vector<int> C;

    void move(vector<int> &src, vector<int> &des) {
        // get the disc from the top of src
        int pan = src.back();
        src.pop_back();
        // place the disc on the top of des
        des.push_back(pan);
    }

    void dfs(int i, vector<int> &src, vector<int> &buf, vector<int> &des) {
        if (i == 1) {
            move(src, des);
            return ;
        }
    
        dfs(i - 1, src, des, buf);
        move (src, des);
        dfs(i - 1, buf,src, des);
    }
    
    public:
    HanoiTower(vector<int> discs) : A(discs), B(), C() {} // constructor to initialize the towers

    void solve() {
        int n = A.size();
        // move the top n discs from A to C by means of B
        dfs(n, A, B, C);
    }
    void printState() const {
        cout << "A: "; printVector(A);
        cout << "B: "; printVector(B);
        cout << "C: "; printVector(C);
    }
};

int main() {
    vector<int> discs = {6, 5, 4, 3, 2, 1};
    HanoiTower hanoi(discs);
    
    cout << "Initial state: \n";
    hanoi.printState();
    hanoi.solve();
    
    cout << "After disk movement: \n";
    hanoi.printState();
    
    return (0);
}