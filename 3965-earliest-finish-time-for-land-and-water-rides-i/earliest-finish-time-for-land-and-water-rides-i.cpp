class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            for(int j=0;j<waterStartTime.size();j++){
                int landed = landStartTime[i]+landDuration[i];
                int startwater = max(landed,waterStartTime[j]);
                int endtimeA = startwater + waterDuration[j];

                int waterend = waterStartTime[j]+waterDuration[j];
                int startland = max(waterend,landStartTime[i]);
                int endtimeB = startland+landDuration[i];

                ans = min({ans,endtimeA,endtimeB});
            }
        }
        return ans;
    }
};