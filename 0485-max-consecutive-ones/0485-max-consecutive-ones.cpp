class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0;
        
        int cnt = 0;
        int mcnt = 0;
        while(i<nums.size()){
            if(nums[i] == 1){
                cnt++;
            } else{
                mcnt = max(cnt, mcnt);
                cnt = 0;
            }
            i++;
        }
        mcnt = max(cnt, mcnt);

        return mcnt;
    }
};