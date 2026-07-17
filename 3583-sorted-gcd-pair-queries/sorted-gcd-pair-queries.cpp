class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal = *max_element(nums.begin(), nums.end());

        // Frequency of each number
        vector<long long> freq(maxVal + 1, 0);
        for (int x : nums)
            freq[x]++;

        // Count numbers divisible by each d
        vector<long long> divisible(maxVal + 1, 0);
        for (int d = 1; d <= maxVal; d++) {
            for (int multiple = d; multiple <= maxVal; multiple += d)
                divisible[d] += freq[multiple];
        }

        // Total pairs divisible by d
        vector<long long> exact(maxVal + 1, 0);
        for (int d = 1; d <= maxVal; d++) {
            exact[d] = divisible[d] * (divisible[d] - 1) / 2;
        }

        // Inclusion-Exclusion:
        // exact[d] = pairs whose gcd is exactly d
        for (int d = maxVal; d >= 1; d--) {
            for (int multiple = 2 * d; multiple <= maxVal; multiple += d)
                exact[d] -= exact[multiple];
        }

        // Prefix sums
        vector<long long> prefix(maxVal + 1, 0);
        for (int d = 1; d <= maxVal; d++)
            prefix[d] = prefix[d - 1] + exact[d];

        // Answer queries
        vector<int> ans;
        for (long long q : queries) {
            int g = lower_bound(prefix.begin(), prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};