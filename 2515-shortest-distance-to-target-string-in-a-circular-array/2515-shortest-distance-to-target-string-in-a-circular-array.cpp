class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        vector<int> t ;
        for(int i = 0; i<words.size(); i++){
            if(words[i] == target) t.push_back(i);
        }
        int ans = INT_MAX;
        int n = words.size();
        if(t.size() == 0) return -1;
        for(int i = 0; i< t.size(); i++){
            ans = min(ans , abs(t[i]-startIndex));
            ans = min(ans,(min(t[i],startIndex) - max(t[i],startIndex)+n));
        }
        return ans;
    }
};