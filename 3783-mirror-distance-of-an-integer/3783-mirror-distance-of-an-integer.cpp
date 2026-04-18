class Solution {
public:
    int rev(int x ){
        int rev = 0;
        int x1=x;
        
        while(x>0){
            if(rev > (INT_MAX/10) || rev < (INT_MIN/10)){
                return 0;
            }
            rev = rev*10 + x%10;
            x=x/10;
        }
        return rev;
    }

    
    int mirrorDistance(int n) {
        int a = rev(n);
        return abs(n - a);

    }
};