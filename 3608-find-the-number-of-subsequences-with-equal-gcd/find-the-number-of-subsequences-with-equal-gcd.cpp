class Solution {
public:
    vector<vector<vector<int>>> dp;
    int mod = 1e9 + 7;
    int n = 0;

    int gcd(int a, int b) {
        while (b) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    int recursive(vector<int>& nums, int index, int gcd1, int gcd2) {
        if (index == n)
            return (gcd1 == gcd2 && gcd1);

        if (dp[index][gcd1][gcd2] != -1)
            return dp[index][gcd1][gcd2];

        int res1 = recursive(nums, index + 1, gcd(gcd1, nums[index]), gcd2);
        int res2 = recursive(nums, index + 1, gcd1, gcd(gcd2, nums[index]));
        int res3 = recursive(nums, index + 1, gcd1, gcd2);

        return dp[index][gcd1][gcd2] =
            ((res1 + res2) % mod + res3) % mod;
    }

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();

        dp.assign(
            n + 1,
            vector<vector<int>>(
                201,
                vector<int>(201, -1)
            )
        );

        return recursive(nums, 0, 0, 0);
    }
};