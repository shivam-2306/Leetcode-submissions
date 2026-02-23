class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;

        int total = 1 << k;
        vector<bool> seen(total, false);

        int hash = 0;
        int mask = total - 1;

        for (int i = 0; i < s.size(); i++) {
            hash = ((hash << 1) & mask) | (s[i] - '0');

            if (i >= k - 1 && !seen[hash]) {
                seen[hash] = true;
                total--;
                if (total == 0) return true;
            }
        }
        return false;
    }
};