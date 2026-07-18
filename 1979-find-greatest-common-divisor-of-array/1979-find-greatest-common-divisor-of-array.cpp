class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mi=*min_element(nums.begin(),nums.end());
        int ma=*max_element(nums.begin(),nums.end());

        return __gcd(mi,ma);
    }
};