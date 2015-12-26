/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        traversal(root);
        return ret;
    }
    void traversal(TreeNode *node)
    {
        if (!node) return;
        traversal(node->left);
        traversal(node->right);
        ret.push_back(node->val);
    }
    vector<int> ret;
};

//Status: Accepted