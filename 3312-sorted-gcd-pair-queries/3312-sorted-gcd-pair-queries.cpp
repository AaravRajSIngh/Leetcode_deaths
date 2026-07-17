class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        vector<long long> cntG(mx + 1, 0);

        // cntG[g] = number of pairs having gcd exactly g
        for (int g = mx; g >= 1; g--) {
            long long cnt = 0;
            for (int x = g; x <= mx; x += g)
                cnt += freq[x];

            cntG[g] = cnt * (cnt - 1) / 2;

            for (int x = 2 * g; x <= mx; x += g)
                cntG[g] -= cntG[x];
        }

        // Prefix sums
        vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + cntG[i];

        vector<int> ans;
        for (long long q : queries) {
            ans.push_back(
                upper_bound(pref.begin(), pref.end(), q) - pref.begin()
            );
        }

        return ans;
    }
};