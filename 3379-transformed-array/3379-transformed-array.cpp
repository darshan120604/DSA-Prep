class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int pos;

        for(int i=0; i<n; i++){

            if(nums[i] > 0){
                pos = (nums[i] + i)%n;
                result[i] = nums[pos];
            } else {
                if(nums[i]<0){
                    pos = (n + nums[i] + i) % n;
                    if(pos<0){
                        pos = n + pos;
                    }
                    result[i] = nums[pos];
                }
                else{
                    result[i] = nums[i];
                }
            }
        }

        return result;
    }
};