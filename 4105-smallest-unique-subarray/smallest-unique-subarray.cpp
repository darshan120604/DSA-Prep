#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    static constexpr long long MOD1 = 1000000007LL;
    static constexpr long long MOD2 = 1000000009LL;
    static constexpr long long BASE1 = 1315423911LL;
    static constexpr long long BASE2 = 2654435761LL;

    static uint64_t pack(long long h1, long long h2) {
        return (static_cast<uint64_t>(h1) << 32) | static_cast<uint32_t>(h2);
    }

    bool hasUniqueOfLength(const vector<int>& nums, int k,
                           const vector<long long>& p1,
                           const vector<long long>& p2) const {
        int n = static_cast<int>(nums.size());
        if (k <= 0 || k > n) return false;

        long long h1 = 0, h2 = 0;
        for (int i = 0; i < k; ++i) {
            long long val = nums[i] + 1;
            h1 = (h1 * BASE1 + val) % MOD1;
            h2 = (h2 * BASE2 + val) % MOD2;
        }

        unordered_map<uint64_t, int> freq;
        freq.reserve(n - k + 1);
        freq[pack(h1, h2)] = 1;

        for (int i = k; i < n; ++i) {
            long long out_val = nums[i - k] + 1;
            long long in_val = nums[i] + 1;

            h1 = (h1 - (out_val * p1[k - 1]) % MOD1 + MOD1) % MOD1;
            h1 = (h1 * BASE1 + in_val) % MOD1;

            h2 = (h2 - (out_val * p2[k - 1]) % MOD2 + MOD2) % MOD2;
            h2 = (h2 * BASE2 + in_val) % MOD2;

            ++freq[pack(h1, h2)];
        }

        for (const auto& kv : freq) {
            if (kv.second == 1) return true;
        }
        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            p1[i] = (p1[i - 1] * BASE1) % MOD1;
            p2[i] = (p2[i - 1] * BASE2) % MOD2;
        }

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUniqueOfLength(nums, mid, p1, p2)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};