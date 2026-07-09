class Solution {
public:
    void help1(vector<int>&heights,vector<int>&nse)
    {
        int n=heights.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
          while(!st.empty()&&heights[i]<=heights[st.top()])
          {
               st.pop();
          }
          if(st.empty())
          nse[i]=n;
          else
          nse[i]=st.top();
          st.push(i);
        }
    }
     void help2(vector<int>&heights,vector<int>&pse)
    {
        int n=heights.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
          while(!st.empty()&&heights[i]<=heights[st.top()])
          {
               st.pop();
          }
          if(st.empty())
          pse[i]=-1;
          else
          pse[i]=st.top();
          st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>pse(n),nse(n);
        help1(heights,nse);
        help2(heights,pse);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,(nse[i]-pse[i]-1)*heights[i]);
        }
        return ans;
    }
};