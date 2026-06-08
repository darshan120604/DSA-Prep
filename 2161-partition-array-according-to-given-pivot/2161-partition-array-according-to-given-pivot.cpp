class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cnt = 0;
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
            }
            if(nums[i] == pivot) cnt++;
        }

        for(int i = 0; i<cnt; i++){
            ans.push_back(pivot);
        }

        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>pivot){
                ans.push_back(nums[i]);
            }
        }

        for(int i = 0; i<nums.size(); i++){
            nums[i] = ans[i];
        }

        return nums;
    }
};