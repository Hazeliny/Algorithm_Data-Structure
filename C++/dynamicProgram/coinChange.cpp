/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coinChange.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:39:13 by linyao            #+#    #+#             */
/*   Updated: 2024/10/17 13:19:09 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/algo.hpp"

/*
给定 $n$ 种硬币，第 $i$ 种硬币的面值为 $coins[i - 1]$ ，目标金额为 $amt$
**每种硬币可以重复选取**，问能够凑出目标金额的最少硬币数量。
如果无法凑出目标金额，则返回 $-1$ 
*/
class coinChange {
    private:
        int n; // number of coins
        int amt; // maximum amount
        int MAX;
        vector<int> coins;
        vector<int> dp;

        int coinChangeDPOptimize() {
            dp[0] = 0;
            for (int i = 1; i <= n; i++) {
                for (int a = 1; a <= amt; a++) {
                    if (coins[i - 1] > a) {
                        // if exceeding the target amount, do not choose coin i
                        dp[a] = dp[a];
                    } else {
                        // the smaller calue between not choosing and choosing coin i
                        dp[a] = min(dp[a], dp[a - coins[i - 1]] + 1);
                    }
                }
            }
            return dp[amt] != MAX ? dp[amt] : -1;
        }

    public:
        coinChange(int nx, int amtx, int MAXx, vector<int> coinsx, vector<int> dpx) : n(nx), amt(amtx), MAX(MAXx), coins(coinsx), dp(dpx) {
            
        }
        int solve() {
            return (coinChangeDPOptimize());
        }
        void printCC(int res) {
            cout << "The minimum number of coins required to make up the target amount is " << res << endl;
        }
};

int main() {
    int nx; // number of coins
    int amtx = 4; // maximum amount
    int MAXx = amtx + 1; // amount exceeding maximum amount
    vector<int> coinsx = {1, 2, 5}; // coins available
    nx = coinsx.size(); // number of coins
    vector<int> dpx(amtx + 1, MAXx); // initialize state transition with MAXx
    
    coinChange cc(nx, amtx, MAXx, coinsx, dpx);
    int res = cc.solve();
    cc.printCC(res);
    return (0);
}