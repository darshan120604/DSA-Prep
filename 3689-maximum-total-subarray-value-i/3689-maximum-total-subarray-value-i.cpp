class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int s = nums[0];
        int l = s;
        int n = nums.size();
        for(int i = 1; i<n; i++){
            if(nums[i]<s){
                s = nums[i];
            }
            if(nums[i]>l){
                l = nums[i];
            }
        }

        long long ans;
        ans = l-s;

        ans *= k;

        return ans;
    }
};