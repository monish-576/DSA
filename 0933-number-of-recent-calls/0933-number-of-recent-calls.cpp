class RecentCounter {
public:
    vector<long long>ans;
    RecentCounter() {
    }
    
    int ping(int t) {
        ans.push_back(t);
        if(t<3000)
        return ans.size();
        else
        {
            int x=t-3000;
            int i;
            for(i=0;i<ans.size();i++)
            {
                if(ans[i]>=x)
                break;
            }
            return ans.size()-i;
        }
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */