class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hbars, vector<int>& vbars) {
        int horizontal = 1, vertical = 1;
        hbars.push_back(INT_MAX);
        vbars.push_back(INT_MAX);
        sort(hbars.begin(), hbars.end());
        sort(vbars.begin(), vbars.end());
        int temp = 1;
        for(int i = 1;i<hbars.size();i++){
            if(hbars[i] - hbars[i-1] == 1){
                temp ++;
                cout<<"Executed"<<endl;
            }
            else {
                horizontal = max(temp, horizontal);
                temp = 1;
            }
        }
        //  horizontal = max(temp, horizontal);
        
        temp = 1;
        for(int i = 1;i<vbars.size();i++){
            if(vbars[i] - vbars[i-1] == 1){
                temp ++;
            }
            else {
                vertical = max(temp, vertical);
                temp = 1;
            }
        }
         vertical = max(temp, vertical);
        cout<<horizontal<<" "<<vertical;
        return (min(vertical, horizontal)+1)*(min(vertical, horizontal)+1);
    }
};