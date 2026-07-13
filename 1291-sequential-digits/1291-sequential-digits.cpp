class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        vector<int> ans;
        string n= "123456789";
        for(int i=2;i<=9;++i)
        {
            for(int j=0;j+i<=9;j++)
            {
                int newn=stoi(n.substr(j,i));
                if (newn>high) return ans;
                else if (newn>=low) ans.push_back(newn);
            }
        }
        return ans;
    }
};