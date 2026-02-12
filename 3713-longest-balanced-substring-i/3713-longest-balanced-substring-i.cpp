class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;

        for(int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int distinct = 0, maxFreq = 0;

            for(int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if(freq[idx] == 0) distinct++;
                freq[idx]++;
                maxFreq = max(maxFreq, freq[idx]);

                int len = j - i + 1;

                // Check if balanced
                if(distinct * maxFreq == len) {
                    bool ok = true;
                    for(int f : freq) {
                        if(f > 0 && f != maxFreq) {
                            ok = false;
                            break;
                        }
                    }
                    if(ok) ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};
