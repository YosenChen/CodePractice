/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right)
    {
        if (left==NULL && right==NULL) return true;
        else if (left && right)
        {
            return (left->val == right->val)
                && isSymmetric(left->left, right->right)
                && isSymmetric(left->right, right->left);
        }
        else return false; // only one of them is NULL
    }
    // L.B.T.C. OK
};

/*
Submission Details
192 / 192 test cases passed.
Status: Accepted
Runtime: 4 ms
Submitted: 0 minutes ago

Your runtime beats 10.80% of cpp submissions.
*/