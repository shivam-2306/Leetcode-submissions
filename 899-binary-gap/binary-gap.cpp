class Solution {
public:
    int binaryGap(int n) {
        string res = bitset<32>(n).to_string();
        int i = 0, j = 0, result = 0;

        while (i < 32) {
            if (res[i] == '0') {
                i++;
            } else {
                j = i + 1;
                while (j < 32 && res[j] == '0')
                    j++;

                if (j == 32)
                    break;

                result = max(result, j - i);
                i = j;
            }
        }
        return result;
    }
};