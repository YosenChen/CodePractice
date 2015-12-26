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
    vector<int> inorderTraversal(TreeNode *root) {
        //"in order" means: left, self, right
        traversal(root);
        return ret;
    }
    void traversal(TreeNode *node)
    {
        if (!node) return;
        if (node->left) traversal(node->left);
        ret.push_back(node->val);
        if (node->right) traversal(node->right);
    }
    vector<int> ret;
};
//Status: Accepted
//67 / 67 test cases passed., Runtime: 44 ms