class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mp(26,0);
        for(int i=0;i<tasks.size();i++)
        {
            mp[tasks[i]-'A']++;
        }
        sort(mp.begin(),mp.end());
        int maxFeq=mp[25];
        int gadde=maxFeq-1;
        int slots=gadde*n;
        for(int i=24;i>=0;i--)
        {
            slots-=min(mp[i],gadde);
        }
        if(slots>0) return tasks.size()+slots;
        return tasks.size();
    }
};