class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> even_count(26, 0);
        vector<int> odd_count(26, 0);
        
        for (int i = 0; i < s1.size(); i++) {
            if (i % 2 == 0) {
                even_count[s1[i] - 'a']++;
                even_count[s2[i] - 'a']--;
            } else {
                odd_count[s1[i] - 'a']++;
                odd_count[s2[i] - 'a']--;
            }
        }
        
        for (int i = 0; i < 26; i++) {
            if (even_count[i] != 0 || odd_count[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};
