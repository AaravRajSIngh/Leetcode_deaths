class Solution {
public:
    long long solve(vector<int>& Astart, vector<int>& Adur,
                    vector<int>& Bstart, vector<int>& Bdur) {

        int m = Bstart.size();

        vector<pair<long long,long long>> b;
        for(int i=0;i<m;i++)
            b.push_back({Bstart[i], Bdur[i]});

        sort(b.begin(), b.end());

        vector<long long> starts(m);

        for(int i=0;i<m;i++)
            starts[i] = b[i].first;

        vector<long long> prefDur(m);
        prefDur[0] = b[0].second;

        for(int i=1;i<m;i++)
            prefDur[i] = min(prefDur[i-1], b[i].second);

        vector<long long> suffFinish(m);

        suffFinish[m-1] = b[m-1].first + b[m-1].second;

        for(int i=m-2;i>=0;i--)
            suffFinish[i] = min(
                suffFinish[i+1],
                b[i].first + b[i].second
            );

        long long ans = LLONG_MAX;

        for(int i=0;i<(int)Astart.size();i++) {

            long long finishA = 1LL * Astart[i] + Adur[i];

            int pos = upper_bound(
                starts.begin(),
                starts.end(),
                finishA
            ) - starts.begin();

            if(pos > 0)
                ans = min(ans,
                          finishA + prefDur[pos-1]);

            if(pos < m)
                ans = min(ans,
                          suffFinish[pos]);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans = LLONG_MAX;

        ans = min(ans,
                  solve(landStartTime, landDuration,
                        waterStartTime, waterDuration));

        ans = min(ans,
                  solve(waterStartTime, waterDuration,
                        landStartTime, landDuration));

        return (int)ans;
    }
};