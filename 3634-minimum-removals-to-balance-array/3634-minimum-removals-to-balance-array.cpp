class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = INT_MAX;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (1ll * nums[i] > 1ll* nums[j] * k) {
                j++;
            }
            ans = min(ans, n - (i - j + 1));
        }
        return ans;
    }
};