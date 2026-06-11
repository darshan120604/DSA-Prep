class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int s = 0, e = (n * m - 1);
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int r = mid / m;
            int c = mid % m;
            if (r < n && mat[r][c] == target)
                return true;
            if (r < n && mat[r][c] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return false;
    }
};