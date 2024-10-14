/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPath.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:49:16 by linyao            #+#    #+#             */
/*   Updated: 2024/10/14 22:40:07 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/algo.hpp"

class minPath {
    private:
        int n;
        int m;
        vector<vector<int>> grid;
        vector<vector<int>> mem;
        vector<vector<int>> dpd;
        vector<int> dp;

        // dynamic programming with optimized space complexity O(0)
        int minPathSumDPOptimized() {
            dp.assign(m, 0);
            // state transition function: 1st row
            dp[0] = grid[0][0];
            for (int j = 1; j < m; j++) {
                dp[j] = dp[j - 1] + grid[0][j];
            }
            // state transition function: the rest of the rows
            for (int i = 1; i < n; i++) {
                // state transition function: 1st column
                dp[0] = dp[0] + grid[i][0];
                // state transition function: rest of the columns
                for (int j = 1; j < m; j++) {
                    dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
                }
            }
            return dp[m - 1];
        }
        
        // dynamic programming
        int minPathSumDP() {
            dpd.assign(n, vector<int>(m, 0));
            dpd[0][0] = grid[0][0];
            //state transition function: 1st row
            for (int j = 1; j < m; j++) {
                dpd[0][j] = dpd[0][j - 1] + grid[0][j];
            }
            //state transition function: 1st column
            for (int i = 1; i < n; i++) {
                dpd[i][0] = dpd[i -1][0] + grid[i][0];
            }
            //state transition function: rest of the grid
            for (int i =1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    dpd[i][j] = min(dpd[i][j -1], dpd[i - 1][j]) + grid[i][j];
                }
            }
            return (dpd[n - 1][m - 1]);
        }

        // Momorized searching version of dynamic programming
        int minPathSumMemorization(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &mem) {
            // if it's the top-left cell, stop searching
            if (i == 0 && j == 0) {
                return (grid[0][0]);
            }
            // if the row or column index is out of bounds, return INT_MAX
            if (i < 0 || j < 0)
                return (INT_MAX);
            // if there is a record, return it
            if (mem[i][j] != -1)
                return (mem[i][j]);
            // the minimum path cost from left and top cells
            int up = minPathSumMemorization(i - 1, j, grid, mem);
            int left = minPathSumMemorization(i, j - 1, grid, mem);
            // record and return the minimum path cost from top-left cell to (i, j)
            mem[i][j] = min(left, up) != INT_MAX ? min(left, up) + grid[i][j] : INT_MAX;
            return (mem[i][j]);
        }
        
        // brute force version of dynamic programming
        int minPathSumDFS(int i, int j, vector<vector<int>> &grid) {
            // if it's the top-left cell, stop searching
            if (i == 0 && j == 0)
                return (grid[0][0]);
            // if the row or column index is out of bounds, return INT_MAX
            if (i < 0 || j < 0)
                return (INT_MAX);
            // calculate the minimum path cost from top-left to (i-1,j) and (i, j-1)
            int up = minPathSumDFS(i - 1, j, grid);
            int left = minPathSumDFS(i, j - 1, grid);
            // return the minimum path cost from top-left cell to (i, j)
            return (min(left, up) != INT_MAX ? min(left, up) + grid[i][j] : INT_MAX);
        } 
        
    public:
        // constructor
        minPath(int x, int y,vector<vector<int>> gridx) : n(x), m(y), grid(gridx) {
        }

        minPath(int x, int y, vector<vector<int>> gridx, vector<vector<int>> memx) : n(x), m(y), grid(gridx), mem(memx) {
        }
        
        int minPathSum(const char *method) {
            if (strcmp(method, "optimized space complexity") == 0)
                return (minPathSumDPOptimized());
            else if (strcmp(method, "dynamic programming") == 0)
                return (minPathSumDP());
            else if (strcmp(method, "memorization") == 0)
                return (minPathSumMemorization(n - 1, m -1, grid, mem));
            else if (strcmp(method, "brute force") == 0)
                return (minPathSumDFS(n - 1, m - 1, grid));
            else
                return (0);
        }
        void printMP(int res) {
            cout << "The minimum path sum from the top left corner to the bottom right corner is " << res << endl;
        }
};

int main() {
    vector<vector<int>> gridx = {{1, 3, 1, 5}, {2, 2, 4, 2}, {5, 3, 2, 1}, {4, 3, 5, 2}};
    int x = gridx.size(), y = gridx[0].size();
    // optimized
    minPath mp(x, y, gridx);
    int res = mp.minPathSum("optimized space complexity");
    mp.printMP(res);
    // dynamic programming
    minPath mpdp(x, y, gridx);
    int resdp = mp.minPathSum("dynamic programming");
    mpdp.printMP(resdp);
    // memorization
    vector<vector<int>> memx(x, vector<int>(y, -1));
    minPath mpmem(x, y, gridx, memx);
    int resmem = mpmem.minPathSum("memorization");
    mpmem.printMP(resmem);
    // brute force
    minPath mpbf(x, y, gridx);
    int resbf = mpbf.minPathSum("brute force");
    mpbf.printMP(resbf);
    return (0);
}