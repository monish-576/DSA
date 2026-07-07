class Solution {
public:
    bool help(string &s1, string &s2)
    {
        int n1 = s1.size(), n2 = s2.size();

        if(n1 != n2 + 1)
            return false;

        int i = 0, j = 0;

        while(i < n1)
        {
            if(j < n2 && s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }

        return j == n2;
    }

    static bool comp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words)
    {
        int n = words.size(), maxi = 1;

        sort(words.begin(), words.end(), comp);

        vector<int> dp(n, 1);

        for(int i = 1; i < n; i++)
        {
            for(int prev = 0; prev < i; prev++)
            {
                if(help(words[i], words[prev]) &&
                   dp[prev] + 1 > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};