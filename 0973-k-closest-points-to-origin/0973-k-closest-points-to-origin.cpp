class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        multiset<pair<double,pair<int,int>>>s;
        for(int i=0;i<points.size();i++)
        {
              double ans=sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
              s.insert({ans,{points[i][0],points[i][1]}});
        }
        int i=0;
        vector<vector<int>>ans;
        for(auto x:s)
        {
            if(i==k) break;
            ans.push_back({x.second.first,x.second.second});
            i++;
        }
        return ans;
    }
};