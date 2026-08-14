/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int>res;
    int i;
    void help(TreeNode *root)
    {
        if(root==NULL) return;
        help(root->left);
        res.push_back(root->val);
        help(root->right);
    }
    BSTIterator(TreeNode* root) {
        i=0;
        help(root);
    }
    
    int next() {
        int x=res[i];
        i++;
        return x;
    }
    
    bool hasNext() {
        return i<res.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */