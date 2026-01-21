class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        // 1. Sort the array to use the two-pointer approach
        sort(nums.begin(), nums.end());
        
        // Initialize closestSum with the first possible triplet
        long closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // If we found the exact target, return immediately
                if (currentSum == target) {
                    return currentSum;
                }
                
                // Update closestSum if the currentSum is closer to target
                if(abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                // Move pointers based on the sum comparison
                if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return (int)closestSum;
    }
};