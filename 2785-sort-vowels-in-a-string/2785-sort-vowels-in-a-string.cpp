class Solution {
public:
    string sortVowels(string s) {
        string a="",b="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            b+=s[i];
            else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            a+=s[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int k=0,j=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            {
                if(k<a.size())
                {
                    s[i]=a[k];
                    k++;
                }
                else
                {
                    s[i]=b[j];
                    j++;
                }
            } 
        }
        return s;
    }
};