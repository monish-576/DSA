class Solution {
public:
    vector<int> partitionLabels(string s) {
        int arr[26]={0};
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'a']=i;
        }
        int last=0,maxi=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++)
        {
            maxi=max(maxi,arr[s[i]-'a']);
            if(i==maxi)
            {
                    ans.push_back(i-last+1);
                    last=i+1;
            }
        }
        return ans;
    }
};