class Solution {
public:
    string makeFancyString(string s) {
        if (s.size() < 3)
            return s;
        string result;
        s += '/';
        int i = 0, j = 1;
        while (j < s.size() && i <= j) {
            // cout << i << " " << j << endl;
            // cout << result << endl;
            if (s[i] == s[j])
                j++;
            else {
                if (j - i >= 2) {
                    result += s[i];
                    result += s[i + 1];
                    i = j;
                } else {
                    result += s[i];
                    i++;
                }
            }
        }
        
        return result;
    }
};