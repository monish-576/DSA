class Solution {
public:
    void ps(vector<int>&arr,vector<int>&pse)
    {
        stack<pair<int,int>>s;
        for(int i=0;i<arr.size();i++)
        {
            while(!s.empty()&&s.top().first>arr[i])
            {
                s.pop();
            }
            if(s.empty()) pse[i]=-1;
            else pse[i]=s.top().second;
            s.push({arr[i],i});
        }
    }
     void ns(vector<int>&arr,vector<int>&nse)
    {
        stack<pair<int,int>>s;
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!s.empty()&&s.top().first>=arr[i])
            {
                s.pop();
            }
            if(s.empty()) nse[i]=arr.size();
            else nse[i]=s.top().second;
            s.push({arr[i],i});
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        const long long mod=1e9+7;
        int n=arr.size();
        vector<int>nse(n),pse(n);
        long long sum=0;
        ps(arr,pse);
        ns(arr,nse);
        for(int i=0;i<arr.size();i++)
        {
            long long start=i-pse[i];
            long long end=nse[i]-i;
            long long curr = (end*(start*arr[i])%mod)%mod;
            sum=(sum+curr)%mod;
        }
        return (int)sum;
    }
};