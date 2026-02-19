class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;

        int o = 0;
        int z = 0;
        s.push_back('2');
        int n = s.size();
        int prev = 0;
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                cnt++;
            } else {
                cnt++; 
                ans += min(prev, cnt);
                prev = cnt;
                cnt = 0;
            }
        }
        ans += min(prev, cnt);
        return ans;
    }
};