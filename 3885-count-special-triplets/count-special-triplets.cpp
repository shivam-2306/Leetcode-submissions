class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, signed long long> pairCheck;
        unordered_map<int, int> numberAppearance;
        unsigned long long int result = 0;
        int mod = 1e9 + 7;
        int numberOfZeroes = 0;
        for (auto i : nums) {
            if (i == 0) {
                numberOfZeroes++;
                continue;
            }
            if (numberAppearance.find(i * 2) != numberAppearance.end()) {
                pairCheck[i] = (pairCheck[i] + numberAppearance[i * 2]) % mod;
            }
            if (i % 2 == 0) {
                if (numberAppearance.find(i / 2) != numberAppearance.end()) {
                    result = (result + pairCheck[i / 2]) % mod;
                }
            }
            numberAppearance[i]++;
        }
        if (numberOfZeroes < 3)
            return result;
        long long n = numberOfZeroes;

        auto modpow = [&](long long a, long long b) {
            long long res = 1;
            while (b) {
                if (b & 1)
                    res = (res * a) % mod;
                a = (a * a) % mod;
                b >>= 1;
            }
            return res;
        };

        long long temp1 = ((long long)(n - 2) * (n - 1)) % mod;
        long long temp2 = ((long long)n * temp1) % mod;

        long long inv6 = modpow(6, mod - 2);

        temp2 = (temp2 % mod * inv6) % mod;

        result = (result + temp2) % mod;

        return result;
    }
};