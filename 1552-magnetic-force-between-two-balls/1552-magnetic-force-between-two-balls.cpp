class Solution {
public:
    bool solve(int dist,vector<int>&position,int m)
    {
        int c=1;
        int prev=position[0];
        for(int i=1;i<position.size();i++)
        {
            if(position[i]-prev>=dist)
            {
                c++;
                prev=position[i];
            }
        }
        return c>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        int maxi=*max_element(position.begin(),position.end());
        int mini=*min_element(position.begin(),position.end());
        int i=0,j=maxi-mini;
        int ans=0;
        sort(position.begin(),position.end());
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(solve(mid,position,m))
            {
                ans=mid;
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
        }
        return ans;
    }
};