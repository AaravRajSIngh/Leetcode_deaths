class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mn = 1e18, mx = -1;

        for (int x : nums) {
            mn = min(mn, (long long)x);
            mx = max(mx, (long long)x);
        }

        return (mx - mn) * 1LL * k;
    }
};