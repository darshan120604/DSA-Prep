class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = INT_MAX;

        unordered_map<int, vector<int>> mp;

        for(int i = 0;i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }

        for(auto v:mp){
            for(int k = 2;  k < v.second.size(); k++){
                int i = k-2;
                int j = k-1;
                int x = abs(v.second[i] - v.second[j])  + abs(v.second[i]- v.second[k]) + abs(v.second[j] - v.second[k]);

                ans = min(ans,x);
                
            }
        }
        
        return ans >= INT_MAX ? -1 : ans; 
    }
};