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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;

        for (auto& d : descriptions) {
            int pVal = d[0];
            int cVal = d[1];
            bool isLeft = d[2];

            if (nodeMap.find(pVal) == nodeMap.end()) nodeMap[pVal] = new TreeNode(pVal);
            if (nodeMap.find(cVal) == nodeMap.end()) nodeMap[cVal] = new TreeNode(cVal);

            if (isLeft) {
                nodeMap[pVal]->left = nodeMap[cVal];
            } else {
                nodeMap[pVal]->right = nodeMap[cVal];
            }

            children.insert(cVal);
        }

        for (auto& d : descriptions) {
            if (children.find(d[0]) == children.end()) {
                return nodeMap[d[0]];
            }
        }

        return nullptr;
    }
};
