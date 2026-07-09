class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> m(n,1);
        // m[0] = 1;
        // cout<<nums[0]<<"\n";
        int graph = 1;
        for(int i = 1;i<n;i++){
            if(nums[i]-nums[i-1] <= maxDiff){
                // cout<<"if\n";
                // m[i-1] = graph;
                m[i] = graph;
            }
            else {
                // cout<<nums[0];
                // cout<<"else\n";
                graph++;
                m[i] = graph;
            }
        }
        vector<bool> res;
        for(auto i:queries){
            // cout<<m[i[0]]<<" "<<m[i[1]]<<"\n";
            res.push_back(m[i[0]] == m[i[1]]);
        }
        return res;
    }
};