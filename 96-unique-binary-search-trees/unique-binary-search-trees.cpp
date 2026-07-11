class Solution {
public:
    int numTrees(int n) {
        long long int res = 1;
        for(int i = 1;i<=n;i++){
           res = res * (n + i) / i;
        }
        res /= (n+1);
        return res;
    }
};