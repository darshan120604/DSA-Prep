#include <vector>

using namespace std;

class Solution {
public:
    bool isMajor(int count, int subarray_len) {
        return (count * 2 > subarray_len);
    }

    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int target_count = 0;
            int subarray_len = 0;

            for (int j = i; j < n; j++) {
                subarray_len++;
                
                if (nums[j] == target) {
                    target_count++;
                }

                if (isMajor(target_count, subarray_len)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
