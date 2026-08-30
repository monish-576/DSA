class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int large=*max_element(nums.begin(),nums.end());
        int small=*min_element(nums.begin(),nums.end());
        int l,s;
        for(int i=0;i<n;i++)
        {
           if(nums[i]==large) l=i;
           if(nums[i]==small) s=i;
        }
        // if(l<n/2&&s<n/2) return max(l,s)+1;
        // else if(l>n/2&&s>n/2) return n-min(l,s);
        // else if(l==n/2||s==n/2) return min( max(l,s)+1,n-min(l,s));
        // else if(l<s) return (l+1+(n-s));
        // else return (s+1+(n-l));
        return min({max(l,s)+1,n-min(l,s),min( max(l,s)+1,n-min(l,s)),(l+1+(n-s)),(s+1+(n-l))});
    }
};