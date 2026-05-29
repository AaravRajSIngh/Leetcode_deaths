class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto g:s)
        {
            if(g =='{' or g == '[' or g =='(')
            {
                st.push(g);


            }
            else
            {
                if(st.empty())
                    return false;

                if(g ==']' and  st.top()=='[' )
                {
                    //st pop
                    st.pop();
                }

                else if( g =='}' and  st.top()=='{')
                {
                    st.pop();
                }
                else if( g ==')' and  st.top()=='(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return st.empty()?1:0;
            }
};