class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        for(int i=0;i<text.size();i++)
        {
            if(text[i]=='b'||text[i]=='a'||text[i]=='l'||text[i]=='o'||text[i]=='n')
            mp[text[i]]++;
        }
        int ans=INT_MAX;
        for(auto &x:mp)
        {
            if(x.first=='l'||x.first=='o')
            ans=min(ans,(x.second)/2);
            else
            ans=min(ans,x.second);
        }
        if(mp['a']==0||mp['b']==0||mp['l']==0||mp['o']==0||mp['n']==0)
        return 0;
        return ans;
    }
};