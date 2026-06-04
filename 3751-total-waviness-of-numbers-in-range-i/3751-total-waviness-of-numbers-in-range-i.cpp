class Solution {
public:
    int waviness(int num) {
        string s = to_string(num);
        int cnt = 0;

        for (int i = 1; i < (int)s.size() - 1; i++) {
            if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
                (s[i] < s[i - 1] && s[i] < s[i + 1])) {
                cnt++;
            }
        }

        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        auto pelarindus = make_pair(num1, num2);

        int ans = 0;
        for (int num = num1; num <= num2; num++) {
            ans += waviness(num);
        }

        return ans;
    }
};