class Solution {
public:
    int minPartitions(string n) {
        int ans=0;

        for(char c:n){
            int t = c-'0';
            if(t>ans){
                ans = t;
            }
        }

        return ans;
    }
};