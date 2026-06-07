/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        vector<pair<TreeNode*, int>> mapper(100001, {NULL, -1});
        int root = -1;
        for(auto i:d){
            TreeNode* temp;
            if(mapper[i[1]].first == NULL)
            mapper[i[1]].first = new TreeNode(i[1]);
            temp = mapper[i[1]].first;
            if(mapper[i[0]].first == NULL){
                mapper[i[0]].first = new TreeNode(i[0]); 
            }
            TreeNode* temp2 =  mapper[i[0]].first;
            if(i[2]) temp2->left = temp;
            else temp2->right = temp;
            root =  i[0];
            mapper[i[1]].second = i[0];
        }
        while(true){
            if(mapper[root].second == -1) break;
            root = mapper[root].second;
        }
        return mapper[root].first;
    }
};