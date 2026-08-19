class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Mark reserved seats using bits
        for (auto &v : reservedSeats) {
            int row = v[0];
            int seat = v[1];

            mp[row] |= (1 << (seat - 1));
        }

        int ans = 0;

        // Masks:
        // seats 2,3,4,5
        int left = 0b00000011110;

        // seats 4,5,6,7
        int middle = 0b0001111000;

        // seats 6,7,8,9
        int right = 0b0111100000;

        for (auto &[row, mask] : mp) {

            bool canLeft = (mask & left) == 0;
            bool canMiddle = (mask & middle) == 0;
            bool canRight = (mask & right) == 0;

            if (canLeft && canRight) {
                // Two families: left + right
                ans += 2;
            }
            else if (canLeft || canMiddle || canRight) {
                // At least one family
                ans += 1;
            }
        }

        // Rows with no reservations can always fit 2 families
        ans += (n - mp.size()) * 2;

        return ans;
    }
};