class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // int cnt = 3;
        // int n = nums.size();
        // if(n==cnt){
        //     return (nums[0] + nums[1] + nums[3]);
        // }
        // int first = nums[0]; 
        sort(nums.begin() + 1, nums.end());
        // int ans = max(nums[0] + nums[1] + nums[2]);
      
        return nums[0] + nums[1] + nums[2];


    }
};