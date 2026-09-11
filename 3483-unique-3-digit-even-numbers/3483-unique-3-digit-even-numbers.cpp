class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int,int>mp;
        for(int i=0;i<digits.size();i++)
        {
            int sum=digits[i]*100;
            for(int j=0;j<digits.size();j++)
            {
                 if(j==i) continue;
                 sum+=digits[j]*10;
                 for(int k=0;k<digits.size();k++)
                 {
                    if(k==i||k==j) continue;
                    sum+=digits[k];
                    if(sum%2==0&&sum>99&&sum<=999)
                    mp[sum]++;
                    sum-=digits[k];
                 }
                 sum-=digits[j]*10;
            }
        }
        int ans=0;
        for(auto x:mp)
        {
            ans++;
        }
        return ans;
    }
};