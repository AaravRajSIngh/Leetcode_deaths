class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mp;
        for(auto x:nums)
        {
            mp[x]++;
        }

        for(auto g:mp)
        {
            if(g.second < 2)
            {
                return g.first;
            }
        }
        return -1;


    }
};