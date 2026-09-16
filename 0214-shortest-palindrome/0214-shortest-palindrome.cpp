class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string str = s + '#' + rev;

        int n = str.size();
        vector<int> lps(n, 0);

        int len = 0, i = 1;

        while (i < n) {
            if (str[i] == str[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0)
                    len = lps[len - 1];
                else
                    i++;
            }
        }

        int palLen = lps[n - 1];

        string add = s.substr(palLen);
        reverse(add.begin(), add.end());

        return add + s;
    }
};