class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        
        int o = 0;
        int z = 0;
        
        int n = s.size();
        for(int i =0; i<n; i++){
            if(s[i] == '0'){
                while(s[i]=='0' && i<n){
                    i++;
                    z++;
                }
                ans+= min(z,o);
                o=0;
                while(s[i]=='1' && i<n){
                    i++;
                    o++;
                }
                ans+= min(z,o);
                z=0;
            }
            if(s[i] == '1'){
                while(s[i]=='1' && i<n){
                    i++;
                    o++;
                }
                ans+= min(z,o);
                z=0;
                while(s[i]=='0' && i<n){
                    i++;
                    z++;
                }
                ans+= min(z,o);
                o=0;
            }
            i--;
        }

        return ans;
    }
};