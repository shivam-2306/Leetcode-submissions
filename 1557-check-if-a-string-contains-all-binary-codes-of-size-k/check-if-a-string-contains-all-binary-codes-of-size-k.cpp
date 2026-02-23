class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;

        vector<bool> array(1 << k, false);

        string temp = s.substr(0, k);

        // initial conversion once
        int val = stoi(temp, nullptr, 2);
        array[val] = true;

        int mask = (1 << k) - 1;
        int j = k;

        while (j < s.size()) {
            for (int i = 0; i < k - 1; i++)
                temp[i] = temp[i + 1];
            temp[k - 1] = s[j];
            val = ((val << 1) & mask) | (s[j] - '0');

            array[val] = true;
            j++;
        }

        for (bool v : array)
            if (!v) return false;

        return true;
    }
};