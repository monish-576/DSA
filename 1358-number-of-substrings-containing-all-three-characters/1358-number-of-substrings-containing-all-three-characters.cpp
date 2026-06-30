class Solution {
public:
    int numberOfSubstrings(string s) {
        int arr[3]={-1,-1,-1};
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-97]=i;
            if(arr[0]!=-1&&arr[1]!=-1&&arr[2]!=-1)
            ans+=((min({arr[0],arr[1],arr[2]}))+1);
        }
        return ans;
    }
};