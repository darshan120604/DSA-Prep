class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            int j=1;
            while(j<nums[i]){
                if(nums[i] == (j | (j+1))){
                    ans[i] = j;
                    break;
                }
                j++;
            }
        }
        return ans;
    }
};