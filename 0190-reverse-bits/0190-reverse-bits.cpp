class Solution {
public:
    int reverseBits(int n) {
        bitset<32>b(n); 
        for(int i = 0; i < 16; i++){
            int t = b[i];
            b[i] = b[31-i];
            b[31-i] = t;
        }
        return  static_cast<int>(b.to_ulong()); 

    }
};