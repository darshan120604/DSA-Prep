class Solution {
public:
    bool isSpecial(vector<vector<int>>& mat, int i,int j){
        int n = mat.size();
        int m = mat[0].size();
        for(int k=0; k<n; k++){
            if(k != i && mat[k][j] == 1){
                return false;
            }
        }
        for(int k =0; k<m; k++){
            if(k != j && mat[i][k] == 1){
                return false;
            }
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int count=0;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 1 && isSpecial(mat, i, j)){
                    count++;
                }
            }
        }

        return count;
    }
};