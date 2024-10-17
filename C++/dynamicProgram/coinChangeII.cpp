/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coinChangeII.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:24:01 by linyao            #+#    #+#             */
/*   Updated: 2024/10/17 13:53:19 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/algo.hpp"

/*
给定 $n$ 种硬币，第 $i$ 种硬币的面值为 $coins[i - 1]$ ，目标金额为 $amt$
每种硬币可以重复选取，**问凑出目标金额的硬币组合数量**。
*/
class coinChangeII {
    private:
        int n;
        int amt;
        vector<int> coins;
        vector<int> dp;

        int coinChangeIIOptimize() {
            dp[0] = 1;
            for (int i = 1; i <= n; i++) {
                for (int a = 1; a <= amt; a++) {
                    if (coins[i - 1] > a) {
                        dp[a] = dp[a];
                    } else {
                        dp[a] = dp[a] + dp[a - coins[i - 1]];
                    }
                }
            }
            return (dp[amt]);
        }

    public:
        coinChangeII(int nx, int amtx, vector<int> coinsx, vector<int> dpx) : n(nx), amt(amtx), coins(coinsx), dp(dpx) {
            
        }
        int solve() {
            return (coinChangeIIOptimize());
        }
        void printCCII(int res) {
            cout << "The number of coin combinations to make up the target amount is " << res << endl;
        }
};

int main() {
    int nx;
    int amtx = 5;
    vector<int> coinsx = {1, 2, 5};
    vector<int> dpx(amtx + 1, 0);
    nx = coinsx.size();
    
    coinChangeII ccii(nx, amtx, coinsx, dpx);
    int res = ccii.solve();
    ccii.printCCII(res);
    return (0);
}