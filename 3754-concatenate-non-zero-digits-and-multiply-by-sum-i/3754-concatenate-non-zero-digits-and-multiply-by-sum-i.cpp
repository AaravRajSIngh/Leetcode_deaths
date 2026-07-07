class Solution {
public:
    long long sumAndMultiply(int n) {
        string nx=to_string(n);
        if(n==0)return n;
        string res="";
        for(auto x:nx)
        {
            if(x!='0')
            res+= x;
        }
        long long sum=0;
        for(auto g:res)
        {
            sum+=g -'0';
        }

        long long numx=stoll(res);
        return numx*sum;
    }
};