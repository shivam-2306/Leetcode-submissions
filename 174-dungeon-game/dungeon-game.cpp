class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size()-1, n = dungeon[0].size()-1;
        vector<vector<int>> dp(dungeon.size()+1,vector<int>( dungeon[0].size()+1, INT_MIN));
        dp[m][n] = dungeon[m][n];
        if(dp[m][n]>0)dp[m][n] = 0;
        for(int i = m;i>=0;i--){
            for(int j = n;j>=0;j--){
                if(i == m && j == n) continue;
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]) + dungeon[i][j];
                if(dp[i][j]>0)dp[i][j]=0;
            }
        }
        // for(auto i:dp){
        //     for(auto j:i)
        //     cout<<j<<" ";
        //     cout<<endl;
        // }
        // return dp[0][0];
        if(dp[0][0] > 0){
            return 1;
        }
        else return dp[0][0]*-1+1;
        
    }
};