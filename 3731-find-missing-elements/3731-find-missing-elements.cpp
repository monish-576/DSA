class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>res;
        set<int>st;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        int s=*min_element(nums.begin(),nums.end());
        int e=*max_element(nums.begin(),nums.end());
        while(s<e)
        {
            if(st.find(s)==st.end())
            res.push_back(s);
            s++;
        }
        return res;
    }
};