class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>dum(nums);
        for(int i=0;i<nums.size();i++)
        {
            dum.push_back(nums[i]);
        }
        vector<int>res(dum.size());
        stack<int>st;
        for(int i=dum.size()-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()<=dum[i])
            {
                st.pop();
            }
            if(st.empty())
            res[i]=-1;
            else
            res[i]=st.top();
            st.push(dum[i]);
        }
        while(res.size()>nums.size())
        {
            res.pop_back();
        }
        return res;
    }
};