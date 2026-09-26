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
class Solution {
public:
    void inorder(vector<int>&res,TreeNode* temp)
    {
        if(temp==NULL) return;
        inorder(res,temp->left);
        res.push_back(temp->val);
        inorder(res,temp->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>a,b;
        inorder(a,root1);
        inorder(b,root2);
        vector<int>c;
        int i=0,j=0;
        while(i<a.size()&&j<b.size())
        {
            if(a[i]<=b[j])
            {
                c.push_back(a[i]);
                i++;
            }
            else
            {
                c.push_back(b[j]);
                j++;
            }
        }
        while(i<a.size())
        {
            c.push_back(a[i]);
            i++;
        }
        while(j<b.size())
        {
            c.push_back(b[j]);
            j++;
        }
        return c;
    }
};