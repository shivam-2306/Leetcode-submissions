/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int result = 0;
    vector<int> calc(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }
        vector<int> arrRight = calc(root->right);
        vector<int> arrLeft = calc(root->left);
        int average = (arrRight[0]+arrLeft[0]+root->val)/(arrRight[1]+arrLeft[1]+1);
        if(average == root->val)result++;
        return {arrRight[0]+arrLeft[0]+root->val, arrRight[1]+arrLeft[1]+1};
    }
    int averageOfSubtree(TreeNode* root) {
        vector<int> arr = calc(root);
        return result;
    }
};