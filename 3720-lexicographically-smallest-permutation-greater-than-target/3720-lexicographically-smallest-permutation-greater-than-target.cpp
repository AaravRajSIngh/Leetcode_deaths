class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        // Try to make the answer greater at position i.
        // We go from right to left so that the first
        // difference from target occurs as late as possible.
        for (int i = n - 1; i >= 0; i--) {

            // Characters used by target[0...i-1]
            vector<int> cnt = freq;
            bool possible = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (cnt[x] == 0) {
                    possible = false;
                    break;
                }

                cnt[x]--;
            }

            if (!possible)
                continue;

            int cur = target[i] - 'a';

            // Find the smallest character > target[i]
            int bigger = -1;

            for (int c = cur + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    bigger = c;
                    break;
                }
            }

            if (bigger == -1)
                continue;

            string ans = target.substr(0, i);

            // Make the first difference here
            ans += char('a' + bigger);
            cnt[bigger]--;

            // Remaining characters in sorted order
            for (int c = 0; c < 26; c++) {
                ans += string(cnt[c], char('a' + c));
            }

            return ans;
        }

        return "";
    }
};