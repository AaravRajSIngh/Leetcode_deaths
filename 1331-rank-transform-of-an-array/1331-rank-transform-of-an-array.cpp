class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ass=arr;
        sort(arr.begin(),arr.end());

        unordered_map<int,int>mp;
        int c=1;
        for(auto x:arr)
        {   
            if(!mp.count(x))
            mp[x]=c++;
        }

        for(auto &g:ass)
        {
            g=mp[g];
        }
        return ass;
    }
};