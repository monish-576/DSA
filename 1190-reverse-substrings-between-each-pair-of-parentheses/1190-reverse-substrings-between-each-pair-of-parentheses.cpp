class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='(') ans+=s[i];
            else
            {
                st.push(s[i]);
                int j=i+1;
                string res="";
                while(!st.empty())
                {
                    while(j<s.size()&&s[j]!=')')
                    {
                        st.push(s[j]);
                        j++;
                    }
                    j++;
                    while(!st.empty()&&st.top()!='(')
                    {
                        res+=st.top();
                        st.pop();
                    }
                    st.pop();
                    if(!st.empty())
                    {
                        int k=0;
                        while(k<res.size())
                        {
                            st.push(res[k]);
                            k++;
                        }
                        res="";
                    }

                }
                ans+=res;
                i=j-1;
            }
        }
        return ans;
    }
};