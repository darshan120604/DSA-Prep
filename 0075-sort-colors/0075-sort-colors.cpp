class Solution {
public:
    void sortColors(vector<int>& nums) {
        int o =0;
        int z =0;
        int t =0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] == 0) z++;
            if(nums[i] == 1) o++;
            if(nums[i] == 2) t++;
        }
        int i=0;
        while(i<nums.size()){
            if(i<z) nums[i] = 0;
            else{
                if(i<(z+o)) nums[i] = 1;
                else{
                    nums[i] = 2;
                }
            }
            
            i++;
        }
    }
};