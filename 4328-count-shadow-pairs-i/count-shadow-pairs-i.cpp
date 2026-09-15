class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        long long ans = 0;
        stack<pair<int, int>> s;

        for (auto i : nums) {

            if (s.empty()) {
                s.push({i, 1});
            } 
            else {

                while (!s.empty() && s.top().first > i) {
                    s.pop();
                }

                if (!s.empty()) {

                    if (s.top().first != i) {
                        ans += s.size();
                    } 
                    else {
                        ans += s.size() - s.top().second;
                    }
                }

                if (!s.empty() && s.top().first == i) {
                    s.push({i, s.top().second + 1});
                } 
                else {
                    s.push({i, 1});
                }
            }
        }

        return ans;
    }
};