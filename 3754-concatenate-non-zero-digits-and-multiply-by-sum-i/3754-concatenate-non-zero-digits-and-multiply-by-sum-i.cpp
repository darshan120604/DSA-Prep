class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        long long i = 1;
        long sum = 0;
        string s = to_string(n);
        reverse(s.begin(), s.end());
        cout<<s;
        for(char c:s){
            if(c-'0' != 0){
                ans += i*(c-'0');
                i*=10;
                sum += (c-'0');
            }
        }

        ans *= sum;

        return ans;
    }
};