class Solution {
public:
    int reverseBits(int n) {
        vector<int> bit(32,0);
        int i = 31;
        while(n){
            bit[i] = n%2;
            n/=2;
            i--;
        }

        int ans = 0;
        for(int i =0; i<32; i++){
            if(bit[i] == 1)
                ans += (1 << i);
        }
        return ans;

    }
};