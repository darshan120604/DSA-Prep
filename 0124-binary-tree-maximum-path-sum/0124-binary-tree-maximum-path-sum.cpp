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
    int s = 0;
    int h(TreeNode * root){
        if(!root) return 0;
        int ls = h(root->left);
        int rs = h(root->right);
        int v = root->val;
        ls = max(0,ls);
        rs = max(0, rs);
        s = max(s,v +ls + rs);
        return v + max(ls,rs);
    }
    int maxPathSum(TreeNode* root) {
        s = root->val;
        int p = h(root);

        return s;
    }
};