class Solution {
public:
    int rev(int x ){
        int rev = 0;
        int x1=x;
        if(x==INT_MIN){
            return 0;
        }
        if(x<0){
            x=-x;
        }
        while(x>0){
            if(rev > (INT_MAX/10) || rev < (INT_MIN/10)){
                return 0;
            }
            rev = rev*10 + x%10;
            x=x/10;
        }
        if(x1<0) return -rev;
        return rev;
    }

    
    int mirrorDistance(int n) {
        int a = rev(n);
        return abs(n - a);

    }
};