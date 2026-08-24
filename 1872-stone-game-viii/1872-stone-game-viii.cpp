#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int stoneGameVIII(std::vector<int>& stones) {
        int n = stones.size();
        
        // Compute prefix sums in-place
        std::vector<long long> prefix(n, 0);
        prefix[0] = stones[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        // Base case: at the last position n-1, the player takes all remaining stones
        long long max_diff = prefix[n - 1];

        // Process backwards from n - 2 down to 1
        // (Player must take at least 2 stones, so index must be >= 1)
        for (int i = n - 2; i >= 1; --i) {
            max_diff = std::max(max_diff, prefix[i] - max_diff);
        }

        return max_diff;
    }
};