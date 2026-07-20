class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();       // Number of rows
        int m = grid[0].size();    // Number of columns
        int total = n * m;
        
        // Mod k by total size to eliminate redundant full rotations
        k = k % total; 
        
        // Create the answer grid with the same dimensions
        vector<vector<int>> ans(n, vector<int>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Find the flattened 1D index and calculate the shifted index
                int old_flat_idx = i * m + j;
                int new_flat_idx = (old_flat_idx + k) % total;
                
                // Convert back to 2D coordinates
                int new_row = new_flat_idx / m;
                int new_col = new_flat_idx % m;
                
                ans[new_row][new_col] = grid[i][j];
            }
        }
        
        return ans;
    }
};
