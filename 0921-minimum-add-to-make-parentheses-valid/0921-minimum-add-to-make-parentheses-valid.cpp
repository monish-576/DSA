class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size()==0) return 0;
        int c=0;
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push('(');
            else
            {
                if(!st.empty()) st.pop();
                else c++;
            }
        }
        c+=st.size();
        return c;
    }
};