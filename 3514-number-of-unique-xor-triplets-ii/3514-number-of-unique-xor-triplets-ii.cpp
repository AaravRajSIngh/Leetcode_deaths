class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> pairXor(MAXX, false);
        vector<bool> ans(MAXX, false);

        int n = nums.size();

        for (int i = n - 1; i >= 0; i--) {
            // Add all pairs (i, k)
            for (int k = i; k < n; k++) {
                pairXor[nums[i] ^ nums[k]] = true;
            }

            // Form triplets (i, j, k)
            for (int x = 0; x < MAXX; x++) {
                if (pairXor[x])
                    ans[nums[i] ^ x] = true;
            }
        }

        int cnt = 0;
        for (bool x : ans)
            if (x) cnt++;

        return cnt;
    }
};