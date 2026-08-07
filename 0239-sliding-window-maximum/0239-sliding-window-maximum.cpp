class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>ans;
        int j=0;
        while(j<nums.size())
        {
            while(!q.empty()&&q.front()<=j-k)
            {
                q.pop_front();
            }
            while(!q.empty()&&nums[q.back()]<nums[j])
            {
                q.pop_back();
            }
            q.push_back(j);
            if(j>=k-1)
            {
                ans.push_back(nums[q.front()]);
            }
            j++;
        }
        return ans;
    }
};