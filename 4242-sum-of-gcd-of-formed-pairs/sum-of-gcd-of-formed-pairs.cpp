class Solution {
public:
    int mod = 1e9+7;
    int gcd(int a, int b){
        while(b!=0){
            int temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        vector<int> gcdArr;
        int maximum = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            maximum = max(nums[i], maximum);
            gcdArr.push_back(gcd(nums[i], maximum));
        }
        int i = 0, j = nums.size()-1;
        sort(gcdArr.begin(), gcdArr.end());
        // for(auto i: gcdArr){
        //     cout<<i<<" ";
        // }
        long long result = 0;
        while(i<j){
            result +=  gcd(gcdArr[i], gcdArr[j]);
            i++;j--;
        }
        return result;
    }
};