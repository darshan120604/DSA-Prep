class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        int ans = 0;
        int p = 0;
        for(int i = n-1; i>=0; i--){
            if(p == 2){
                p = 0;
                continue;
            }
            ans += cost[i];
            p++;
        }

        return ans;
    }
};