class Solution {
public:
    int numTrees(int n) {
        long long int res = 1;
        int div = 1e9+7;
        unsigned long long int num = 1;
         unsigned long long int den = 1;
        for(int i = 1;i<=n;i++){
           res = res * (n + i) / i;
        }
        res /= (n+1);
        den%=div;
        cout<<num<<" "<<den;
        return res;
    }
};