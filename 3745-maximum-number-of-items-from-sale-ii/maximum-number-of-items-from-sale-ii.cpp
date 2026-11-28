#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int max_factor = 0;
        long long min_price = LLONG_MAX;
        
        for (const auto& item : items) {
            max_factor = max(max_factor, item[0]);
            min_price = min(min_price, (long long)item[1]);
        }
        
        // Step 1: Count frequency of each factor
        vector<int> cnt(max_factor + 1, 0);
        for (const auto& item : items) {
            cnt[item[0]]++;
        }
        
        // Step 2: Calculate total items divisible by each factor
        vector<int> multiples(max_factor + 1, 0);
        for (int f = 1; f <= max_factor; ++f) {
            if (cnt[f] == 0) continue;
            for (int m = f; m <= max_factor; m += f) {
                multiples[f] += cnt[m];
            }
        }
        
        // Step 3: Sort items by price ascending
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        long long total_items = 0;
        long long rem_budget = budget;
        
        // Greedily buy bonus copies that cost less than 2 * min_price
        for (const auto& item : items) {
            int f = item[0];
            long long price = item[1];
            
            if (price >= 2 * min_price) break;
            
            long long gain = multiples[f] - 1;
            if (gain <= 0) continue;
            
            long long can_buy = min(gain, rem_budget / price);
            total_items += 2 * can_buy;
            rem_budget -= can_buy * price;
            
            if (rem_budget < price) break;
        }
        
        // Step 4: Use remaining budget on single copies of the cheapest item
        total_items += rem_budget / min_price;
        
        return (int)total_items;
    }
};
