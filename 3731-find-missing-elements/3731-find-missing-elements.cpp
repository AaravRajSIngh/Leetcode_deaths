class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> un(nums.begin(),nums.end());
        int maxe=*max_element(nums.begin(),nums.end());
        int mine=*min_element(nums.begin(),nums.end());
        for(int i=mine+1;i<maxe;i++)
        {
            if(!un.contains(i))
            {
                ans.push_back(i);
            }
        }
        return ans;

    }
};