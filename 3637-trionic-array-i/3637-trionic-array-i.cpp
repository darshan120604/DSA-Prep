class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int cnt = 0;

        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i - 1] || nums[i] == nums[i + 1])
                return false;
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                cnt++;
            else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
                if (!cnt)
                    return false;
                cnt++;
            }
        }
        return cnt == 2;
    }
};