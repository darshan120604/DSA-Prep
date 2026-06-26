// class Solution {
// public:
//     long long countMajoritySubarrays(vector<int>& nums, int target) {
//         int cnt = 0;
//         long long ans = 0;
//         for(int i = 0; i<nums.size(); i++){
//             if(nums[i] == target) nums[i] = 1;
//             else nums[i] = -1;
//         }

//         vector<long long> p(nums.size()+1,0);

//         p[0] = 0;
//         for(int i = 0; i<nums.size(); i++){
//             p[i+1] = p[i] + nums[i];
//         }

//         for(int i= 0; i<p.size(); i++){
//             for(int j = i+1; j<p.size(); j++){
//                 if(p[j]>p[i]) ans++;
//             }
//         }
//         return ans;
//     }
// };
#include <vector>
using namespace std;

class Solution {
private:
    void update(vector<int>& bit, int idx, int val, int n) {
        for (; idx < n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int query(vector<int>& bit, int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return 0;
        
        long long ans = 0;
        int offset = n + 1;
        int max_bit_size = 2 * n + 2;
        vector<int> bit(max_bit_size, 0);

        int current_sum = 0;
        update(bit, current_sum + offset, 1, max_bit_size);

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                current_sum += 1;
            } else {
                current_sum -= 1;
            }

            ans += query(bit, current_sum + offset - 1);
            update(bit, current_sum + offset, 1, max_bit_size);
        }

        return ans;
    }
};
