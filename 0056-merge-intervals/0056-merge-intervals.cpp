class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[0] < b[0]; // Sort based on the first element
    });
        int st = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i< intervals.size(); i++){
            int next = intervals[i][0];
            if(next<= end){
                end = max(end,intervals[i][1]);
                continue; 
            } else{
                ans.push_back({st,end});
                end = intervals[i][1];
                st = next;
            }
        }

        ans.push_back({st,end});
        return ans;
    }
};