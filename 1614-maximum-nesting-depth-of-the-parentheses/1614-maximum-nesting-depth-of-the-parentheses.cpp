class Solution {
public:
    int maxDepth(string s) {
       int c=0;
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') c++;
            else if(s[i]==')') c--;
            ans=max(ans,c);
        }
        return ans;
    }
};