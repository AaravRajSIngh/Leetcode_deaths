class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto x:nums)
        {
            q.push(x);
              if (q.size() > 2)
                q.pop();
        }   //nlog n insertion

        int a=q.top();
        q.pop();
        int b=q.top();


        return (a-1)*(b-1);

    }
};