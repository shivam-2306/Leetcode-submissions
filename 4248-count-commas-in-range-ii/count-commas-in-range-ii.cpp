class Solution {
public:
    using ull = unsigned long long;

    long long countCommas(long long n) {
        vector<ull> arr = {
            1000ULL,
            1000000ULL,
            1000000000ULL,
            1000000000000ULL,
            1000000000000000ULL,
            1000000000000000000ULL
        };

        ull value = 0;

        for (int i = 0; i < 5; i++) {
            if (n < arr[i])
                break;

            ull val = min<ull>(n, arr[i + 1] - 1);
            val -= arr[i]-1;

            value += val * (i + 1);
        }

        return value;
    }
};