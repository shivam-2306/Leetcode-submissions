class Solution {
public:
    int gcd (int a , int b){
        while(b!=0){
            int temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int res = gcd(pow(n,2), n*n+n);
        return res;
    }
};