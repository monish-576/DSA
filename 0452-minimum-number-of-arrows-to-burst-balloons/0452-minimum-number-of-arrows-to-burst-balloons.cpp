class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=0;
        sort(points.begin(),points.end());
        int n=points.size(),i=1;
        int mini=points[0][0],maxi=points[0][1];
        while(i<n)
        {
            if(mini<=points[i][0]&&points[i][0]<=maxi)
            {
                mini=max(points[i][0],mini);
                maxi=min(points[i][1],maxi);
            }
            else
            {
                ans++;
                mini=points[i][0];
                maxi=points[i][1];
            }
            i++;
        }
        ans++;
        return ans;
    }
};