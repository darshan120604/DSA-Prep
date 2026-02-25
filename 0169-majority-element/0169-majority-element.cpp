class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxcount=0,max;
        for(int i=0;i<nums.size();i++){
            int count=1;
            if(nums[i]==max){
                continue;
            }
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    count++;
                }
                
            }
            if(count>maxcount){
                maxcount=count;
                max=nums[i];
            }
        }
        return max;
    }
    
};