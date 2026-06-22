class Solution {
public:
    int maxNumberOfBalloons(string s) {
        int b = 0,a = 0,l = 0,o = 0,n = 0;
        for(char c:s){
            if(c == 'b'){
                b++;
                continue;
            }
            if(c == 'a'){
                a++;
                continue;
            }
            if(c == 'l'){
                l++;
                continue;
            }
            if(c == 'o'){
                o++;
                continue;
            }
            if(c == 'n'){
                n++;
            }
        }
        int one = min(n,min(b,a));
        int two = min(l,o);
        two /=2;

        return min(one,two);
    }
};