class Solution {
public:
    string shortestPalindrome(string s) {
        string o=s;
        string str=s;
        reverse(s.begin(),s.end());
        str+='#';
        str+=s;
        int n=str.size();
        vector<int>lps(n,0);
        int len=0,i=1;
        while(i<n)
        {
            if(str[i]==str[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0) len=lps[len-1];
                else i++;
            }
        }
        string ans=o.substr(0,lps[n-1]);
        string p=o.substr(lps[n-1],n-lps[n-1]);
        ans+=p;
        reverse(p.begin(),p.end());
        p+=ans;
        return p;
    }
};