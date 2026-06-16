class Solution {
public:
    string processStr(string s) {
       string res="";
       for(auto x:s)
       {
        if('a'<= x and x <= 'z')
        {
            res+=x;
        }
        else if(x=='*')
        {
            if(res.size()>0)
            {
                res.pop_back();
            }
        }
        else if(x=='#')
        {
            res+=res;
        }
        else if(x=='%')
        {
            reverse(res.begin(),res.end());
        }
       }
       return res; 
    }
};