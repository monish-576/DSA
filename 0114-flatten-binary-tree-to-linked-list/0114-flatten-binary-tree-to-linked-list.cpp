/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void help(TreeNode* root, deque<int>& dq) {
        if (root == NULL)
            return;
        dq.push_back(root->val);
        help(root->left, dq);
        help(root->right, dq);
    }
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        deque<int> dq;
        help(root, dq);
        dq.pop_front();
        if (!dq.empty()) {
            int x = dq.front();
            TreeNode* h = new TreeNode(x);
            dq.pop_front();
            TreeNode* temp = h;
            while (!dq.empty()) {
                int y = dq.front();
                TreeNode* node = new TreeNode(y);
                temp->right = node;
                temp = node;
                dq.pop_front();
            }
            root->right=h;
            root->left=NULL;
        }
    }
};