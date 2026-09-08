class Solution {
public:
    int countCommas(int n) {
        int result = n-999;
        // if(n == 100000){
        //     result ++;
        // }
        return result<0?0:result;
    }
};