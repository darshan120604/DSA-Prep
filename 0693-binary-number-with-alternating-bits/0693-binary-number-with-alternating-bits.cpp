class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool eve = (n%2 == 0);

        while(n>0){
            
            if(n%2 == 0 && eve){
                n=n/2;
                eve = false;
            } else {
                if(n%2 == 1 && !eve){
                    n=n/2;
                    eve = true;
                }
                else{
                    break;
                }

            } 
            
        }
        return n==0;
    }
};