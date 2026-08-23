class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int lsum = 0, rsum = 0;
        int lq = 0, rq = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                lq++;
            else
                lsum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rq++;
            else
                rsum += num[i] - '0';
        }

        // Odd number of '?' => Alice always wins
        if ((lq + rq) % 2) return true;

        // Bob wins only if equality can be forced
        return (lsum - rsum) != ((rq - lq) / 2) * 9;
    }
};