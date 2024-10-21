/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   climbStair_constraint.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:52:50 by linyao            #+#    #+#             */
/*   Updated: 2024/10/17 14:57:12 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/algo.hpp"

/*
给定一个共有 $n$ 阶的楼梯，你每步可以上 $1$ 阶或者 $2$ 阶，**但不能连续两轮跳 $1$ 阶**
问有多少种方案可以爬到楼顶？（多考虑前面一个状态，消除无后效性）
*/
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

/*
Q：给定一个共有 $n$ 阶的楼梯，你每步可以上 $1$ 阶或者 $2$ 阶，请问有多少种方案可以爬到楼顶？（无后效性）
回溯穷举所有可能性：参考{climbing_stairs_backtrack}
暴力搜索，状态转移：dp[i] = dp[i-1] + dp[i-2] 参考{climbing_stairs_dfs}
记忆化搜索，状态转移：dp[i] = dp[i-1] + dp[i-2] 参考{climbing_stairs_dfs_mem} 从顶到底
动态规划，状态转移：dp[i] = dp[i-1] + dp[i-2] 参考{climbing_stairs_dp} 从底到顶
动态规划空间优化，“滚动变量”或“滚动数组”，参考{climbing_stairs_dp}中的int climbingStairsDPComp(int n)
Q：爬楼梯最小代价：给定一个楼梯，每步可以上 $1$ 阶或者 $2$ 阶，每一阶楼梯上都贴有一个非负整数，
表示你在该台阶所需要付出的代价。给定一个非负整数数组 $cost$ ，其中 $cost[i]$ 表示在第 $i$ 个台阶需要付出的代价，
$cost[0]$ 为地面（起始点）。计算最少需要付出多少代价才能到达顶部？（无后效性）
动态规划，dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]，参考min_cost_climbing_stairs_dp

Q：（有严重后效性）给定一个共有 $n$ 阶的楼梯，你每步可以上 $1$ 阶或者 $2$ 阶。**规定当爬到第 $i$ 阶时，
系统自动会在第 $2i$ 阶上放上障碍物，之后所有轮都不允许跳到第 $2i$ 阶上**。例如，前两轮分别跳到了第 $2$、$3$ 阶上，
则之后就不能跳到第 $4$、$6$ 阶上。请问有多少种方案可以爬到楼顶？
用启发式搜索、遗传算法、强化学习等，在有限时间内得到可用的局部最优解。
*/