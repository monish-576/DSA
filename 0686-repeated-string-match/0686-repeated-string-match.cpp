class Solution {
public:
    bool kmp(string s,string b)
    {
        int n=s.size(),m=b.size();
        vector<int>lps(m,0);
        int len=0,i=1;
        while(i<m)
        {
            if(b[i]==b[len])
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
        int j=0;
        i=0;
        while(i<n)
        {
            if(s[i]==b[j])
            {
                i++;
                j++;
                if(j==m) return true;
            }
            else
            {
                if(j!=0) j=lps[j-1];
                else i++;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int m=a.size();
        int n=b.size();
        int k=(m+n-1)/m;
        string s="";
        for(int i=0;i<k;i++)
        s+=a;
        if(kmp(s,b)) return k;
        s+=a;
        if(kmp(s,b)) return k+1;
        return -1;
    }
};