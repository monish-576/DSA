class Solution {
public:
    int help(vector<int>&prefix)
    {
           int n=prefix.size();
           vector<int>nse(n),pse(n);
           stack<int>st1,st2;
           for(int i=0;i<n;i++)
           {
               while(!st1.empty()&&prefix[st1.top()]>=prefix[i])
               {
                    st1.pop();
               }
               if(st1.empty())
               pse[i]=-1;
               else
               pse[i]=st1.top();
               st1.push(i);
           }
           for(int i=n-1;i>=0;i--)
           {
               while(!st2.empty()&&prefix[st2.top()]>=prefix[i])
               {
                    st2.pop();
               }
               if(st2.empty())
               nse[i]=n;
               else
               nse[i]=st2.top();
               st2.push(i);
           }
           int ans=0;
           for(int i=0;i<n;i++)
           {
               cout<<nse[i];
               ans=max(ans,(nse[i]-pse[i]-1)*prefix[i]);
           }
           cout<<endl;
           return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>prefix(m,vector<int>(n,0));
        for(int j=0;j<n;j++)
        {
            int sum=0;
            for(int i=0;i<m;i++)
            {
              sum+=(int)(matrix[i][j]-'0');
              if(matrix[i][j]=='0')
              {
                sum=0;
              }
              prefix[i][j]=sum;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
             ans=max(ans,help(prefix[i]));
        }
        return ans;
    }
};