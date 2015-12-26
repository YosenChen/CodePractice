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
    vector<int> preorderTraversal(TreeNode *root) {
        traversal(root);
        return ret;
    }
    void traversal(TreeNode *node)
    {
        if (!node) return;
        ret.push_back(node->val);
        traversal(node->left);
        traversal(node->right);
    }
    
    vector<int> ret;
    
};
//Status: Accepted