class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long factorial(long long n) {
        long long result = 1;
        for (long long i = 1; i <= n; i++) {
            result = (result * i) % MOD;
        }
        return result%MOD;
    }
    int countPermutations(vector<int>& c) {
        int firstComplexity = c[0];
        for (int i = 1; i < c.size(); i++) {
            if (firstComplexity >= c[i])
                return 0;
        }
        return factorial(c.size()-1)%MOD;
    }
};