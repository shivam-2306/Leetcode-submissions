class Solution {
public:
    void addString(int a, int charNum, string& res) {
        for (int i = 0; i < a; i++) {
            res += charNum + 'a';
        }
    }

    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> frequencyMap(26, 0);

        for (auto i : s) {
            frequencyMap[i - 'a']++;
        }

        string res = "";

        int i = 25, j = 24;

        while (i >= 0 && frequencyMap[i] == 0) {
            i--;
        }

        if (i < 0) return res;

        j = i - 1;

        while (j >= 0 && frequencyMap[j] == 0) {
            j--;
        }

        while (i >= 0) {

            if (frequencyMap[i] > repeatLimit) {

                addString(repeatLimit, i, res);
                frequencyMap[i] -= repeatLimit;
                if (j < 0) break;
                addString(1, j, res);
                frequencyMap[j]--;
                while (j >= 0 && frequencyMap[j] == 0) {
                    j--;
                }
            }

            else {
                addString(frequencyMap[i], i, res);
                frequencyMap[i] = 0;
                i = j;
                if (i < 0) break;
                j = i - 1;
                while (j >= 0 && frequencyMap[j] == 0) {
                    j--;
                }
            }
        }

        return res;
    }
};