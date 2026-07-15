class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;

    bool outOfBounds(int i, int j) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }

    pair<int, int> path(int i, int j,
                        vector<vector<pair<int, int>>>& dp,
                        const vector<string>& board) {

        if (!outOfBounds(i, j) || board[i][j] == 'X')
            return {-1, 0};

        if (dp[i][j].first != -2)
            return dp[i][j];

        // Reached E
        if (i == 0 && j == 0)
            return dp[i][j] = {0, 1};

        vector<pair<int, int>> val = {
            path(i - 1, j, dp, board),
            path(i, j - 1, dp, board),
            path(i - 1, j - 1, dp, board)
        };

        int maxi = -1;
        for (auto &k : val)
            maxi = max(maxi, k.first);

        if (maxi == -1)
            return dp[i][j] = {-1, 0};

        int ways = 0;
        for (auto &k : val) {
            if (k.first == maxi) {
                ways = (ways + k.second) % MOD;
            }
        }

        int score = maxi;
        if (board[i][j] >= '0' && board[i][j] <= '9')
            score += board[i][j] - '0';

        return dp[i][j] = {score, ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<pair<int, int>>> dp(
            m, vector<pair<int, int>>(n, {-2, -2}));

        pair<int, int> res = path(m - 1, n - 1, dp, board);

        if (res.first == -1)
            return {0, 0};

        return {res.first, res.second};
    }
};