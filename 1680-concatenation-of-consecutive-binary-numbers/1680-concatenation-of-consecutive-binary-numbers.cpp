class Solution {
public:
    int concatenatedBinary(int n) {
        string s = "";
        long long MOD = 1e9 + 7;

        // 1. Correctly build the string
        for (int i = 1; i <= n; i++) {
            int temp = i;
            string binary = "";
            while (temp > 0) {
                binary += (temp % 2 == 0 ? '0' : '1');
                temp /= 2;
            }
            reverse(binary.begin(), binary.end());
            s += binary;
        }

        // 2. Convert binary string to decimal with Modulo
        long long ans = 0;
        for (char c : s) {
            ans = (ans * 2 + (c - '0')) % MOD;
        }

        return (int)ans;
    }
};
