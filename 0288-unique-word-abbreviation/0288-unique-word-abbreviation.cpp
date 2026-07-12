class ValidWordAbbr {
    unordered_map<string, string> mp;

    string getAbbr(const string &s) {
        if (s.size() <= 2) return s;
        return string(1, s.front()) + to_string(s.size() - 2) + s.back();
    }

public:
    ValidWordAbbr(vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());

        for (const string &word : st) {
            string abbr = getAbbr(word);

            if (!mp.count(abbr))
                mp[abbr] = word;
            else if (mp[abbr] != word)
                mp[abbr] = "";
        }
    }

    bool isUnique(string word) {
        string abbr = getAbbr(word);

        if (!mp.count(abbr))
            return true;

        return mp[abbr] == word;
    }
};