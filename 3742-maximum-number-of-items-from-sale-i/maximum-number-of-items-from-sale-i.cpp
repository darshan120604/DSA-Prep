class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int max_factor = 1500;
        int min_price = 1501;
        
        // Count frequency of each factor and find the cheapest item
        vector<int> freq(max_factor + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
            min_price = min(min_price, item[1]);
        }
        
        // Precompute the total copies gained from buying the 1st copy of each factor
        vector<int> gain_for_factor(max_factor + 1, 0);
        for (int f = 1; f <= max_factor; ++f) {
            if (freq[f] > 0) {
                for (int multiple = f; multiple <= max_factor; multiple += f) {
                    gain_for_factor[f] += freq[multiple];
                }
            }
        }
        
        // 0/1 Knapsack for choosing which distinct items to buy at least once
        vector<int> dp(budget + 1, -1);
        dp[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            int f = items[i][0];
            int price = items[i][1];
            int val = gain_for_factor[f];
            
            for (int c = budget; c >= price; --c) {
                if (dp[c - price] != -1) {
                    dp[c] = max(dp[c], dp[c - price] + val);
                }
            }
        }
        
        // Spend any leftover budget on the cheapest available item
        int max_items = 0;
        for (int c = 0; c <= budget; ++c) {
            if (dp[c] != -1) {
                int extra_copies = (budget - c) / min_price;
                max_items = max(max_items, dp[c] + extra_copies);
            }
        }
        
        return max_items;
    }
};
