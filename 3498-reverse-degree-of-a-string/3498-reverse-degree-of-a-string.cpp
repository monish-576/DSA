class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        // unordered_map<char,int>mp;
        // int i=26;
        // for(int j=97;j<123;j++)
        // {
        //     mp[(char)j]=i;
        //     i--;
        // }
        for(int j=0;j<s.size();j++)
        {
            ans+=(j+1)*(123-(int)s[j]);
        }
        return ans;
    }
};