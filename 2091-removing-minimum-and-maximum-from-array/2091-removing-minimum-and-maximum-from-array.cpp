class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0, maxIdx = 0;

        // Find indices of minimum and maximum
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        // Put smaller index first
        int l = min(minIdx, maxIdx);
        int r = max(minIdx, maxIdx);

        // 1. Both from front
        int front = r + 1;

        // 2. Both from back
        int back = n - l;

        // 3. One from each side
        int both = (l + 1) + (n - r);

        return min({front, back, both});
    }
};