class Solution {
public:
    void help1(vector<int>&arr,vector<int>&pse)
    {
        int n=arr.size();
        stack<int>s;
        for(int i=0;i<n;i++)
        {
           while(!s.empty()&&arr[s.top()]>arr[i])
           {
              s.pop();
           }
           if(s.empty())
           pse[i]=-1;
           else
           pse[i]=s.top();
           s.push(i);
        }
    }
    void help2(vector<int>&arr,vector<int>&nse)
    {
        int n=arr.size();
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {
           while(!s.empty()&&arr[s.top()]>=arr[i])
           {
              s.pop();
           }
           if(s.empty())
           nse[i]=n;
           else
           nse[i]=s.top();
           s.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9+7;
        vector<int>pse(n),nse(n);
        help1(arr,pse);
        help2(arr,nse);
        long long tot=0;
        for(int i=0;i<n;i++)
        {
            long long left=i-pse[i];
            long long right=nse[i]-i;
            tot=(tot+(left*right*arr[i])%mod)%mod;
        }
        return (int)tot;
    }
};