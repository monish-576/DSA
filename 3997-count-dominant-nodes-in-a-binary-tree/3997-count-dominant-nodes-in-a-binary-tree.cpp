class Solution {
public:
    int help(TreeNode* root, int &cnt) {
        if (!root)
            return INT_MIN;

        int left = help(root->left, cnt);
        int right = help(root->right, cnt);

        int mx = max({root->val, left, right});

        if (root->val == mx)
            cnt++;

        return mx;
    }

    int countDominantNodes(TreeNode* root) {
        int cnt = 0;
        help(root, cnt);
        return cnt;
    }
};