class Solution {
public:

    void help6(vector<int>& nums, vector<int>& pge)
    {
        int n = nums.size();
        stack<int> st;

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && nums[st.top()] <= nums[i])
            {
                st.pop();
            }

            if(st.empty())
                pge[i] = -1;
            else
                pge[i] = st.top();

            st.push(i);
        }
    }


    void help5(vector<int>& nums, vector<int>& nge)
    {
        int n = nums.size();
        stack<int> st;

        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && nums[st.top()] < nums[i])
            {
                st.pop();
            }

            if(st.empty())
                nge[i] = n;
            else
                nge[i] = st.top();

            st.push(i);
        }
    }


    long long help1(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> nge(n), pge(n);

        help5(nums, nge);
        help6(nums, pge);

        long long tot = 0;

        for(int i = 0; i < n; i++)
        {
            long long left = i - pge[i];
            long long right = nge[i] - i;

            tot += left * right * (long long)nums[i];
        }

        return tot;
    }


    void help4(vector<int>& nums, vector<int>& pse)
    {
        int n = nums.size();
        stack<int> st;

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && nums[st.top()] > nums[i])
            {
                st.pop();
            }

            if(st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }
    }


    void help3(vector<int>& nums, vector<int>& nse)
    {
        int n = nums.size();
        stack<int> st;

        for(int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }

            if(st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }
    }


    long long help2(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> nse(n), pse(n);

        help3(nums, nse);
        help4(nums, pse);

        long long tot = 0;

        for(int i = 0; i < n; i++)
        {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            tot += left * right * (long long)nums[i];
        }

        return tot;
    }


    long long subArrayRanges(vector<int>& nums)
    {
        return help1(nums) - help2(nums);
    }
};