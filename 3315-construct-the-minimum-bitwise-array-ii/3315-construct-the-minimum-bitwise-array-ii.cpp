class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int p : nums) {
            // Case 1: Even primes (only 2). 
            // 2 in binary is 10. No x OR (x+1) can result in a trailing 0.
            if (p == 2) {
                ans.push_back(-1);
                continue;
            }

            // Case 2: Odd primes.
            // We need to find the first '0' bit to find the end of the 
            // trailing sequence of '1's.
            for (int j = 0; j < 31; j++) {
                // Check if the bit at position j is 0
                if (!((p >> j) & 1)) {
                    // The bit at (j-1) is the one we must flip to 0
                    // to get the minimum x.
                    ans.push_back(p ^ (1 << (j - 1)));
                    break;
                }
            }
        }
        return ans;
    }
};