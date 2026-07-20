class Solution {
public:
    int m, n;

    pair<int, int> indexFilter(int i, int j, int shift) {
        int total = (j - 1) + shift;
        int y = total % n;
        int vertical = total / n;
        int x = ((i - 1) + vertical) % m;
        return {x + 1, y + 1};
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        k %= (m * n);

        vector<vector<int>> res(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pair<int, int> p = indexFilter(i + 1, j + 1, k);
                res[p.first - 1][p.second - 1] = grid[i][j];
            }
        }

        return res;
    }
};