class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
  
        int r;
        int i;
        if (target < mat[0][0]) return false; 
        for(i = 0; i< n; i++){
            if(mat[i][0] > target){
                r = i-1;
                break;
            }
        }
        if(i == n) r = i-1;
        int st = 0, end = m-1;
        int mid;
        while(st<=end){
            mid = st + (end - st)/2;

            if(mat[r][mid] == target){
                return true;
            } 
            if(mat[r][mid] < target){
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }

        return false;
        
    }
};