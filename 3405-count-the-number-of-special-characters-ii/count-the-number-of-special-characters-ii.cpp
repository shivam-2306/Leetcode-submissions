class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<int> s;
        unordered_set<int> ignore;
        int res = 0;
        for (auto i : word) {
            int temp = i + 0;
            if (temp > 96 && temp < 123 && ignore.find(temp) == ignore.end()) {
                if (s.find(temp - 32) != s.end()) {
                    res--;
                    ignore.insert(temp);
                    continue;
                }
                s.insert(temp);
                continue;
            }
            if (s.find(temp) == s.end()) {
                if(s.find(temp+32) != s.end()){
                    res++;
                    s.insert(temp);
                }else {
                    ignore.insert(temp+32);
                }
            }
        }
        return res;
    }
};