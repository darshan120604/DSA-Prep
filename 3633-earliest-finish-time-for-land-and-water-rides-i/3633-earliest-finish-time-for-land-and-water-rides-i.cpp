class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minTime = INT_MAX;
        int l = landDuration.size();
        int w = waterDuration.size();
        int currSum;
        for(int i = 0; i<l; i++){
            currSum = landStartTime[i] + landDuration[i];
            for(int j = 0; j<w; j++){
                if(waterStartTime[j] >= currSum){
                    int diff = waterStartTime[j] - currSum;
                    int dur = (diff + waterDuration[j]);
                    minTime = min(minTime,currSum+dur);
                } else{
                    int s = currSum + waterDuration[j];
                    minTime = min(minTime, s);
                }
            }

        }

        for(int i = 0; i<w; i++){
            currSum = waterStartTime[i] + waterDuration[i];
            for(int j = 0; j<l; j++){
                if(landStartTime[j] >= currSum){
                    int diff = landStartTime[j] - currSum;
                    
                    int dur = (diff + landDuration[j]);
                    minTime = min(minTime,currSum+dur);
                }else{
                    int s = currSum + landDuration[j];
                    minTime = min(minTime, s);
                }
                
            }
        }

        return minTime;
    }
};