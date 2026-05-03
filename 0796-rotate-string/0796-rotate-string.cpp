class Solution {
public:
    bool rotateString(string s, string goal) {
        string s1 = goal+goal;
        int j = 0;
        if(s.size() != goal.size()) return false;
        for(int i = 0; i<s1.size();i++){
            if(s[j] == s1[i]){
                j++;
                if(j==s.size()) return true;
            } else{
                i = i-j;
                j=0;
            }
        }

        return false;
    }
};