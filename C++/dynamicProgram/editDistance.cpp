/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editDistance.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:54:37 by linyao            #+#    #+#             */
/*   Updated: 2024/10/15 00:49:49 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/algo.hpp"

/*
The edit distance problem. Given two strings $s$ and $t$, return 
the minimum number of editing steps required to transform $s$ into $t$. 
You can perform three types of edit operations on a string: 
insert a character, delete a character, or replace a character with any other character. 
After space optimization, it becomes equivalent to a complete knapsack problem
*/

class editDistance {
    private:
        string s, t;
        int n, m;
        vector<int> dp;

        int editDistanceDPOptimized() {
            // state transition function: 1st row
            for (int j = 1; j <= m; j++)
                dp[j] = j;
            // state transition function: the rest of the rows
            for (int i = 1; i <= n; i++) {
                //state transition function: 1st column
                int leftup = dp[0]; // temporarily store dp[i-1][j-1]
                dp[0] = i;
                // state transition function: the rest of the columns
                for (int j = 1; j <= m; j++) {
                    int tmp = dp[j];
                    if (s[i - 1] == t[j -1])
                        dp[j] = leftup; // if the two characters are the same, skip these two characters
                    else
                        dp[j] = min(min(dp[j - 1], dp[j]), leftup) + 1; // minimum number of edits = minimum number of edits from three operations(insert, remove, replace)+1
                    leftup = tmp; // update for the next round of dp[i-1,j-1]
                }
            }
            return (dp[m]);
        }

    public:
        editDistance(string a, string b, int x, int y, vector<int> dpx) : s(a), t(b), n(x), m(y), dp(dpx) {
        }
        int solve() {
            return (editDistanceDPOptimized());
        }
        void printED(int res) {
            cout << "Changing " << s << " to " << t << " requires a minimum of " << res << " edits." << endl;
        }
};

int main() {
    string a = "bag";
    string b = "pack";
    int x = a.length();
    int y = b.length();
    vector<int> dpx(y + 1, 0);

    editDistance ed(a, b, x, y, dpx);
    int res = ed.solve();
    ed.printED(res);
    
    return (0);
}