class Solution {
public:
    bool checkDivisibility(int n) {
        
        int temp=n;
        int sum=0; int mult=1;
        while(temp>0)
        {
            int d=temp%10;
            sum+=d;
            mult*=d;
            temp/=10;
        }

        if(n%(sum+mult)==0)
        return true;

        return false;


    }
};