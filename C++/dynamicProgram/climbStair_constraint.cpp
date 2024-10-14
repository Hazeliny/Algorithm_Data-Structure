/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climbStair_constraint.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:52:50 by linyao            #+#    #+#             */
/*   Updated: 2024/10/13 23:51:53 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/algo.hpp"

// 限制条件是不能连续两轮跳1阶 constraint: cannot jump 1 step consecutively
class climbStairConstr {
    private:
        int n;
        vector<vector<int>> dp;
        
        int climbStairConstraintDP(int m) {
            if (m == 1 || m == 2) {
                return (1);
            }
            for (int i = 3; i <= m; i++) {
                // state transition function
                dp[i][1] = dp[i - 1][2];
                dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
            }
            return (dp[m][1] + dp[m][2]);
        }
        
    public:
        climbStairConstr(int x, vector<vector<int>> dpx) : n(x), dp(n + 1, vector<int>(3, 0)) {
            // initialize state: preset the smallest subproblem solution
            dp[1][1] = dpx[0][0]; // feasible scheme
            dp[1][2] = dpx[0][1]; // impossible scheme
            dp[2][1] = dpx[1][0]; // impossible scheme: cannot jump 1 step consecutively
            dp[2][2] = dpx[1][1]; // feasible scheme
        }
        
        int climbStairConstraint() {
            return (climbStairConstraintDP(n));
        }
        void printDP(int res) {
            cout << "There are " << res << " ways to climb " << n << " stairs." << endl;
        }
};

int main () {
    vector<vector<int>> dpx = {{1, 0}, {0, 1}};
    climbStairConstr csc(9, dpx);
    int res = csc.climbStairConstraint();
    csc.printDP(res);
    return (0);
}