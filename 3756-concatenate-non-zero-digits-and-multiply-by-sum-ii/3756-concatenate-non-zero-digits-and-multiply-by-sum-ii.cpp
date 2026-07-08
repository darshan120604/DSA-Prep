#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long MOD = 1e9 + 7;

        // Precompute powers of 10 modulo 10^9 + 7
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        // Tracking arrays
        vector<long long> prefix_sum(m + 1, 0);       // Prefix sums of digits
        vector<long long> prefix_concat(m + 1, 0);    // Value of concatenated non-zero digits
        vector<int> nonzero_count(m + 1, 0);          // Count of non-zero digits encountered

        for (int i = 0; i < m; i++) {
            int digit = s[i] - '0';
            prefix_sum[i + 1] = prefix_sum[i] + digit;

            if (digit != 0) {
                prefix_concat[i + 1] = (prefix_concat[i] * 10 + digit) % MOD;
                nonzero_count[i + 1] = nonzero_count[i] + 1;
            } else {
                prefix_concat[i + 1] = prefix_concat[i];
                nonzero_count[i + 1] = nonzero_count[i];
            }
        }

        vector<int> answer;
        answer.reserve(queries.size());

        for (const auto& query : queries) {
            int L = query[0];
            int R = query[1];

            // 1. Calculate Sum of digits in the range [L, R]
            long long current_sum = prefix_sum[R + 1] - prefix_sum[L];

            if (current_sum == 0) {
                answer.push_back(0);
                continue;
            }

            // 2. Extract value x using prefix properties
            long long full_right = prefix_concat[R + 1];
            long long full_left = prefix_concat[L];
            
            // Count how many non-zero digits exist strictly inside [L, R]
            int count_inside = nonzero_count[R + 1] - nonzero_count[L];

            // Strip the left part's contribution out of the right part
            long long x = (full_right - (full_left * pow10[count_inside]) % MOD + MOD) % MOD;

            // 3. Compute (x * sum) % MOD
            long long query_ans = (x * (current_sum % MOD)) % MOD;
            answer.push_back(static_cast<int>(query_ans));
        }

        return answer;
    }
};
