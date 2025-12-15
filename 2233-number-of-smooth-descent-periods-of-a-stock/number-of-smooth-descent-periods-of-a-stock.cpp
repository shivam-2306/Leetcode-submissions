class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        prices.push_back(INT_MAX);
        int size  = prices.size();
        long long result = 0;
        if(size == 2) return 1;
        int temp = 1;
        for (int i = 1; i < size; i++) {
            if (prices[i] >= prices[i - 1] || prices[i] - prices[i - 1] != -1) {
                result += (1LL * (temp) * (temp + 1)) / 2;
                temp = 1;
            } 
            if(prices[i] - prices[i - 1] == -1) {
                temp++;
            }
        }
        return result;
    }
};