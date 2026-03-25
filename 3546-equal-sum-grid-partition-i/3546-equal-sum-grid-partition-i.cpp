class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long total = 0;
        
        // Step 1: Total sum
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }
        
        // Step 2: Must be even
        if (total % 2 != 0) return false;
        
        long long target = total / 2;
        
        // Step 3: Horizontal cut
        long long sum = 0;
        for (int i = 0; i < m - 1; i++) {  // ensure non-empty bottom
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if (sum == target) return true;
        }
        
        // Step 4: Vertical cut
        sum = 0;
        for (int j = 0; j < n - 1; j++) {  // ensure non-empty right
            for (int i = 0; i < m; i++) {
                sum += grid[i][j];
            }
            if (sum == target) return true;
        }
        
        return false;
    }
};