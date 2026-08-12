class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0;i<k;i++)
        {
           sum+=cardPoints[i];
        }
        int ans=sum;
        cout<<sum<<endl;
        int n=cardPoints.size()-1,j=k-1;
        while(j>=0)
        {
            sum-=cardPoints[j];
            sum+=cardPoints[n];
            cout<<sum;
            ans=max(sum,ans);
            j--;
            n--;
        }
        return ans;
    }
};