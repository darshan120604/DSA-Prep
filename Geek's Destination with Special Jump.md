## 01. Geek's Destination with Special Jump

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/geek-and-her-destination--145724/1)

### Problem Description

**Task:** Geek starts at position 0 on the positive X-axis and needs to reach or pass position d on the positive X-axis. Geek normally follows a repeating movement pattern:Move forward by a units, taking a seconds.Move backward by b units, taking b seconds.Geek also has a special jump that moves him exactly j units forward in 1 second. He can use it at any time, even in the middle of a forward or backward movement, and the journey ends immediately after the jump.Given five integers a, b, d, l, and r. For every integer j in the range [l, r], find the minimum time required for Geek to reach or pass position d. He may either use the special jump or reach the destination using normal movement alone, whichever takes less time.Return the sum of the minimum times for all jump lengths from l to r. Since, the answer can be large, return modulo 10⁹ + 7. Note: Each jump length is considered independently.Examples:Input: a = 2, b = 1, d = 5, l = 3, r = 4Output: 5Explanation: For j = 3, Geek moves 2 units forward, then takes a jump of 3 units to reach the destination. The minimum time required is 3 seconds.For j = 4, Geek moves 1 unit forward, then takes a jump of 4 units to reach the destination. The minimum time required is 2 seconds.Total sum for the range [l, r] = 3 + 2 = 5.Input: a = 4, b = 2, d = 8, l = 2, r = 4Output: 26Explanation:For j = 2, Geek moves 4 units forward, then 2 units backward. She then moves 4 units forward again and takes a jump of 2 units to reach the destination. The minimum time required is 11 seconds.For j = 3, Geek moves 4 units forward, then 2 units backward. She then moves 3 units forward and takes a jump of 3 units to reach the destination. The minimum time required is 10 seconds.For j = 4, Geek moves 4 units forward, then takes a jump of 4 units to reach the destination. The minimum time required is 5 seconds.Total sum for the range [l, r] = 11 + 10 + 5 = 26.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(1)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-11-25 19:42:09
- **Status:** Correct
- **Marks:** 8

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    static constexpr long long MOD = 1000000007LL;

    long long modNorm(long long x) const {
        long long r = x % MOD;
        return r < 0 ? r + MOD : r;
    }

    // Minimum time to reach position x >= 0 using normal movement only
    long long earliestNormal(long long a, long long b, long long x) const {
        if (x <= 0) return 0;
        if (x <= a) return x;
        long long step = a - b;
        long long k = (x - a + step - 1) / step;
        return k * (a + b) + (x - k * step);
    }

    // Sum of earliestNormal(a, b, x) for x in [1, X] (mod MOD)
    long long prefixEarliest(long long a, long long b, long long X) const {
        if (X <= 0) return 0;
        if (X <= a) {
            return (X % MOD) * ((X + 1) % MOD) % MOD * 500000004LL % MOD; // inv(2) mod 1e9+7
        }

        long long step = a - b;
        long long res = (a % MOD) * ((a + 1) % MOD) % MOD * 500000004LL % MOD;

        long long M = X - a;
        long long full_k = M / step;
        long long rem = M % step;

        if (full_k > 0) {
            long long fk_mod = full_k % MOD;
            long long sum_k = fk_mod * ((full_k + 1) % MOD) % MOD * 500000004LL % MOD;
            long long cycle_gain = modNorm(step * (a + b));
            long long term1 = cycle_gain * sum_k % MOD;

            long long block_const = modNorm(step * b + step * (step + 1) / 2);
            long long term2 = fk_mod * block_const % MOD;

            res = (res + term1 + term2) % MOD;
        }

        if (rem > 0) {
            long long k = (full_k + 1) % MOD;
            long long rem_mod = rem % MOD;
            long long start_val = modNorm(k * modNorm(a + b) + b);
            long long rem_part = rem_mod * start_val % MOD;
            long long rem_inc = rem_mod * ((rem + 1) % MOD) % MOD * 500000004LL % MOD;
            res = (res + rem_part + rem_inc) % MOD;
        }

        return res;
    }

public:
    int minTime(long long a, long long b, long long d, long long l, long long r) {
        long long t_no_jump = earliestNormal(a, b, d);

        // x = d - j ranges from L = d - r to R = d - l
        long long L = max(0LL, d - r);
        long long R = max(0LL, d - l);

        // Find largest x in [L, R] where earliestNormal(a, b, x) + 1 <= t_no_jump
        long long low = L, high = R, cut = L - 1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (earliestNormal(a, b, mid) + 1 <= t_no_jump) {
                cut = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        long long total = 0;

        // Range [L, cut]: uses jump -> earliestNormal(a, b, x) + 1
        if (cut >= L) {
            long long sum_x = modNorm(prefixEarliest(a, b, cut) - prefixEarliest(a, b, L - 1));
            long long jump_cnt = modNorm(cut - L + 1);
            total = (total + sum_x + jump_cnt) % MOD;
        }

        // Range [cut + 1, R]: jump is not faster -> t_no_jump
        if (R > cut) {
            long long no_jump_cnt = modNorm(R - max(L - 1, cut));
            total = (total + no_jump_cnt * modNorm(t_no_jump)) % MOD;
        }

        return static_cast<int>(total);
    }
};
```

*Generated on: 25/11/2026, 19:46:04*