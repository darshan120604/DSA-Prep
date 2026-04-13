class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        vector<int> d;

        int n = nums.size();
        int i = 0;
        while(i<n){
            if(nums[i] == target) d.push_back(i);
            i++;
        }

        int ans = INT_MAX;
        i = 0;
        int m = d.size();
        while(i<m){
            ans = min(abs(start - d[i]), ans);
            i++;
        }

        return ans;
    }
};