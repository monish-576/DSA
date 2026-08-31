class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=needle.length();
        vector<int>lps(m,0);
        int len=0,i=1;
        while(i<m)
        {
            if(needle[i]==needle[len])
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
        int n=haystack.length();
        i=0;
        int j=0;
        while(i<n)
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            if(j==m)
            {
                return i-m;
            }
            else if(haystack[i]!=needle[j])
            {
                if(j!=0) j=lps[j-1];
                else i++;
            }
        }
        return -1;
    }
};