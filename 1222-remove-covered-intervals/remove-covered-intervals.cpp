class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            if(a[1] != b[1] && a[0] == b[0]){
                return a[1]>b[1];
            }
            else return a[0]<b[0];
        });
        int res = 0;
        int x = -1, y = -1;
        for(auto i:intervals){
            if(i[0]>=x && i[1]<=y) continue;
            if(i[0]>y || i[1]>y){
                x = i[0];y=i[1];res++;
                continue;
            }
        }
        return res;
    }
};