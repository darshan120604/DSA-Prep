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
    int sum = 0;
    int binaryToInteger(std::string binary) {
        int result = 0;
        
        for (char bit : binary) {
            // Shift left by 1 and use bitwise OR to add the current bit
            result = (result << 1) | (bit - '0');
        }
    
        return result;
    }
    void preord(TreeNode* root, string s){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            s.push_back(root->val + '0');
            sum += binaryToInteger(s);

            return;
        }
        s.push_back(root->val + '0');
        preord(root->left, s);
        preord(root->right, s);

    }
    int sumRootToLeaf(TreeNode* root) {
        string s ="";
        preord(root,s);
        return sum;
    }
};