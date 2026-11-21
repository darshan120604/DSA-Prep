class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        int o = nums[0];
        int cnt = 1;
        for(int i = 1; i<nums.size(); i++){
            if(o>nums[i]){
                if(cnt == 2) return o;
                o = nums[i];
                cnt++;
            }
        }
        return -1;
    }
};