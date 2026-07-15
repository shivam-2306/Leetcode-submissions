class Solution {
public:
    int dp[201][201][201];
    int mod = 1e9+7;
    int n = 0;
    int gcd (int a, int b){
        while(b!=0){
            int temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }
    int recursive(vector<int>& nums, int index, int gcd1, int gcd2){
        if(index == n){
            return (gcd1 == gcd2 && gcd1 & gcd2);
        }
        if(dp[index][gcd1][gcd2] != -1){
            return dp[index][gcd1][gcd2];
        }
        int res1 = recursive(nums, index+1, gcd(gcd1,nums[index]), gcd2);
        int res2 = recursive(nums, index+1, gcd1, gcd(gcd2, nums[index]));
        int res3 = recursive(nums, index+1, gcd1, gcd2);
        dp[index][gcd1][gcd2] = ((res1+res2)%mod+res3)%mod;
        return dp[index][gcd1][gcd2];
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        n = nums.size();
        return recursive(nums, 0, 0, 0);        
    }
};