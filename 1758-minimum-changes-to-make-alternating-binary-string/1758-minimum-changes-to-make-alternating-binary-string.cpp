class Solution {
public:
    int minOperations(string s) {
        int ch = 0;
        int min_ch;
        bool one = true;
        for(int i = 0; i< s.size(); i++){
            if(i % 2 == 0){
                if(s[i] == '1') ch++;
            } else{
                if(s[i] == '0') ch++;
            }
        }
        min_ch = ch;
        ch = 0;
        for(int i = 0; i< s.size(); i++){
            if(i % 2 ==0){
                if(s[i] == '0') ch++;
            } else{
                if(s[i] == '1') ch++;
            }
        }
        min_ch = min(ch, min_ch);
        return min_ch;

    }
};