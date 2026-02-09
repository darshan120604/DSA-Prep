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
    void inordtrav(TreeNode* root, vector<int> &arr) {
        if (root == NULL) return;
        inordtrav(root->left, arr);
        arr.push_back(root->val);
        inordtrav(root->right, arr);
    }

    TreeNode* buildBST(vector<int> &arr, int st, int end) {
        if (st > end) return NULL;

        int mid = (st + end) / 2;
        TreeNode* root = new TreeNode(arr[mid]);

        root->left = buildBST(arr, st, mid - 1);
        root->right = buildBST(arr, mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inordtrav(root, arr);
        return buildBST(arr, 0, arr.size() - 1);
    }
};
