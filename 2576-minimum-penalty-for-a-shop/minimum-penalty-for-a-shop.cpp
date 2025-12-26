class Solution {
public:
    int bestClosingTime(string c) {
        vector<int> rightNCount(c.size()+1, 0), leftYCount(c.size()+1, 0);
        for(int i = c.length()-1;i>=0;i--){
            leftYCount[i] = leftYCount[i+1];
            if(c[i] == 'Y'){
                leftYCount[i]++;
            }
        }
        int optimumIndex = 0;
        int res = leftYCount[0]+rightNCount[0];
        for(int i = 0;i<c.length();i++){
            rightNCount[i+1] = rightNCount[i];
            if(c[i] == 'N'){
                rightNCount[i+1]++;
            }
            int resTemp = res;
            res = min(res, leftYCount[i]+rightNCount[i]);
            res != resTemp?optimumIndex = i:NULL;
        }
        int resTemp = res;
            res = min(res, leftYCount[c.size()]+rightNCount[c.size()]);
            res != resTemp?optimumIndex = c.size():NULL;

        //     cout<<resTemp<<" ";
        //     res = min(res, leftYCount[i]+rightNCount[i]);
        //     cout<<res<<endl;


        // for(auto i:rightNCount){
        //     cout<<i<< " ";
        // }cout<<endl;
        // for(auto i:leftYCount){
        //     cout<<i<< " ";
        // }cout<<endl;
        return optimumIndex;
        // return 0;
    }
};