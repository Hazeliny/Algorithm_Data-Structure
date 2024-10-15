/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knapSack.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:55:11 by linyao            #+#    #+#             */
/*   Updated: 2024/10/15 23:40:14 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/algo.hpp"

class knapSack {
    private:
        int n; //number of items
        int cap; //capacity
        vector<int> wgt; //weights
        vector<int> val; //values
        vector<int> dp; // state transition table for space-optimized
        vector<vector<int>> dpp; // state transition table for dynamic programming
        
        // 0-1 knapsack: space optimized dynamic programming
        int knapSackDPOptimized() {
            for (int i = 1; i <=n; i++) {
                // traverse in reverse order
                for (int c = cap; c >= 1; c--) {
                    if (wgt[i - 1] <= c) {
                        dp[c] = max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
                    }
                }
            }
            return (dp[cap]);
        }
        
        int knapSackDP() {
            for (int i = 1; i <=n; i++) {
                for (int c = 1; c <= cap; c++) {
                    if (wgt[i - 1] > c) {
                        // if exceeding the knapsack capacity, don't choose item i
                        dpp[i][c] = dpp[i - 1][c];
                    } else {
                        //the greater value between not choosing and choosing item i
                        dpp[i][c] = max(dpp[i - 1][c], dpp[i - 1][c - wgt[i - 1]] + val[i - 1]);
                    }
                }
            }
            return (dpp[n][cap]);
        }

    public:
        knapSack(int x, int y, vector<int> a, vector<int> b, vector<int> dpx) : n(x), cap(y), wgt(a), val(b), dp(dpx) {   
        }
        knapSack(int x, int y, vector<int> a, vector<int> b, vector<vector<int>> dpy) : n(x), cap(y), wgt(a), val(b), dpp(dpy) {   
        }
        int solve(const char *method) {
            if (strcmp(method, "optimized") == 0)
                return (knapSackDPOptimized());
            else if (strcmp(method, "dynamic") == 0)
                return (knapSackDP());
            else
                return (-1);
        }
        void printSolution(int res) {
            cout << "The maximum value within the bag capacity is " << res << endl;
        }
};

int main() {
    vector<int> a = {10, 20, 30, 40, 50}; //weights
    vector<int> b = {50, 120, 150, 210, 240}; //values
    int x = a.size();
    int y = 50; //capacity
    // 0-1 knapsack: space optimized dynamic programming
    vector<int> dpx(y + 1, 0);
    knapSack ksOp(x, y, a, b, dpx);
    int res = ksOp.solve("optimized");
    ksOp.printSolution(res);
    // 0-1 knapsack: dynamic programming
    vector<vector<int>> dpy(x + 1, vector<int>(y + 1, 0));
    knapSack ksDp(x, y, a, b, dpy);
    res = ksDp.solve("dynamic");
    ksDp.printSolution(res);
    return (0);
}