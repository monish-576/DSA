class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int n = fruits.size();
        int ans = 0;
        int i = 0, j = 0;

        while (j < n) {
            // Add current fruit
            mp[fruits[j]]++;

            // Shrink window if more than 2 types
            while (mp.size() > 2) {
                mp[fruits[i]]--;

                if (mp[fruits[i]] == 0) {
                    mp.erase(fruits[i]);
                }

                i++;
            }

            // Update answer for every valid window
            ans = max(ans, j - i + 1);

            j++;
        }

        return ans;
    }
};