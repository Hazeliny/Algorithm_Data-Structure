/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unboundedKnapSack.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 23:14:55 by linyao            #+#    #+#             */
/*   Updated: 2024/10/16 23:35:22 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/algo.hpp"

class unboundedKnapSack {
    private:
        int n; // numbers of items
        int cap; // capacity of knapsack
        vector<int> dp; // state transition table
        vector<int> wgt; // weights of items
        vector<int> val; // values of items

        int unboundedKnapSackDPOptimize() {
            for (int i = 1; i <= n; i++) {
                for (int c = 1; c <=cap; c++) {
                    if (wgt[i - 1] > c) {
                        // if exceeding the knapsack capacity, don't choose item i
                        dp[c] = dp[c];
                    } else {
                        // the greater value between not choosing and choosing item i
                        dp[c] = max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
                    }
                }
            }
            return (dp[cap]);
        }

    public:
        unboundedKnapSack(int nx, int capx, vector<int> wgtx, vector<int> valx, vector<int> dpx) : n(nx), cap(capx), wgt(wgtx), val(valx), dp(dpx) {
            
        }
        int solve() {
            return (unboundedKnapSackDPOptimize());
        }
        void printUKS(int res) {
            cout << "The maximum value within the bag capacity is " << res << endl;
        }
};

int main() {
    vector<int> wgtx = {1, 2, 3};
    vector<int> valx = {5, 11, 15};
    int nx = wgtx.size();
    int capx = 4;
    vector<int> dpx(capx + 1, 0);
    
    unboundedKnapSack uks(nx, capx, wgtx, valx, dpx);
    int res = uks.solve();
    uks.printUKS(res);
    return (0);
}