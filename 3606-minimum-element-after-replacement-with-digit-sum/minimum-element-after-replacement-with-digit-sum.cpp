class Solution {
public:
 int sumOfDigitsFrom1ToN(int x) {
            int sum = 0;
            while (x != 0) {
                sum += x % 10;
                x = x / 10;
            }
            return sum;
        }
    int minElement(vector<int>& nums) {
       vector<int> check(37,0);
        for(auto i:nums){
            int c = sumOfDigitsFrom1ToN(i);
            if(c == 1) return 1; 
            check[c]++;
        }
        for(int i = 0;i<37;i++){
            if(check[i]) return i;
        }
        return 0;
    }
};