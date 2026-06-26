class Solution {
public:
    struct BIT {
        int n;
        vector<int> bit;

        BIT(int n) : n(n), bit(n + 1, 0) {}

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        BIT ft(2 * n + 5);

        int pref = n + 2;   // shifted prefix sum
        ft.update(pref, 1);

        long long ans = 0;

        for (int x : nums) {
            pref += (x == target ? 1 : -1);
            ans += ft.query(pref - 1);
            ft.update(pref, 1);
        }

        return ans;
    }
};