#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<char>>& grid, int row, int col,
             vector<vector<bool>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        if (row < 0 or col < 0 or row >= n || col >= m ||
            grid[row][col] == '0' || vis[row][col])
            return;

        vis[row][col] = true;

        dfs(grid, row + 1, col, vis);
        dfs(grid, row - 1, col, vis);
        dfs(grid, row, col + 1, vis);
        dfs(grid, row, col - 1, vis);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    dfs(grid, row, col, vis);
                    count++;
                }
            }
        }
        return count;
    }
};