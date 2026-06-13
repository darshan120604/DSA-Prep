class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string ans= "";
        for(int i = 0; i<n; i++){
            int m = words[i].size();
            int sum = 0;
            for(int j = 0; j<m; j++){
                sum += weights[(words[i][j] - 'a')];
            }
            sum %= 26;
            int pos = 26 - sum - 1;
            ans.push_back('a' + pos);
        }

        return ans;
    }
};