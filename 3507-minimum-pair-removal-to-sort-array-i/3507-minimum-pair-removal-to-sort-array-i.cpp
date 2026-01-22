class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
         int ops = 0;

    while (true) {
        // Check if already non-decreasing
        bool sorted = true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) break;

        // Find leftmost adjacent pair with minimum sum
        int minSum = INT_MAX;
        int idx = -1;
        for (int i = 0; i < nums.size() - 1; i++) {
            int s = nums[i] + nums[i + 1];
            if (s < minSum) {
                minSum = s;
                idx = i;
            }
        }

        // Replace the pair with their sum
        nums[idx] = nums[idx] + nums[idx + 1];
        nums.erase(nums.begin() + idx + 1);
        ops++;
    }
    return ops;

    }
};