class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        
        long long ans = LLONG_MAX;

        int n = landStartTime.size();
        int m = waterStartTime.size();

        // Land -> Water
        for (int i = 0; i < n; i++) {
            long long landFinish = landStartTime[i] + landDuration[i];

            for (int j = 0; j < m; j++) {
                long long waterBegin = max(landFinish,
                                           (long long)waterStartTime[j]);

                long long totalFinish =
                    waterBegin + waterDuration[j];

                ans = min(ans, totalFinish);
            }
        }

        // Water -> Land
        for (int i = 0; i < m; i++) {
            long long waterFinish = waterStartTime[i] + waterDuration[i];

            for (int j = 0; j < n; j++) {
                long long landBegin = max(waterFinish,
                                          (long long)landStartTime[j]);

                long long totalFinish =
                    landBegin + landDuration[j];

                ans = min(ans, totalFinish);
            }
        }

        return (int)ans;
    }
};