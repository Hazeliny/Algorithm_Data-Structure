/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPath.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:49:16 by linyao            #+#    #+#             */
/*   Updated: 2024/10/14 13:30:08 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/algo.hpp"

class minPath {
    private:
        int n;
        int m;
        vector<vector<int>> grid;
        vector<int> dp;

        int minPathSumDPOptimized() {
            dp.assign(m, 0);
            dp[0] = grid[0][0];
            for (int j = 1; j < m; j++) {
                dp[j] = dp[j - 1] + grid[0][j];
            }
            for (int i = 1; i < n; i++) {
                dp[0] = dp[0] + grid[i][0];
                for (int j = 1; j < m; j++) {
                    dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
                }
            }
            return dp[m - 1];
        }
        
    public:
        minPath(int x, int y,vector<vector<int>> gridx) : n(x), m(y), grid(gridx) {
        }
        
        int minPathSum() {
            return (minPathSumDPOptimized());
        }
        void printMP(int res) {
            cout << "The minimum path sum from the top left corner to the bottom right corner is " << res << endl;
        }
};

int main() {
    vector<vector<int>> gridx = {{1, 3, 1, 5}, {2, 2, 4, 2}, {5, 3, 2, 1}, {4, 3, 5, 2}};
    int x = gridx.size(), y = gridx[0].size();
    minPath mp(x, y, gridx);
    int res = mp.minPathSum();
    mp.printMP(res);
    return (0);
}