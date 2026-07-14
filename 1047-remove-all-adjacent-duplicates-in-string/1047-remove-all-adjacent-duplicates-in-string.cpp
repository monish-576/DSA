class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        st.push(s[0]);
        int i=1;
        while(i<s.size())
        {
            if((!st.empty()&&st.top()!=s[i])||st.empty())
            {
               st.push(s[i]);
            }
            else
            {
                while(!st.empty()&&st.top()==s[i])
                {
                    st.pop();
                }
            }
            i++;
        }
        string ans="";
        while(!st.empty())
        {
           ans+=st.top();
           st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};