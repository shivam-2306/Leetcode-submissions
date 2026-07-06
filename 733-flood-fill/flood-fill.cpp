class Solution {
public:
    int m =0,n=0;
    bool isValid(int m, int n, int i, int j) {
    return (i >= 0 && i < m && j >= 0 && j < n);
    }
    void traverser(vector<vector<int>>& im, int i, int j, int color, int initialColor, vector<vector<bool> >& visited){
         if(!isValid(m, n, i, j) || im[i][j] != initialColor || visited[i][j] == true) return;
         im[i][j] = color;
         visited[i][j] = true;
         traverser(im, i-1, j, color, initialColor, visited);
         traverser(im, i+1, j, color, initialColor, visited);
         traverser(im, i, j-1, color, initialColor, visited);
         traverser(im, i, j+1, color, initialColor, visited);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& im, int i, int j, int color) {
        m = im.size(); n = im[0].size();
        int res = 0;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        traverser(im,i, j, color,im[i][j], visited);
        return im;
    }
};