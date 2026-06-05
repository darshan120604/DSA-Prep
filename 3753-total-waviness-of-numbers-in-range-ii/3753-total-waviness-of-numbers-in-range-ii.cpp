
class Solution {
    // memo[idx][prev_digit][prev_prev_digit][tight][leading_zeros]
    // Stores pair: {total_count_of_numbers, total_waviness_sum}
    pair<long long, long long> memo[20][11][11][2][2];
    string s;

    pair<long long, long long> dp(int idx, int p1, int p2, bool tight, bool leading_zeros) {
        if (idx == s.size()) {
            return {1, 0}; // Base case: 1 valid number reached, 0 waviness added at leaf
        }
        
        // Adjust for -1 indices in memoization table
        if (memo[idx][p1 + 1][p2 + 1][tight][leading_zeros].first != -1) {
            return memo[idx][p1 + 1][p2 + 1][tight][leading_zeros];
        }

        pair<long long, long long> res = {0, 0};
        int limit = tight ? s[idx] - '0' : 9;

        for (int d = 0; d <= limit; ++d) {
            bool next_tight = tight && (d == limit);
            bool next_leading_zeros = leading_zeros && (d == 0);
            
            // A peak/valley is only possible if we have at least 2 previous real digits
            long long added_waviness = 0;
            if (!leading_zeros && p1 != -1 && p2 != -1) {
                if ((p1 > p2 && p1 > d) || (p1 < p2 && p1 < d)) {
                    added_waviness = 1;
                }
            }

            pair<long long, long long> next = dp(idx + 1, (next_leading_zeros ? -1 : d), (next_leading_zeros ? -1 : p1), next_tight, next_leading_zeros);
            
            res.first += next.first;
            // Total waviness = (waviness of this digit * count of future numbers) + total future waviness
            res.second += (added_waviness * next.first) + next.second;
        }

        return memo[idx][p1 + 1][p2 + 1][tight][leading_zeros] = res;
    }

    long long count(long long n) {
        if (n < 0) return 0;
        s = to_string(n);
        // Reset memo table
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 11; j++)
                for (int k = 0; k < 11; k++)
                    for (int l = 0; l < 2; l++)
                        for (int m = 0; m < 2; m++)
                            memo[i][j][k][l][m] = {-1, -1};
                            
        return dp(0, -1, -1, true, true).second;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return count(num2) - count(num1 - 1);
    }
};
