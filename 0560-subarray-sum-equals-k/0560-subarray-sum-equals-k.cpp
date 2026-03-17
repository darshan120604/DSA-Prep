class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        unordered_map <int, int> prefixSum;

        for(int i = 0; i<n; i++){
            sum += nums[i];

            if(sum == k){
                ans++;
            }

            if(prefixSum.find(sum - k) != prefixSum.end()){
                ans += prefixSum[sum - k];
            }

            prefixSum[sum]++;
        }

        return ans;
    }
};