class Solution {
public:
    int bintoint(string s){
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans = (ans << 1) | 1; 
            } else {
                ans = (ans << 1);
            }
        }
        return ans;
    }
    int numSteps(string s) {

        int st = 0;
        // int n = bintoint(s);
        
        // while(n>1){
        //     if(n%2 == 0) n/=2;
        //     else n+=1;
        //     st++;
        // }
        int carry = 0;
        int n = s.size();
        for(int i=n-1; i>0;i--){
            int curr = s[i] - '0' + carry;

            if(curr == 1){
                st+=2;

                carry = 1;
            } else{
                st++;
            }
        }
        
        return st + carry;
    }
};