class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int res = 0;
        sort(cost.begin(), cost.end());
        for(int i = cost.size()-1;i>=0;i-=3){
            res += cost[i];
            if(i>0)
            res+= cost[i-1];
        }
        return res;
    }
};