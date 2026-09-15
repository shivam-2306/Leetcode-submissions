class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        long long ans = 0;
        stack<pair<int, int>> s;
        long long total = 0;

        for (int x : nums) {
            while (!s.empty() && s.top().first > x) {
                total -= s.top().second;
                s.pop();
            }

            if (!s.empty()) {

                if (s.top().first == x) {
                    ans += total - s.top().second;
                } 
                else {
                    ans += total;
                }
            }
            if (!s.empty() && s.top().first == x) {
                s.top().second++;
            } 
            else {
                s.push({x, 1});
            }

            total++;
        }

        return ans;
    }
};