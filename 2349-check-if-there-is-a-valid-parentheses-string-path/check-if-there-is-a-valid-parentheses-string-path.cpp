class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool validPaths(vector<vector<char>>& grid, int i, int j, int balance) {
        if (i >= m || j >= n)
            return false;

        if (grid[i][j] == '(') {
            balance++;
        } else {
            balance--;
            if (balance < 0)
                return false;
        }

        if (i == m - 1 && j == n - 1) {
            return balance == 0;
        }

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        return dp[i][j][balance] =
            validPaths(grid, i + 1, j, balance) ||
            validPaths(grid, i, j + 1, balance);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<vector<int>>(
                         n, vector<int>(m + n + 1, -1)));
                         
        if ((m + n) % 2 == 0)
            return false;

        return validPaths(grid, 0, 0, 0);
    }
};