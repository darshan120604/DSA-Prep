class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> a;
        int mindiff = INT_MAX;

        for(int i=1;i<arr.size();i++){
            mindiff = min(abs(arr[i]-arr[i-1]), mindiff);
        }

        for(int i=1;i<arr.size();i++){
            if((abs(arr[i]-arr[i-1])) == mindiff){
                a.push_back(arr[i-1]);
                a.push_back(arr[i]);
                ans.push_back(a);
                a.pop_back();
                a.pop_back();
            }
        }

        return ans;
    }
};