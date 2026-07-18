class Solution {
public:
    int findGCD(vector<int>& nums) {
        int s = nums[0];
        int l = nums[0];
        int n = nums.size();
        for(int i = 0; i<n; i++){
            s = min(s,nums[i]);
            l = max(l,nums[i]);
        }
        int ans = 0;
        for(int i = s; i>0; i--){
            if(ans){
                return ans;
            } else{
                if(s%i == 0 && l%i ==0){
                    ans = i;
                }
            }
        }
        return 1;
    }
};