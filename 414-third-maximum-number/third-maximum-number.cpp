class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        int o = nums[0];
        int cnt = 1;
        for(int i = 1; i<nums.size(); i++){
            if(o>nums[i]){
                o = nums[i];
                cnt++;
                if(cnt == 3) return o;
            }
        }
        return nums[0];
    }
};