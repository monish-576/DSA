class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0;
        int n=intervals.size();
        vector<vector<int>>res;
        sort(intervals.begin(),intervals.end());
        while(i<n)
        {
             int start=intervals[i][0];
             int end=intervals[i][1];
             i++;
             while(i<n&&end>=intervals[i][0])
             {
                start=min(start,intervals[i][0]);
                end=max(end,intervals[i][1]);
                i++;
             }
             res.push_back({start,end});
        }
        return res;
    }
};