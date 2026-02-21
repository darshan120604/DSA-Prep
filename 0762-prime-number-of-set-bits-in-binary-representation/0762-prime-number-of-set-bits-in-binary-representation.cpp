class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        
        // primes up to 20 (bit count range)
        unordered_set<int> prime = {2,3,5,7,11,13,17,19};
        
        int ans = 0;
        
        for (int x = left; x <= right; x++) {
            int bits = __builtin_popcount(x);  // count set bits
            if (prime.count(bits))
                ans++;
        }
        
        return ans;
    }
};