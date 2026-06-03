class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        long long minLandFinish = LLONG_MAX;
        long long minWaterFinish = LLONG_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            minLandFinish = min(minLandFinish, (long long)landStartTime[i] + landDuration[i]);
        }

        for (int i = 0; i < waterStartTime.size(); i++) {
            minWaterFinish = min(minWaterFinish, (long long)waterStartTime[i] + waterDuration[i]);
        }

        long long ans = LLONG_MAX;

        for (int j = 0; j < waterStartTime.size(); j++) {
            ans = min(ans, max(minLandFinish, (long long)waterStartTime[j]) + waterDuration[j]);
        }

        for (int i = 0; i < landStartTime.size(); i++) {
            ans = min(ans, max(minWaterFinish, (long long)landStartTime[i]) + landDuration[i]);
        }

        return (int)ans;
    }
};
