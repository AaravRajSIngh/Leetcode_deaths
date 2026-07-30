class Solution {
public:
    int minimumPushes(string word) {

        int n=word.size();
        int ans=0;
        if(n<=8) 
            return n;
        else if(n>8 and n<=16)
            return 8+((n-8)*2);
        else if(n>16 and n<=24)
            return 8+16+((n-16)*3);
        else
            return 8 + 16 + 24 + (n - 24) * 4;   
        
        
    }
};