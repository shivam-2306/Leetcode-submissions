class Solution {
public:
    int calculate(vector<int>& stoneValue, int i, vector<int>& dp){
        int n = stoneValue.size();
        if(i == n){
            return 0;
        }
        
        if(dp[i] != -1e9){
            return dp[i];
        }
        
        int sum = 0;
        int best = -1e9;
        
        for(int k = 0; k < 3 && i + k < n; k++){
            sum += stoneValue[i + k];
            best = max(best, sum - calculate(stoneValue, i + k + 1, dp));
        }
        
        return dp[i] = best;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, -1e9);
        
        int maxi = calculate(stoneValue, 0, dp);
        
        if(maxi > 0) return "Alice";
        if(maxi == 0) return "Tie";
        return "Bob";
    }
};