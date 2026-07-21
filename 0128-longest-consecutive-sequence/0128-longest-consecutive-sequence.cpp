class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int ans=0;
        for(int m:s)
        {
            if(s.find(m-1)==s.end())
            {
                int l=1;
                int x=m+1;
                while(s.find(x)!=s.end())
                {
                  l++;
                  x++;
                }
                ans=max(ans,l);
            }
        }
        return ans;
    }
};